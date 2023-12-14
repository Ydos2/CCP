#include <cassert>
#include <typeinfo>
#include <cstring>

#include "ast.hpp"
#include "symtab.hpp"
#include "primitive.hpp"


class Codegen : public Visitor
{
  private:
    FILE* m_outputfile;
    SymTab *m_st;

    // Basic size of a word (integers and booleans) in bytes
    static const int wordsize = 4;

    int actu_offset = 0;
    int ret_offset = 0;

    int label_count; // Access with new_label
    int space_taken = 0;

    // Helpers
    // This is used to get new unique labels (cleverly names label1, label2, ...)
    int new_label()
    {
        return label_count++;
    }

    void set_text_mode()
    {
        fprintf(m_outputfile, ".text\n\n");
    }

    void set_data_mode()
    {
        fprintf(m_outputfile, ".data\n\n");
    }

    // PART 1:
    // 1) get arithmetic expressions on integers working:
    //  you wont really be able to run your code,
    //  but you can visually inspect it to see that the correct
    //  chains of opcodes are being generated.
    // 2) get procedure calls working:
    //  if you want to see at least a very simple program compile
    //  and link successfully against gcc-produced code, you
    //  need to get at least this far
    // 3) get boolean operation working
    //  before we can implement any of the conditional control flow
    //  stuff, we need to have booleans worked out.
    // 4) control flow:
    //  we need a way to have if-elses and while loops in our language.
    // 5) arrays: just like variables, but with an index

    // Hint: the symbol table has been augmented to track an offset
    //  with all of the symbols.  That offset can be used to figure
    //  out where in the activation record you should look for a particuar
    //  variable


    ///////////////////////////////////////////////////////////////////////////////
    //
    //  function_prologue
    //  function_epilogue
    //
    //  Together these two functions implement the callee-side of the calling
    //  convention.  A stack frame has the following layout:
    //
    //                         <- SP (before pre-call / after epilogue)
    //  high -----------------
    //       | actual arg 1  |
    //       |    ...        |
    //       | actual arg n  |
    //       -----------------
    //       |  Return Addr  |
    //       =================
    //       | temporary 1   | <- SP (when starting prologue)
    //       |    ...        |
    //       | temporary n   |
    //   low ----------------- <- SP (when done prologue)
    //
    //
    //              ||
    //              ||
    //             \  /
    //              \/
    //
    //
    //  The caller is responsible for placing the actual arguments
    //  and the return address on the stack. Actually, the return address
    //  is put automatically on the stack as part of the x86 call instruction.
    //
    //  On function entry, the callee
    //
    //  (1) allocates space for the callee's temporaries on the stack
    //
    //  (2) saves callee-saved registers (see below) - including the previous activation record pointer (%ebp)
    //
    //  (3) makes the activation record pointer (frmae pointer - %ebp) point to the start of the temporary region
    //
    //  (4) possibly copies the actual arguments into the temporary variables to allow easier access
    //
    //  On function exit, the callee:
    //
    //  (1) pops the callee's activation record (temporay area) off the stack
    //
    //  (2) restores the callee-saved registers, including the activation record of the caller (%ebp)
    //
    //  (3) jumps to the return address (using the x86 "ret" instruction, this automatically pops the
    //      return address off the stack
    //
    //////////////////////////////////////////////////////////////////////////////
    //
    // Since we are interfacing with code produced by GCC, we have to respect the
    // calling convention that GCC demands:
    //
    // Contract between caller and callee on x86:
    //    * after call instruction:
    //           o %eip points at first instruction of function
    //           o %esp+4 points at first argument
    //           o %esp points at return address
    //    * after ret instruction:
    //           o %eip contains return address
    //           o %esp points at arguments pushed by caller
    //           o called function may have trashed arguments
    //           o %eax contains return value (or trash if function is void)
    //           o %ecx, %edx may be trashed
    //           o %ebp, %ebx, %esi, %edi must contain contents from time of call
    //    * Terminology:
    //           o %eax, %ecx, %edx are "caller save" registers
    //           o %ebp, %ebx, %esi, %edi are "callee save" registers
    ////////////////////////////////////////////////////////////////////////////////


