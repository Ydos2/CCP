#include <assert.h>
#include <ctype.h>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*** Enums and Print Functions for Terminals and Non-Terminals
 * **********************/

#define MAX_SYMBOL_NAME_SIZE 25

// all of the terminals in the language
typedef enum {
  T_eof = 0,   // 0: end of file
  T_num,       // 1: numbers
  T_plus,      // 2: +
  T_minus,     // 3: -
  T_times,     // 4: *
  T_period,    // 5: .
  T_bar,       // 6: |
  T_openparen, // 7: (
  T_closeparen // 8: )
} token_type;

// this function returns a string for the token.  It is used in the parsetree_t
// class to actually dump the parsetree to a dot file (which can then be turned
// into a picture).  Note that the return char* is a reference to a local copy
// and it needs to be duplicated if you are a going require multiple instances
// simultaniously
char *token_to_string(token_type c) {
  static char buffer[MAX_SYMBOL_NAME_SIZE];
  switch (c) {
  case T_eof:
    strncpy(buffer, "eof", MAX_SYMBOL_NAME_SIZE);
    break;
  case T_num:
    strncpy(buffer, "num", MAX_SYMBOL_NAME_SIZE);
    break;
  case T_plus:
    strncpy(buffer, "+", MAX_SYMBOL_NAME_SIZE);
    break;
  case T_minus:
    strncpy(buffer, "-", MAX_SYMBOL_NAME_SIZE);
    break;
  case T_times:
    strncpy(buffer, "*", MAX_SYMBOL_NAME_SIZE);
    break;
  case T_period:
    strncpy(buffer, ".", MAX_SYMBOL_NAME_SIZE);
    break;
  case T_bar:
    strncpy(buffer, "|", MAX_SYMBOL_NAME_SIZE);
    break;
  case T_openparen:
    strncpy(buffer, "(", MAX_SYMBOL_NAME_SIZE);
    break;
  case T_closeparen:
    strncpy(buffer, ")", MAX_SYMBOL_NAME_SIZE);
    break;
  default:
    strncpy(buffer, "unknown_token", MAX_SYMBOL_NAME_SIZE);
    break;
  }
  return buffer;
}

// all of the non-terminals in the grammar (you need to add these in
// according to your grammar.. these are used for printing the thing out)
// please follow the convention we set up so that we can tell what the heck you
// are doing when we grade
typedef enum {
  epsilon = 100,
  NT_List,
  NT_Expr,
  NT_Term,
  NT_Fact
  // WRITEME: add symbolic names for you non-terminals here
} nonterm_type;

// this function returns a string for the non-terminals.  It is used in the
// parsetree_t class to actually dump the parsetree to a dot file (which can
// then be turned into a picture).  Note that the return char* is a reference to
// a local copy and it needs to be duplicated if you are a going require
// multiple instances simultaniously.
char *nonterm_to_string(nonterm_type nt) {
  static char buffer[MAX_SYMBOL_NAME_SIZE];
  switch (nt) {
  case epsilon:
    strncpy(buffer, "e", MAX_SYMBOL_NAME_SIZE);
    break;
  case NT_List:
    strncpy(buffer, "List", MAX_SYMBOL_NAME_SIZE);
    break;
  // WRITEME: add the other nonterminals you need herE
  case NT_Expr:
    strncpy(buffer, "Expr", MAX_SYMBOL_NAME_SIZE);
    break;
  case NT_Term:
    strncpy(buffer, "Term", MAX_SYMBOL_NAME_SIZE);
    break;
  case NT_Fact:
    strncpy(buffer, "Fact", MAX_SYMBOL_NAME_SIZE);
    break;
  default:
    strncpy(buffer, "unknown_nonterm", MAX_SYMBOL_NAME_SIZE);
    break;
  }
  return buffer;
}

/*** Scanner Class ***********************************************/

class scanner_t {
public:
  // eats the next token and prints an error if it is not of type c
  void eat_token(token_type c);

