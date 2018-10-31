 /*
Reagan Young and Riley Maersch
Prog Lang & Trans
10/17/18
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include "SymbolTable.h"
using namespace std;

#define NOT_APPLICABLE      -2
#define UNDEFINED           -1
#define FUNCTION            0
#define INT                 1
#define STR                 2
#define INT_OR_STR          3
#define BOOL                4
#define INT_OR_BOOL         5
#define STR_OR_BOOL         6
#define INT_OR_STR_OR_BOOL  7
#define ARITHMETIC_OP       8
#define LOGICAL_OP          9
#define RELATIONAL_OP       10

stack<SYMBOL_TABLE> scopeStack;
queue<int> lambda;
int numLines = 1;
int numParameters = 0;
bool isLambda = false;
bool isLet = false;

void printRule(const char *, const char *);
int yyerror(const char *s);
void printTokenInfo(const char* tokenType, const char* lexeme);
bool findEntryInAnyScope(const string theName);
void beginScope();
int endScope();

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}
%}

%union
{
  char* text;
  TYPE_INFO typeInfo;
  int num;
};

/*Token declarations*/
%token      T_IDENT T_INTCONST T_UNKNOWN T_STRCONST T_LETSTAR
%token      T_LAMBDA T_INPUT T_PRINT T_IF T_LPAREN T_RPAREN
%token      T_ADD T_MULT T_DIV T_SUB T_AND T_OR T_NOT T_LT T_GT
%token      T_LE T_GE T_EQ T_NE T_T T_NIL

/*Link identifiers with their token*/
%type <text> T_IDENT
%type <num> N_BIN_OP
%type <typeInfo> N_CONST N_EXPR N_PARENTHESIZED_EXPR N_IF_EXPR N_ARITHLOGIC_EXPR N_ID_EXPR_LIST
%type <typeInfo> N_LAMBDA_EXPR N_LET_EXPR N_PRINT_EXPR N_EXPR_LIST N_INPUT_EXPR N_ID_LIST

/*Starting point*/
%start      N_START


/*Translation rules*/
%%
N_START                 :N_EXPR
                            {
                                printRule("START", "EXPR");
                                printf("\n---- Completed parsing ----\n\n");
                                return 0;
                            }
                            ;
