%option yylineno
%pointer

%{
    #include <stdlib.h>
    #include <string.h>
    #include "parser.hpp"

    void yyerror(const char *);

    int line_num = 1;
%}

/** WRITE ME:
 *  Put any definitions you need here. Add your own regular expressions
 *  below for ALL tokens defined in the manual. You can choose not to use
 *  definitions here.
 */

/** The example below is very simple, but it shows almost everything you will
 *  need to do for this first part. The syntax is as follows:
 *
 *  regular_expression      {  c code  }
 *
 * The lexer will try to match each regular expression. When it does it will
 * execute the corresponding C code.
*/

%%
[ \t\n]          ;

procedure        { return PROCEDURE; }
var           { return VAR; }
return            { return RETURN; }

integer            { return INTERGER; }

"("                   { return '('; }
")"                   { return ')'; }
"{"                   { return '{'; }
"}"                   { return '}'; }
";"                   { return ';'; }
":"                   { return ':'; }
","                   { return ','; }
"="                   { return '='; }
"+"                   { return '+'; }

[0-9]+\.[0-9]+ { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+         { yylval.ival = atoi(yytext); return INT; }
[a-zA-Z0-9]+   {
  yylval.sval = strdup(yytext);
  return STRING;
}
.              ;
%%

/** You shall not pass!
 *  You should not  have to do or edit anything past this.
 */

int yywrap(void) {
    return 1;
}