  // peeks at the lookahead token
  token_type next_token();
  void tokenizeString();
  void scanNumber(string num);
  string getToken();

  // return line number for errors
  int get_line();

  // constructor - inits g_next_token
  scanner_t();

private:
  // WRITEME: Figure out what you will need to write the scanner
  // and to implement the above interface.  It does not have to
  // be a state machine or anything fancy.  Just read in the
  // characters one at a time (using getchar would be a good way)
  // and group them into tokens.  All of the tokens in this calculator
  // are trivial except for the numbers, so it should not be that bad
  //(10 lines or so)

  // This is a bogus member for implementing a useful stub, it should
  // be cut out once you get the scanner up and going.
  token_type bogo_token;

  // error message and exit if weird character
  void scan_error(char x);
  void parser_error(char x);
  // error message and exit for mismatch
  void mismatch_error(token_type c);

  vector<string> strTokens;
  vector<token_type> tokens;

  // 1 ou 0 JSP
  int lineNbr = 1;
  int tokenNbr = 0;
  int tokenNbrStr = 0;
};

token_type scanner_t::next_token() {
  // WRITEME: replace this bogus junk with code that will take a peek
  // at the next token and return it to the parser.  It should _not_
  // actually consume a token - you should be able to call next_token()
  // multiple times without actually reading any more tokens in

  if (strTokens.size() == 0 || tokens.size() == 0)
    return T_eof;

  return tokens.at(tokenNbr);
}

string scanner_t::getToken() {
  return (strTokens.at(tokenNbrStr - 1).c_str());
}

void scanner_t::eat_token(token_type c) {
  // if we are supposed to eat token c, and it does not match
  // what we are supposed to be reading from file, then it is a
  // mismatch error ( call - mismatch_error(c) )

  // WRITEME: cut this bogus stuff out and implement eat_token
  if (strTokens.at(tokenNbrStr) == "\n") {
    tokenNbrStr++;
    lineNbr++;
  }

  if (c != tokens.at(tokenNbr))
    mismatch_error(c);
  else {
    tokenNbr++;
    tokenNbrStr++;
  }
}

scanner_t::scanner_t() {
  // WRITEME

  char c;
  string token = "";
  bool newList = false;
  bool newCalc = false;

  // You get all character per character and you scan if it's not an error
  // It fill "strTokens" to after change in token
  while ((c = getchar()) != EOF) {
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' ||
        c == '6' || c == '7' || c == '8' || c == '9') {
      token += c;
      newCalc = true;
      newList = false;
      int endOfNumber = 0;
      while (endOfNumber != 1) {
        c = getchar();
        if (!(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
              c == '5' || c == '6' || c == '7' || c == '8' || c == '9')) {
          endOfNumber = 1;
        } else
          token += c;
      }

      strTokens.push_back(token);
      token.clear();
    }

    if (c == '.' || c == '\n') {
      if (c == '\n' && newList == false && newCalc == true)
        parser_error(c);
      if (c == '.')
        newList = true;
      else if (c == '\n')
        newList = false;

      token += c;
      newCalc = false;
      strTokens.push_back(token);
      token.clear();
    } else if (c != ' ' && c != '\t' && c != EOF) {
      if (c == '+' || c == '-' || c == '*' || c == '|' || c == '(' ||
          c == ')') {
        token += c;
        strTokens.push_back(token);
        token.clear();
      } else
        scan_error(c);
    }
  }

  // Add the end of file marker
  strTokens.push_back("EOF");

  // We need to take the string and transform them in a token
  tokenizeString();
}

void scanner_t::tokenizeString() {
  for (int i = 0; i < strTokens.size(); i++) {
    if (strTokens.at(i) == "+")
      tokens.push_back(T_plus);
    else if (strTokens.at(i) == "-")
      tokens.push_back(T_minus);
    else if (strTokens.at(i) == "*")
      tokens.push_back(T_times);
    else if (strTokens.at(i) == "|")
      tokens.push_back(T_bar);
    else if (strTokens.at(i) == ".")
      tokens.push_back(T_period);
    else if (strTokens.at(i) == "(")
      tokens.push_back(T_openparen);
    else if (strTokens.at(i) == ")")
      tokens.push_back(T_closeparen);
    else if (strTokens.at(i) == "EOF")
      tokens.push_back(T_eof);
    else if (strTokens.at(i) != "\n")
      scanNumber(strTokens.at(i));
  }
}

