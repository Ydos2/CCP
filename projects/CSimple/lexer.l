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
[/][%][^%]*[%]+([^%/][^%]*[%]+)*[/]          { /* For commenting */ };

boolean            { return BOOLEAN; }
char            { return CHAR; }
integer            { return INTEGER; }
string            { return STRING; }
intptr            { return INTPTR; }
charptr            { return CHARPTR; }
if            { return IF; }
else            { return ELSE; }
while            { return WHILE; }
var           { return VAR; }
procedure        { return PROCEDURE; }
return            { return RETURN; }
null            { return _NULL_; }

"&&"                   { return AND; }
"/"                   { return '/'; }
"="                   { return '='; }
"=="                   { return EQUAL; }
">"                   { return '>'; }
">="                   { return EQUALMORE; }
"<"                   { return '<'; }
"<="                   { return EQUALLESS; }
"-"                   { return '-'; }
"!"                   { return '!'; }
"!="                   { return DIFF; }
"||"                   { return OR; }
"+"                   { return '+'; }
"*"                   { return '*'; }
"&"                   { return '&'; }
"^"                   { return '^'; }

";"                   { return ';'; }
":"                   { return ':'; }
","                   { return ','; }
"|"                   { return '|'; }
"{"                   { return '{'; }
"}"                   { return '}'; }
"("                   { return '('; }
")"                   { return ')'; }
"["                   { return '['; }
"]"                   { return ']'; }


"true"|"false"         {
    if (strcmp (yytext,"true")==0)
        yylval.bval = 1;
    else
        yylval.bval = 0;
    return BOOLEAN;
}
[0-9]+         { yylval.ival = atoi(yytext); return INTEGER; }
[0-9]+         { yylval.ival = atoi(yytext); return INTPTR; }
[0-9A-F]         { yylval.ival = atoi(yytext); return INTEGER; }
[0-7]         { yylval.ival = atoi(yytext); return INTEGER; }
[01]         { yylval.ival = atoi(yytext); return INTEGER; }
"'"."'"         { yylval.cval = yytext[1]; return CHAR; }
"'"."'"         { yylval.cval = yytext[1]; return CHARPTR; }
"\"".*"\""				{ char temp[yyleng-1]; strncpy(temp,yytext+1,yyleng-1); temp[yyleng-2]='\0'; yylval.sval = strdup(temp); return STRING; }
[a-zA-Z]([0-9]|[a-zA-Z]|"_")*   { yylval.wval = strdup(yytext); return WORD; }
%%

/** You shall not pass!
 *  You should not  have to do or edit anything past this.
 */

int yywrap(void) {
    return 1;
}