    // First, you need to decide how and where to store local variables and the remaining information that you need as part of an activation record.
    // For this, you will probably need to introduce a function prologue that sets up the proper activation record.
    // This function prologue will need to store the activation record pointer of the caller (%ebp) as well as other callee saved registers.
    // Also, it needs to create space for the local variables.
    // Finally, you need to set up the activation record pointer (preferably, %ebp) so that you can access the function's parameters and variables.
    // Note that the return address is already on the top of the stack when your procedure is called (this is done automatically as part of the x86 call instruction).
    void emit_prologue(SymName *name, unsigned int size_locals, unsigned int num_args)
    {
        // On function entry, the callee
        char *func_name = strdup(name->spelling());

        fprintf(m_outputfile, "### PROLOGUE ###\n");

        if (!strcmp(func_name, "Main")) {
            fprintf(m_outputfile, "####### MAIN FUNCTION #######\n");
            fprintf(m_outputfile, ".globl Main\n");
            fprintf(m_outputfile, "Main:\n");
        } else {
            fprintf(m_outputfile, "####### OTHER FUNCTION #######\n");
            fprintf(m_outputfile, "%s:\n", func_name);
        }

        // store the activation record pointer of the caller (%ebp)
        fprintf(m_outputfile, "push %%ebp\n");
        fprintf(m_outputfile, "mov %%esp, %%ebp\n");

        // as well as other callee saved registers
        //fprintf(m_outputfile, "push %%eax\n");
        fprintf(m_outputfile, "push %%ebx\n");
        fprintf(m_outputfile, "push %%esi\n");
        fprintf(m_outputfile, "push %%edi\n");

        int offset = 2 * wordsize;

        while (num_args > 0)
        {
            // it needs to create space for the local variables
            //fprintf(m_outputfile, "push %d(%%ebp)\n", offset);
            offset += wordsize;
            num_args--;
            space_taken += wordsize;
        }

        // A faire changer pour faire de la place
        /*if (size_locals > 0) {
            // decrement of the stack pointers
            fprintf(m_outputfile, "sub $%d, %%esp\n", size_locals);
            space_taken += size_locals;
        }*/
    }

    void emit_epilogue()
    {
        // On function exit, the callee

        fprintf(m_outputfile, "### EPILOGUE ###\n");

        // restores the callee-saved registers, including the activation record of the caller (%ebp)
        //if (space_taken > 0)
        //    fprintf(m_outputfile, "add $%d, %%esp\n", space_taken);

        fprintf(m_outputfile, "pop %%edi\n");
        fprintf(m_outputfile, "pop %%esi\n");
        fprintf(m_outputfile, "pop %%ebx\n");
        fprintf(m_outputfile, "leave\n");
        fprintf(m_outputfile, "ret\n");
    }

    // WRITEME: more functions to emit code
    void emit_set_var(int offset)
    {
        fprintf(m_outputfile, "movl %%eax, -%d(%%ebp)\n", offset);
    }

    void emit_get_var(int offset)
    {
        fprintf(m_outputfile, "movl -%d(%%ebp), %%eax\n", offset);
    }

    void emit_conditional(char* labelName, char* instr, int labelNum)
    {
        fprintf(m_outputfile, "cmp %%ebx, %%eax\n");
        fprintf(m_outputfile, "%s %s%d\n",instr,labelName,labelNum);
        fprintf(m_outputfile, "mov $0, %%eax\n");
        fprintf(m_outputfile, "jmp %sDone%d\n",labelName,labelNum);
        fprintf(m_outputfile, "%s%d:\n",labelName,labelNum);
        fprintf(m_outputfile, "mov $1, %%eax\n");
        fprintf(m_outputfile, "%sDone%d:\n",labelName,labelNum);
    }

  public:

    Codegen(FILE* outputfile, SymTab* st)
    {
        m_outputfile = outputfile;
        m_st = st;
        label_count = 0;
    }

    void visitProgramImpl(ProgramImpl* p)
    {
        set_data_mode();
        set_text_mode();
        p->visit_children(this);
    }

    void visitProcImpl(ProcImpl* p)
    {
        int size_locals = m_st->scopesize(p->m_attribute.m_scope);
        int num_args = p->m_decl_list->size();

        emit_prologue(p->m_symname, size_locals, num_args);

        p->visit_children(this);

        emit_epilogue();
    }

    void visitProcedure_blockImpl(Procedure_blockImpl* p)
    {
        p->visit_children(this);
    }

    void visitNested_blockImpl(Nested_blockImpl* p)
    {
        p->visit_children(this);
    }

    void visitAssignment(Assignment* p)
    {
        fprintf(m_outputfile, "### ASSIGNMENT ###\n");

        m_st->open_scope();
        p->m_lhs->accept(this);


        p->m_expr->accept(this);
        m_st->close_scope();

        emit_set_var((actu_offset + 1) * wordsize);
    }

    void visitCall(Call* p)
    {
        const char* name = p->m_symname->spelling();
        Symbol* s = m_st->lookup(p->m_attribute.m_scope, name);

        fprintf(m_outputfile, "call %s\n", name);

        //emit_set_var(s->get_offset());
    }

