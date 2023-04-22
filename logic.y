%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
#include "node.h"
extern int yylex();
extern int yylineno;
void yyerror(char *);

struct node *root = NULL;
int nbr_var = 0;
%}

%union{
    struct node *node;
    char var;
}

%token T_LPAREN T_RPAREN T_NOT T_AND T_OR T_IMPLIES T_EQUIV
%left T_AND T_OR T_IMPLIES T_EQUIV
%left T_NOT

%token<var> T_VARIABLE
%type <node> expression
%type <node> expr

%start expr



%%
expr : expression
      { root = $1; }
      ;
expression : expression T_OR expression
           { $$ = new_node(OR, $1, $3); }
           | expression T_AND expression
           { $$ = new_node(AND, $1, $3); }
           | T_NOT expression
           { $$ = new_node(NOT, $2, NULL); }
           | expression T_IMPLIES expression
           { $$ = new_node(OR, new_node(NOT, $1, NULL), $3); }
           | expression T_EQUIV expression
           { $$ = new_node(AND, new_node(OR, new_node(NOT, $1, NULL), $3),
                             new_node(OR, new_node(NOT, $3, NULL), $1)); }
           | T_LPAREN expression T_RPAREN
           { $$ = $2; }
           | T_VARIABLE
           { 
            nbr_var++;
            $$ = new_leaf($1);
           }
           ;

%%


int main()
{
    yyparse();
    printf("\nFormule : ");
    print_node(root);
    est_satisfiable(root, nbr_var);
    return 0;
}