void scanner_t::scanNumber(string num) {
  for (int i = 0; i < num.length(); i++) {
    if (num[i] != '0' && num[i] != '1' && num[i] != '2' && num[i] != '3' &&
        num[i] != '4' && num[i] != '5' && num[i] != '6' && num[i] != '7' &&
        num[i] != '8' && num[i] != '9')
      scan_error(num[i]);
  }
  tokens.push_back(T_num);
}

int scanner_t::get_line() {
  // Return line number for errors -- WRITEME

  return lineNbr;
}

void scanner_t::scan_error(char x) {
  printf("scan error: unrecognized character '%c'\n", x);
  exit(1);
}

void scanner_t::parser_error(char x) {
  printf("syntax error: found '%c' in parsing\n", x);
  exit(2);
}

void scanner_t::mismatch_error(token_type x) {
  printf("syntax error: found %s ", token_to_string(next_token()));
  printf("expecting %s - line %d\n", token_to_string(x), get_line());
  exit(1);
}

/*** ParseTree Class **********************************************/

// just dumps out the tree as a dot file.  The interface is described below
// on the actual methods.  This class is full and complete.  You should not
// have to touch a thing if everything goes according to plan.  While you don't
// have to modify it, you will have to call it from your recursive decent
// parser, so read about the interface below.
class parsetree_t {
public:
  void push(token_type t);
  void push(nonterm_type nt);
  void pop();
  void drawepsilon();
  parsetree_t();

private:
  enum stype_t { TERMINAL = 1, NONTERMINAL = 0, UNDEF = -1 };

  struct stuple {
    nonterm_type nt;
    token_type t;
    stype_t stype;
    int uniq;
  };
  void printedge(stuple temp); // prints edge from TOS->temp
  stack<stuple> stuple_stack;
  char *stuple_to_string(const stuple &s);
  int counter;
};

// the constructer just starts by initializing a counter (used to uniquely
// name all the parse tree nodes) and by printing out the necessary dot commands
parsetree_t::parsetree_t() {
  counter = 0;
  printf("digraph G { page=\"8.5,11\"; size=\"7.5, 10\"\n");
}

// This push function taken a non terminal and keeps it on the parsetree
// stack.  The stack keeps trace of where we are in the parse tree as
// we walk it in a depth first way.  You should call push when you start
// expanding a symbol, and call pop when you are done.  The parsetree_t
// will keep track of everything, and draw the parse tree as you go.
// This particular function should be called if you are pushing a non-terminal
void parsetree_t::push(nonterm_type nt) {
  counter++;
  stuple temp;
  temp.nt = nt;
  temp.stype = NONTERMINAL;
  temp.uniq = counter;
  printedge(temp);
  stuple_stack.push(temp);
}

// same as above, but for terminals
void parsetree_t::push(token_type t) {
  counter++;
  stuple temp;
  temp.t = t;
  temp.stype = TERMINAL;
  temp.uniq = counter;
  printedge(temp);
  stuple_stack.push(temp);
}

// when you are parsing a symbol, pop it.  That way the parsetree_t will
// know that you are now working on a higher part of the tree.
void parsetree_t::pop() {
  if (!stuple_stack.empty()) {
    stuple_stack.pop();
  }

  if (stuple_stack.empty()) {
    printf("}\n");
  }
}

// draw an epsilon on the parse tree hanging off of the top of stack
void parsetree_t::drawepsilon() {
  push(epsilon);
  pop();
}