    void visitReturn(Return* p)
    {
        //p->m_expr->accept(this);
        emit_set_var(ret_offset);
        p->visit_children(this);

        // If nothing
        //fprintf(m_outputfile, "pop %%eax\n");
        // if something
        //fprintf(m_outputfile, "mov $%d, %%eax\n", p->m_expr->m_attribute.m_place + wordsize);
    }

    // Control flow
    void visitIfNoElse(IfNoElse* p)
    {
        fprintf(m_outputfile, "\n### IF NO ELSE ###\n\n");

        int label = new_label();

        p->m_expr->accept(this);
        
        p->m_nested_block->accept(this);
        
        fprintf(m_outputfile, "JUMP%d:\n", label_count);

        fprintf(m_outputfile, "\n### END IF NO ELSE ###\n\n");
    }

    void visitIfWithElse(IfWithElse* p)
    {
        fprintf(m_outputfile, "\n### IF ELSE ###\n\n");

        int label = new_label();
        p->m_expr->accept(this);

        p->m_nested_block_1->accept(this);


        fprintf(m_outputfile, "jmp JUMP_ELSE%d\n", label);
        
        fprintf(m_outputfile, "JUMP%d:\n", label_count);
        p->m_nested_block_2->accept(this);
        fprintf(m_outputfile, "JUMP_ELSE%d:\n", label);

        fprintf(m_outputfile, "\n### END IF ELSE ###\n\n");
    }

    void visitWhileLoop(WhileLoop* p)
    {
        /*fprintf(m_outputfile, "\n### WHILE ###\n\n");

        int label = new_label();

        fprintf(m_outputfile, "JUMP_WHILE%d:\n", label_count);
        
        p->m_expr->accept(this);

        p->m_nested_block->accept(this);

        fprintf(m_outputfile, "jmp JUMP_WHILE%d\n", label_count);
        fprintf(m_outputfile, "JUMP%d:\n", label_count);
        

        fprintf(m_outputfile, "\n### END WHILE ###\n\n");*/
    }

    void visitCodeBlock(CodeBlock *p) 
    {
        p->m_nested_block->accept(this);
    }

    // Variable declarations (no code generation needed)
    void visitDeclImpl(DeclImpl* p)
    {
        p->visit_children(this);
    }

    void visitTInteger(TInteger* p)
    {
        p->visit_children(this);
    }

    void visitTIntPtr(TIntPtr* p)
    {
        p->visit_children(this);
    }

    void visitTBoolean(TBoolean* p)
    {
        p->visit_children(this);
    }

    void visitTCharacter(TCharacter* p)
    {
        p->visit_children(this);
    }

    void visitTCharPtr(TCharPtr* p)
    {
        p->visit_children(this);
    }

    void visitTString(TString* p)
    {
        p->visit_children(this);
    }
    //////////////////////////////////////////////////////

