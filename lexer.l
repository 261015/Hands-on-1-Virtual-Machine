%{
#include <stdio.h>
%}

DIGIT      [0-9]
LETTER     [a-zA-Z]
ID         {LETTER}({LETTER}|{DIGIT})*

%%

"int"           { printf("KEYWORD: %s\n", yytext); }
"float"         { printf("KEYWORD: %s\n", yytext); }

{ID}            { printf("IDENTIFIER: %s\n", yytext); }

{DIGIT}+        { printf("NUMBER: %s\n", yytext); }

"+"             { printf("PLUS\n"); }
"-"             { printf("MINUS\n"); }
"="             { printf("ASSIGN\n"); }
";"             { printf("SEMICOLON\n"); }

[ \t\n]         ;

.               { printf("UNKNOWN: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}