// this private print function is called from push.  Basically it
// just prints out the command to draw an edge from the top of the stack (TOS)
// to the new symbol that was just pushed.  If it happens to be a terminal
// then it makes it a snazzy blue color so you can see your program on the
// leaves
void parsetree_t::printedge(stuple temp) {
  if (temp.stype == TERMINAL) {
    printf("\t\"%s%d\" [label=\"%s\",style=filled,fillcolor=powderblue]\n",
           stuple_to_string(temp), temp.uniq, stuple_to_string(temp));
  } else {
    printf("\t\"%s%d\" [label=\"%s\"]\n", stuple_to_string(temp), temp.uniq,
           stuple_to_string(temp));
  }

  // no edge to print if this is the first node
  if (!stuple_stack.empty()) {
    // print the edge
    printf("\t\"%s%d\" ", stuple_to_string(stuple_stack.top()),
           stuple_stack.top().uniq);
    printf("-> \"%s%d\"\n", stuple_to_string(temp), temp.uniq);
  }
}

// just a private utility for helping with the printing of the dot stuff
char *parsetree_t::stuple_to_string(const stuple &s) {
  static char buffer[MAX_SYMBOL_NAME_SIZE];
  if (s.stype == TERMINAL) {
    snprintf(buffer, MAX_SYMBOL_NAME_SIZE, "%s", token_to_string(s.t));
  } else if (s.stype == NONTERMINAL) {
    snprintf(buffer, MAX_SYMBOL_NAME_SIZE, "%s", nonterm_to_string(s.nt));
  } else {
    assert(0);
  }

  return buffer;
}

/*** Parser Class ***********************************************/

// the parser_t class handles everything.  It has and instance of scanner_t
// so it can peek at tokens and eat them up.  It also has access to the
// parsetree_t class so it can print out the parse tree as it figures it out.
// To make the recursive decent parser work, you will have to add some
// methods to this class.  The helper functions are described below

// all phase during the calculation
typedef enum {
  P_new,  // 0: end of file
  P_num,  // 1: numbers
  P_op,   // 2: operator
  P_calc, // 3: calc
} phase_type;

class parser_t {
private:
  scanner_t scanner;
  parsetree_t parsetree;
  void eat_token(token_type t);
  void syntax_error(nonterm_type);

  void List(phase_type phase);
  void ListNew();
  void ListCalc();
  void ListOperator();
  void ListNumber();

  void OpResult();
  int CalcFactory(int a, int b, string op);
  // WRITEME: fill this out with the rest of the
  // recursive decent stuff (more methods)

  token_type lastToken = T_bar;
  int isOpenParen = 0;
  int isOpenBar = 0;

  vector<string> actionList;
public:
  void parse();
};

// this function not only eats the token (moving the scanner forward one
// token), it also makes sure that token is drawn in the parse tree
// properly by calling push and pop.
void parser_t::eat_token(token_type t) {
  parsetree.push(t);
  scanner.eat_token(t);
  parsetree.pop();
}

// call this syntax error wehn you are trying to parse the
// non-terminal nt, but you fail to find a token that you need
// to make progress.  You should call this as soon as you can know
// there is a syntax_error.
void parser_t::syntax_error(nonterm_type nt) {
  printf("syntax error: found %s in parsing %s - line %d\n",
         token_to_string(scanner.next_token()), nonterm_to_string(nt),
         scanner.get_line());
  exit(2);
}

// One the recursive decent parser is set up, you simply call parse()
// to parse the entire input, all of which can be dirived from the start
// symbol
void parser_t::parse() {
  parsetree.push(NT_List);
  List(P_new);
  parsetree.pop();
}

// WRITEME: the List() function is not quite right.  Right now
// it is made to parse the grammar:  List -> '+' List | EOF
// which is not a very interesting language.  It has been included
// so you can see the basics of how to structure your recursive
// decent code.