N_EXPR                  :N_CONST
                            {
                                printRule("EXPR", "CONST");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | T_IDENT
                            {
                                printRule("EXPR","IDENT");
                                if(!findEntryInAnyScope($1))
                                {
                                  yyerror("Undefined identifier");
                                  return(0);
                                }

                                $$.type = scopeStack.top().getType($1);
                                $$.numParams = scopeStack.top().getNumParams($1);
                                $$.returnType = scopeStack.top().getReturnType($1);
                            }
                        | T_LPAREN N_PARENTHESIZED_EXPR T_RPAREN
                            {
                                printRule("EXPR", "( PARENTHESIZED_EXPR )");
                                $$.type = $2.type;
                                $$.numParams = $2.numParams;
                                $$.returnType = $2.returnType;
                            }
                            ;
N_CONST                 :T_INTCONST
                            {
                                printRule("CONST", "INTCONST");
                                $$.type = INT;
                                $$.numParams = 1;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | T_STRCONST
                            {
                                printRule("CONST", "STRCONST");
                                $$.type = STR;
                                $$.numParams = 1;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | T_T
                            {
                                printRule("CONST", "t");
                                $$.type = BOOL;
                                $$.numParams = 1;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | T_NIL
                            {
                                printRule("CONST", "nil");
                                $$.type = BOOL;
                                $$.numParams = 1;
                                $$.returnType = NOT_APPLICABLE;
                            }
                            ;
N_PARENTHESIZED_EXPR    : N_ARITHLOGIC_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "ARITHLOGIC_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_IF_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "IF_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_LET_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "LET_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_LAMBDA_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "LAMBDA_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_PRINT_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "PRINT_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_INPUT_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "INPUT_EXPR");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                            }
                        | N_EXPR_LIST
                            {
                                if($1.numParams > lambda.front() && (isLambda == true && !lambda.empty()))
                                {
                                    yyerror("Too many parameters in function call");
                                    return(1);
                                }
                                else if($1.numParams < lambda.front() && (isLambda == true && !lambda.empty()))
                                {
                                    yyerror("Too few parameters in function call");
                                    return(1);
                                }
                                printRule("PARENTHESIZED_EXPR", "EXPR_LIST");
                                $$.type = $1.type;
                                $$.numParams = $1.numParams;
                                $$.returnType = $1.returnType;
                                lambda.pop();
                            }
                            ;
N_ARITHLOGIC_EXPR       : N_UN_OP N_EXPR
                            {
                                printRule("ARITHLOGIC_EXPR", "UN_OP EXPR");
                                if($2.type == FUNCTION)
                                {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                }
                                $$.type = BOOL;
                                $$.numParams = NOT_APPLICABLE;
                                $$.returnType = NOT_APPLICABLE;
                            }
                        | N_BIN_OP N_EXPR N_EXPR
                            {
                                printRule("ARITHLOGIC_EXPR", "BIN_OP EXPR EXPR");
                                if($1 == ARITHMETIC_OP)
                                {
                                    if($2.type&$3.type&INT == INT)
                                    {
                                        $$.type = INT;
                                        $$.numParams = $2.numParams + $3.numParams;
                                        $$.returnType = INT;
                                    }
                                    else if($2.type != INT)
                                    {
                                        yyerror("Arg 1 must be integer");
                                        return(1);
                                    }
                                    else if($3.type != INT)
                                    {
                                        yyerror("Arg 2 must be integer");
                                        return(1);
                                    }
                                }
                                else if($1 == RELATIONAL_OP)
                                {
                                    if(($2.type == FUNCTION) || ($2.type != STR && $2.type != INT))
                                    {
                                        yyerror("Arg 1 must be integer or string");
                                        return(1);
                                    }
                                    else if(($3.type == FUNCTION) || ($3.type != STR && $3.type != INT))
                                    {
                                        yyerror("Arg 2 must be integer or string");
                                        return(1);
                                    }
                                    else
                                    {
                                        $$.type = BOOL;
                                        $$.numParams = $2.numParams + $3.numParams;
                                        $$.returnType = BOOL;
                                    }
                                }
                                else if($1 == LOGICAL_OP)
                                {
                                    if($2.type == FUNCTION)
                                    {
                                        yyerror("Arg 1 cannot be function");
                                        return(1);
                                    }
                                    else if($3.type == FUNCTION)
                                    {
                                        yyerror("Arg 2 cannot be function");
                                        return(1);
                                    }
                                    $$.type = BOOL;
                                    $$.numParams = $2.numParams + $3.numParams;
                                    $$.returnType = BOOL;
                                }
                            }
                            ;
N_IF_EXPR               : T_IF N_EXPR N_EXPR N_EXPR
                            {
                                printRule("IF_EXPR", "if EXPR EXPR EXPR");
                                if($4.type == FUNCTION)
                                {
                                    yyerror("Arg 3 cannot be function");
                                    return(1);
                                }
                                else if($3.type == FUNCTION)
                                {
                                    yyerror("Arg 2 cannot be function");
                                    return(1);
                                }
                                else if($2.type == FUNCTION)
                                {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                }
                                
                                if($2.type&$3.type&$4.type == INT)
                                {
                                    $$.type = INT;
                                    $$.numParams = $2.numParams + $3.numParams + $4.numParams;
                                    $$.returnType = INT;
                                }
                            }
                            ;
N_LET_EXPR              : T_LETSTAR T_LPAREN N_ID_EXPR_LIST T_RPAREN N_EXPR
                            {
                                printRule("LET_EXPR", "let* ( ID_EXPR_LIST ) EXPR");
                                endScope();
                                isLambda = false;
                                isLet = true;

                                if($5.type == FUNCTION)
                                {
                                    yyerror("Arg 2 cannot be function");
                                    return(1);
                                }

                                $$.type = $5.type;
                                $$.numParams = numParameters;
                                $$.returnType = $5.returnType;
                            }
                            ;
N_ID_EXPR_LIST          : /* epsilon */
                            {
                                printRule("ID_EXPR_LIST", "epsilon");
                                $$.type = UNDEFINED;
                                $$.numParams = 0;
                                $$.returnType = UNDEFINED;
                            }
                        | N_ID_EXPR_LIST T_LPAREN T_IDENT N_EXPR T_RPAREN
                            {
                                printRule("ID_EXPR_LIST", "ID_EXPR_LIST ( IDENT EXPR )");
                                printf ("___Adding %s to symbol table\n", $3);
                                string lex_entry = string($3);
                                
                                if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(lex_entry, $4.type, $4.numParams, $4.returnType)))
                                {
                                  yyerror("Multiply defined identifier");
                                  return(1);
                                }
                                else
                                {
                                  SYMBOL_TABLE_ENTRY entry = SYMBOL_TABLE_ENTRY(lex_entry, $4.type, $4.numParams, $4.returnType);
                                  scopeStack.top().addEntry(entry);
                                }

                                if(isLet == true)
                                {
                                    $$.type = $4.type;
                                }
                                else
                                {
                                    $$.type = $4.returnType;
                                }
                                $$.numParams = scopeStack.top().getNumParams(string($3));
                                $$.returnType = $4.returnType;
                            }
                            ;
N_LAMBDA_EXPR           : T_LAMBDA T_LPAREN N_ID_LIST T_RPAREN N_EXPR
                            {
                                printRule("LAMBDA_EXPR","lambda ( ID_LIST ) EXPR");
                                numParameters = endScope();
                                isLambda = true;

                                if($5.type == FUNCTION)
                                {
                                    yyerror("Arg 2 cannot be function");
                                    return(1);
                                }

                                if(numParameters > $3.numParams)
                                {
                                    yyerror("Too many parameters in function call");
                                    return(1);
                                }
                                else if(numParameters < $3.numParams)
                                {
                                    yyerror("Too few parameters in function call");
                                    return(1);
                                }
                                $$.type = FUNCTION;
                                $$.numParams = numParameters;
                                $$.returnType = $5.type;
                                lambda.push($3.numParams);
                            }
                            ;
N_ID_LIST               : /* epsilon */
                            {
                                printRule("ID_LIST", "epsilon");
                                $$.type = UNDEFINED;
                                $$.numParams = 0;
                                $$.returnType = UNDEFINED;
                            }
                        | N_ID_LIST T_IDENT
                            {
                                printRule("ID_LIST", "ID_LIST IDENT");
                                printf ("___Adding %s to symbol table\n", $2);
                                string lex_entry = string($2);
                                
                                if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(lex_entry, INT)))
                                {
                                  yyerror("Multiply defined identifier");
                                  return(1);
                                }
                                else
                                {
                                  SYMBOL_TABLE_ENTRY entry = SYMBOL_TABLE_ENTRY(lex_entry, INT);
                                  scopeStack.top().addEntry(entry);
                                }
                                $$.type = INT;
                                $$.numParams = $$.numParams + 1;
                                $$.returnType = INT;
                            }
                            ;