    // Comparison operations
    void visitCompare(Compare* p)
    {
        fprintf(m_outputfile, "### Compare ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");
        
        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "cmpl %%ebx, %%eax\n");
        fprintf(m_outputfile, "jne JUMP%d\n", label_count);
    }

    void visitNoteq(Noteq* p)
    {
        fprintf(m_outputfile, "### Noteq ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");
        
        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "cmpl %%ebx, %%eax\n");
        fprintf(m_outputfile, "je JUMP%d\n", label_count);
    }

    void visitGt(Gt* p)
    {
        fprintf(m_outputfile, "### Noteq ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");
        
        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "cmpl %%ebx, %%eax\n");
        fprintf(m_outputfile, "jge JUMP%d\n", label_count);
    }

    void visitGteq(Gteq* p)
    {
        fprintf(m_outputfile, "### Noteq ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");
        
        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "cmpl %%ebx, %%eax\n");
        fprintf(m_outputfile, "jg JUMP%d\n", label_count);
    }

    void visitLt(Lt* p)
    {
        fprintf(m_outputfile, "### Noteq ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");
        
        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "cmpl %%ebx, %%eax\n");
        fprintf(m_outputfile, "jle JUMP%d\n", label_count);
    }

    void visitLteq(Lteq* p)
    {
        fprintf(m_outputfile, "### Noteq ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");
        
        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "cmpl %%ebx, %%eax\n");
        fprintf(m_outputfile, "jl JUMP%d\n", label_count);
    }

    // Arithmetic and logic operations
    void visitAnd(And* p)
    {
        fprintf(m_outputfile, "\n### AND ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ecx\n");

        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%edx\n");
        fprintf(m_outputfile, "and %%ecx, %%edx\n");
    }

    void visitOr(Or* p)
    {
        fprintf(m_outputfile, "\n### OR ###\n");

        p->m_expr_1->accept(this);
        
        fprintf(m_outputfile, "movl %%eax, %%ecx\n");

        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%edx\n");
        fprintf(m_outputfile, "or %%ecx, %%edx\n");
    }

    void visitMinus(Minus* p)
    {
        fprintf(m_outputfile, "\n### MINUS ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");

        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "sub %%ebx, %%eax\n");
    }

    void visitPlus(Plus* p)
    {
        fprintf(m_outputfile, "\n### PLUS ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");

        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "add %%ebx, %%eax\n");
    }

    void visitTimes(Times* p)
    {
        fprintf(m_outputfile, "\n### TIMES ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");

        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "imul %%ebx, %%eax\n");
    }

    void visitDiv(Div* p)
    {
        fprintf(m_outputfile, "\n### DIV ###\n");

        p->m_expr_1->accept(this);

        fprintf(m_outputfile, "movl %%eax, %%ebx\n");

        p->m_expr_2->accept(this);

        fprintf(m_outputfile, "div %%ebx, %%eax\n");
    }

    void visitNot(Not* p)
    {
        fprintf(m_outputfile, "\n### NOT ###\n");

        p->m_expr->accept(this);
        fprintf(m_outputfile, "not %%eax\n");
    }

    void visitUminus(Uminus* p)
    {
        fprintf(m_outputfile, "\n### NEG ###\n");

        p->m_expr->accept(this);
        fprintf(m_outputfile, "neg %%eax\n");
    }

    // Variable and constant access
    void visitIdent(Ident* p)
    {
        fprintf(m_outputfile, "### GET ID ###\n");

        p->visit_children(this);

        char *name = strdup(p->m_symname->spelling()); 
        Symbol *symbol = m_st->lookup(p->m_attribute.m_scope, name);

        //m_st->insert(name, symbol);
        ret_offset = (symbol->get_offset() + 1) * wordsize;
        emit_get_var(ret_offset);
    }

    void visitBoolLit(BoolLit* p)
    {
        // SI R
        //fprintf(m_outputfile, "push $%d\n", p->m_primitive->m_data);
        // SINON
        fprintf(m_outputfile, "movl $%d, %%eax\n", p->m_primitive->m_data);
    }

    void visitCharLit(CharLit* p)
    {
        // SI R
        //fprintf(m_outputfile, "push $%d\n", p->m_primitive->m_data);
        // SINON
        fprintf(m_outputfile, "movl $%d, %%eax\n", p->m_primitive->m_data);
    }

    void visitIntLit(IntLit* p)
    {
        // SI R
        //fprintf(m_outputfile, "push $%d\n", p->m_primitive->m_data);
        // SINON
        fprintf(m_outputfile, "movl $%d, %%eax\n", p->m_primitive->m_data);
    }

    void visitNullLit(NullLit* p)
    {
        //fprintf(m_outputfile, "push $0\n");
        fprintf(m_outputfile, "movl $0, %%eax\n");
    }

    void visitArrayAccess(ArrayAccess* p)
    {
        const char* name = p->m_symname->spelling();
        Symbol* s = m_st->lookup(p->m_attribute.m_scope, name);

        p->m_expr->accept(this);
        fprintf(m_outputfile, "movl $%d, %%eax\n", s->get_offset());
    }

    // LHS
    void visitVariable(Variable* p)
    {
        const char* name = p->m_symname->spelling();
        Symbol* s = m_st->lookup(p->m_attribute.m_scope,name);

        actu_offset = s->get_offset();

        //fprintf(m_outputfile, "movl $%d, %%ebx\n", s->get_offset());
    }

    void visitDerefVariable(DerefVariable* p)
    {
    }

    void visitArrayElement(ArrayElement* p)
    {
    }

    // Special cases
    void visitSymName(SymName* p)
    {
    }

    void visitPrimitive(Primitive* p)
    {
    }

    // Strings
    void visitStringAssignment(StringAssignment* p)
    {
    }

    void visitStringPrimitive(StringPrimitive* p)
    {
    }

    void visitAbsoluteValue(AbsoluteValue* p)
    {
    }

    // Pointer
    void visitAddressOf(AddressOf* p)
    {
    }

    void visitDeref(Deref* p)
    {
    }
};


void dopass_codegen(Program_ptr ast, SymTab* st)
{
    Codegen* codegen = new Codegen(stdout, st);
    ast->accept(codegen);
    delete codegen;
}