// Here is an example
void parser_t::List(phase_type phase) {
  // push this non-terminal onto the parse tree.
  // the parsetree class is just for drawing the finished
  // parse tree, and should in should have no effect the actual
  // parsing of the data

  switch (phase) {
  case P_new:
    parsetree.push(NT_Expr);
    ListNew();
    parsetree.pop();
    break;
  case P_num:
    ListNumber();
    break;
  case P_op:
    ListOperator();
    break;
  case P_calc:
    ListCalc();
    break;
  default:
    break;
  }

  // now that we are done with List, we can pop it from the data
  // stucture that is tracking it for drawing the parse tree
}

void parser_t::ListNew() {
  switch (scanner.next_token()) {
  case T_num:
    // number
    eat_token(T_num);
    lastToken = T_num;
    actionList.push_back(scanner.getToken());
    List(P_op);
    break;
  case T_minus:
    // - But it's negative value not minus something
    eat_token(T_minus);
    lastToken = T_minus;
    actionList.push_back(scanner.getToken());
    // Take info
    List(P_num);
    break;
  case T_openparen:
    // (
    eat_token(T_openparen);
    lastToken = T_openparen;
    isOpenParen++;
    List(P_calc);
    break;
  case T_eof:
    // last
    if (lastToken == T_bar)
      syntax_error(NT_List);
    parsetree.drawepsilon();
    break;
  case T_period:
    // .
    // Bar check
    if (isOpenParen % 2 != 0)
      syntax_error(NT_List);
    isOpenParen = 0;
    if (isOpenBar % 2 != 0)
      syntax_error(NT_List);
    isOpenBar = 0;
    ///////////////////////////////////////////////// FIX ?
    if (lastToken == T_period)
      syntax_error(NT_List);

    eat_token(T_period);
    lastToken = T_period;
    OpResult();
    // parsetree.pop();
    List(P_new);
    break;
  case T_bar:
    // |
    isOpenBar++;
    eat_token(T_bar);
    lastToken = T_bar;
    List(P_calc);
    break;
  default:
    syntax_error(NT_List);
    // parsetree.pop();
    break;
  }
}

void parser_t::ListNumber() {
  switch (scanner.next_token()) {
  case T_num:
    // number
    eat_token(T_num);
    lastToken = T_num;
    actionList.push_back(scanner.getToken());
    List(P_op);
    break;
  case T_minus:
    // - But it's negative value not minus something
    eat_token(T_minus);
    lastToken = T_minus;
    actionList.push_back(scanner.getToken());
    // Take info
    List(P_num);
    break;
  case T_openparen:
    // (
    eat_token(T_openparen);
    lastToken = T_openparen;
    isOpenParen++;
    List(P_calc);
    break;
  case T_closeparen:
    // )
    if (isOpenParen <= 0) {
      syntax_error(NT_List);
      break;
    } else if (lastToken == T_openparen) {
      syntax_error(NT_List);
      break;
    }
    eat_token(T_closeparen);
    // parsetree.drawepsilon();
    lastToken = T_closeparen;
    isOpenParen--;
    List(P_calc);
    break;
  case T_bar:
    // |
    isOpenBar++;
    eat_token(T_bar);
    lastToken = T_bar;
    List(P_calc);
    break;
  default:
    syntax_error(NT_List);
    // parsetree.pop();
    break;
  }
}
void parser_t::ListOperator() {
  switch (scanner.next_token()) {
  case T_plus:
    // +
    eat_token(T_plus);
    lastToken = T_plus;
    actionList.push_back(scanner.getToken());
    List(P_num);
    break;
  case T_minus:
    // -
    eat_token(T_minus);
    lastToken = T_minus;
    actionList.push_back(scanner.getToken());
    List(P_num);
    break;
  case T_times:
    // *
    eat_token(T_times);
    lastToken = T_times;
    actionList.push_back(scanner.getToken());
    List(P_num);
    break;
  case T_period:
    // .
    if (isOpenParen % 2 != 0)
      syntax_error(NT_List);
    isOpenParen = 0;
    if (isOpenBar % 2 != 0)
      syntax_error(NT_List);
    isOpenBar = 0;
    if (lastToken == T_period)
      syntax_error(NT_List);

    eat_token(T_period);
    lastToken = T_period;
    // parsetree.pop();
    OpResult();
    List(P_new);
    break;
  case T_bar:
    // |
    isOpenBar++;
    eat_token(T_bar);
    lastToken = T_bar;
    List(P_calc);
    break;
  case T_closeparen:
    // )
    if (isOpenParen <= 0) {
      syntax_error(NT_List);
      break;
    } else if (lastToken == T_openparen) {
      syntax_error(NT_List);
      break;
    }
    eat_token(T_closeparen);
    // parsetree.drawepsilon();
    lastToken = T_closeparen;
    isOpenParen--;
    List(P_calc);
    break;
  case T_eof:
    // last
    parsetree.drawepsilon();
    // parsetree.pop();
    break;
  default:
    syntax_error(NT_List);
    // parsetree.pop();
    break;
  }
}