N_PRINT_EXPR            : T_PRINT N_EXPR
                            {
                                printRule("PRINT_EXPR", "print EXPR");
                                if($2.type == FUNCTION)
                                {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                }
                                $$.type = $2.type;
                                $$.numParams = 0;
                                $$.returnType = $2.returnType;
                            }    
                            ;
N_INPUT_EXPR            : T_INPUT
                            {
                                printRule("INPUT_EXPR", "input");
                                $$.type = INT_OR_STR;
                                $$.numParams = 0;
                                $$.returnType = INT_OR_STR;
                            }   
                            ;                    
N_EXPR_LIST             : N_EXPR N_EXPR_LIST
                            {
                                printRule("EXPR_LIST", "EXPR EXPR_LIST");
                                if($1.type == FUNCTION){
                                    $$.type = $1.returnType;
                                }
                                else{
                                    $$.type = $1.type;
                                }
                                $$.type = $1.type;
                                $$.numParams = $2.numParams + 1;
                                $$.returnType = $1.returnType;
                            }
                        | N_EXPR
                            {
                                printRule("EXPR_LIST", "EXPR");
                                if($1.type == FUNCTION){
                                    $$.type = $1.returnType;
                                }
                                else{
                                    $$.type = $1.type;
                                }
                                $$.numParams = 0;
                                $$.returnType = $1.returnType;
                            }
                            ;
