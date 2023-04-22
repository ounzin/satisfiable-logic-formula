%{
#include "y.tab.h"

void yyerror(char *s){
            fprintf(stderr, "line %d: %s\n", yylineno, s);
            exit(1); 
    }
%}

%%

"(" { return T_LPAREN; }
")" { return T_RPAREN; }
"!" { return T_NOT; }
"&" { return T_AND; }
"|" { return T_OR; }
"implies" { return T_IMPLIES; }
"equiv" { return T_EQUIV; }
"->" { return T_IMPLIES; }
"<->" { return T_EQUIV; }
[a-z] { yylval.var = yytext[0]; return T_VARIABLE; }
" " { /* ignorer les espaces */ }
. { yyerror("caractère inattendu"); }

%%

int yywrap(void)
{
    return 1;
}