void parser_t::ListCalc() {
  switch (scanner.next_token()) {
  case T_num:
    // number
    eat_token(T_num);
    lastToken = T_num;
    actionList.push_back(scanner.getToken());
    List(P_op);
    break;
  case T_plus:
    // +
    eat_token(T_plus);
    lastToken = T_plus;
    actionList.push_back(scanner.getToken());
    List(P_num);
    break;
  case T_minus:
    // -
    eat_token(T_minus);
    lastToken = T_minus;
    actionList.push_back(scanner.getToken());
    List(P_num);
    break;
  case T_times:
    // *
    eat_token(T_times);
    lastToken = T_times;
    actionList.push_back(scanner.getToken());
    List(P_num);
    break;
  case T_bar:
    // |
    isOpenBar++;
    eat_token(T_bar);
    lastToken = T_bar;
    List(P_calc);
    break;
  case T_period:
    // .
    if (isOpenParen % 2 != 0)
      syntax_error(NT_List);
    isOpenParen = 0;
    if (isOpenBar % 2 != 0)
      syntax_error(NT_List);
    isOpenBar = 0;
    if (lastToken == T_period)
      syntax_error(NT_List);

    eat_token(T_period);
    lastToken = T_period;
    OpResult();
    // parsetree.pop();
    List(P_new);
    break;
  case T_openparen:
    // (
    eat_token(T_openparen);
    lastToken = T_openparen;
    isOpenParen++;
    List(P_calc);
    break;
  case T_closeparen:
    // )
    if (isOpenParen <= 0) {
      syntax_error(NT_List);
      break;
    } else if (lastToken == T_openparen) {
      syntax_error(NT_List);
      break;
    }
    eat_token(T_closeparen);
    // parsetree.drawepsilon();
    lastToken = T_closeparen;
    isOpenParen--;
    List(P_calc);
    break;
  case T_eof:
    // last
    parsetree.drawepsilon();
    // parsetree.pop();
    break;
  default:
    syntax_error(NT_List);
    // parsetree.pop();
    break;
  }
}

// Later -> For calculator
void parser_t::OpResult() {
  int result = 0;

  int a = 0;
  int b = 0;
  string opStr = "";

  if (actionList.size() < 3)
    return;
  for (int i = 0; i <= actionList.size(); i++) {
    if (actionList[i] == "+" || actionList[i] == "-" || actionList[i] == "*") {
      opStr = actionList[i];

      b = atoi(actionList[i + 1].c_str());
      result = CalcFactory(a, b, opStr);
      break;
    } else
      a = atoi(actionList[i].c_str());
  }

  std::cerr << result << std::endl;
  actionList.clear();
}

int parser_t::CalcFactory(int a, int b, string opStr) {
  if (opStr == "+") return (a + b);
  else if (opStr == "-") return (a - b);
  else if (opStr == "*") return (a * b);
  else return (a);
}

// WRITEME: you will need to put the rest of the procedures here

/*** Main ***********************************************/

int main() {
  parser_t parser;
  parser.parse();

  return 0;
}