N_BIN_OP                : N_ARITH_OP
                            {
                                printRule("BIN_OP", "ARITH_OP");
                                $$ = ARITHMETIC_OP;
                            }
                        | N_LOG_OP
                            {
                                printRule("BIN_OP", "LOG_OP");
                                $$ = LOGICAL_OP;
                            }
                        | N_REL_OP
                            {
                                printRule("BIN_OP", "REL_OP");
                                $$ = RELATIONAL_OP;
                            }
                            ;
N_ARITH_OP              : T_MULT
                            {
                                printRule("ARITH_OP", "*");
                            }
                        | T_SUB
                            {
                                printRule("ARITH_OP", "-");
                            }
                        | T_DIV
                            {
                                printRule("ARITH_OP", "/");
                            }
                        | T_ADD
                            {
                                printRule("ARITH_OP", "+");
                            }
                            ;
N_LOG_OP                : T_AND
                            {
                                printRule("LOG_OP", "and");
                            }
                        | T_OR
                            {
                                printRule("LOG_OP", "or");
                            }
                            ;
N_REL_OP                : T_LT
                            {
                                printRule ("REL_OP", "<");
                            }
                        | T_GT
                            {
                                printRule("REL_OP", ">");
                            }
                        | T_LE
                            {
                                printRule("REL_OP", "<=");
                            }
                        | T_GE
                            {
                                printRule("REL_OP", ">=");
                            }
                        | T_EQ
                            {
                                printRule("REL_OP", "=");
                            }
                        | T_NE
                            {
                                printRule("REL_OP", "/=");
                            }
                            ;
N_UN_OP                 : T_NOT
                            {
                                printRule("UN_OP", "not");
                            }
                            ;
%%

#include "lex.yy.c"
extern FILE *yyin;

void beginScope()
{
  scopeStack.push(SYMBOL_TABLE());
  printf("\n___Entering new scope...\n\n");
}

int endScope()
{
  int size = scopeStack.top().getMap().size();
  scopeStack.pop();
  printf("\n___Exiting scope...\n\n");
  return size;
}

void printRule(const char *lhs, const char *rhs)
{
  printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s)
{
  printf("Line %d: %s\n", numLines, s);
  return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme)
{
  printf("TOKEN: %s LEXEME: %s\n", tokenType, lexeme);
}

bool findEntryInAnyScope(const string theName) 
{
  if (scopeStack.empty( )) 
    return(false);
  
  bool found = scopeStack.top( ).findEntry(theName);
  if (found) {
    return(true);
  }
  else
  {
    SYMBOL_TABLE symbolTable = scopeStack.top( );
    scopeStack.pop( );
    found = findEntryInAnyScope(theName);
    scopeStack.push(symbolTable);
    return(found);
  }
}

int main(int argc, char** argv) 
{
    if (argc < 2) 
    {
        printf("You must specify a file in the command line!\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    do 
    {
        yyparse();
    } while (!feof(yyin));
    return 0;
}                        