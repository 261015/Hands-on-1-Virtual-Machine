%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *s);
int yylex();
%}

%token NUMBER

%%

input:
    expr '\n'
;

expr:
    expr '+' term
    | term
;

term:
    NUMBER
;

%%

void yyerror(const char *s) {
    printf("Syntax Error\n");
}

int main() {
    printf("Enter expression:\n");
    yyparse();
    return 0;
}
