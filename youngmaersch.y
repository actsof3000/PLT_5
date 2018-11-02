 /*
Reagan Young and Riley Maersch
Prog Lang & Trans
10/17/18
*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <stack>
#include <queue>
#include "SymbolTable.h"
using namespace std;

#define ARITHMETIC_OP       1
#define LOGICAL_OP          2
#define RELATIONAL_OP       3

stack<SYMBOL_TABLE> scopeStack;
stack <char> arith;
stack <string> rel;
stack <string> logic;

TYPE_INFO findEntryInAnyScope(const string theName);
bool isStrCompatible(const int theType);
bool isIntCompatible(const int theType);
bool isIntOrStrCompatible(const int theType);
void printRule(const char *, const char *);
void printTokenInfo(const char* tokenType, const char* lexeme);
void beginScope();
void endScope();
void cleanup();
int yyerror(const char *s);
int numLines = 1;

extern "C" {
    int yyparse(void);
    int yylex(void);
    int yywrap() {return 1;}
}
%}

%union
{
  char* text;
  TYPE_INFO typeinfo;
  int num;
};

/*Token declarations*/
%token      T_IDENT T_UNKNOWN T_STRCONST T_LETSTAR T_INTCONST
%token      T_INPUT T_PRINT T_IF T_LPAREN T_RPAREN T_LAMBDA
%token      T_ADD T_MULT T_DIV T_SUB T_AND T_OR T_NOT T_LT T_GT
%token      T_LE T_GE T_EQ T_NE T_T T_NIL

/*Link identifiers with their token*/
%type <text> T_IDENT T_STRCONST T_INTCONST
%type <typeinfo> N_CONST N_EXPR N_PARENTHESIZED_EXPR N_IF_EXPR N_ARITHLOGIC_EXPR
%type <typeinfo> N_LET_EXPR N_PRINT_EXPR N_EXPR_LIST N_INPUT_EXPR N_BIN_OP N_UN_OP N_LOG_OP

/*Starting point*/
%start      N_START


/*Translation rules*/
%%
N_START                 :N_EXPR
                            {
                                printRule("START", "EXPR");
                                printf("\n---- Completed parsing ----\n\n");
                                if($1.type == INT)
                                {
                                    printf("\nValue of the expression is: %d\n", $1.nval);
                                }
                                else if($1.type == STR)
                                {
                                    printf("\nValue of the expression is: %s\n", $1.sval);
                                }
                                else
                                {
                                    if($1.bval == true)
                                    {
                                        printf("\nValue of the expression is: t\n");
                                    }
                                    else
                                    {
                                        printf("\nValue of the expression is: nil\n");
                                    }
                                }
                                return 0;
                            }
                            ;
N_EXPR                  :N_CONST
                            {
                                printRule("EXPR", "CONST");
                                $$.type = $1.type;
                                $$.sval = $1.sval;                               
                            }
                        | T_IDENT
                            {
                                printRule("EXPR","IDENT");
                                string id = string($1);
                                TYPE_INFO expr = findEntryInAnyScope(id);
                                if(expr.type == UNDEFINED)
                                {
                                  yyerror("Undefined identifier");
                                  return(0);
                                }
                                $$.type = expr.type;
                                $$.nval = expr.nval;
                            }
                        | T_LPAREN N_PARENTHESIZED_EXPR T_RPAREN
                            {
                                printRule("EXPR", "( PARENTHESIZED_EXPR )");
                                $$.type = $2.type;
                                $$.sval = $2.sval;
                                $$.nval = $2.nval;
                                $$.bval = $2.bval;
                            }
                            ;
N_CONST                 :T_INTCONST
                            {
                                printRule("CONST", "INTCONST");
                                $$.type = INT;
                                $$.nval = atoi($1);
                                $$.bval = true;
                            }
                        | T_STRCONST
                            {
                                printRule("CONST", "STRCONST");
                                $$.type = STR;
                                $$.sval = $1;
                                $$.bval = true;
                            }
                        | T_T
                            {
                                printRule("CONST", "t");
                                $$.type = BOOL;
                                $$.bval = true;
                            }
                        | T_NIL
                            {
                                printRule("CONST", "nil");
                                $$.type = BOOL;
                                $$.bval = false;
                            }
                            ;
N_PARENTHESIZED_EXPR    : N_ARITHLOGIC_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "ARITHLOGIC_EXPR");
                                $$.type = $1.type;
                                $$.nval = $1.nval;
                                $$.bval = $1.bval;
                            }
                        | N_IF_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "IF_EXPR");
                                $$.type = $1.type;
                                $$.sval = $1.sval;
                                $$.nval = $1.nval;
                                $$.bval = $1.bval;
                            }
                        | N_LET_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "LET_EXPR");
                                $$.type = $1.type;
                            }
                        | N_PRINT_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "PRINT_EXPR");
                                $$.type = $1.type;
                            }
                        | N_INPUT_EXPR
                            {
                                printRule("PARENTHESIZED_EXPR", "INPUT_EXPR");
                                $$.type = $1.type;
                            }
                        | N_EXPR_LIST
                            {
                                printRule("PARENTHESIZED_EXPR", "EXPR_LIST");
                                $$.type = $1.type;
                            }
                            ;
N_ARITHLOGIC_EXPR       : N_UN_OP N_EXPR
                            {
                                printRule("ARITHLOGIC_EXPR", "UN_OP EXPR");
                                $$.type = BOOL;
                                if($1.unop == NOT)
                                {
                                    $$.bval = !$2.bval;
                                }
                                else
                                {
                                    $$.bval = $2.bval;
                                }
                            }
                        | N_BIN_OP N_EXPR N_EXPR
                            {
                                printRule("ARITHLOGIC_EXPR", "BIN_OP EXPR EXPR");
                                $$.type = BOOL;

                                switch($1.op)
                                {
                                    case(ARITHMETIC_OP):
                                        $$.type = INT;
                                        $$.bval = true;
                                        if(!isIntCompatible($2.type))
                                        {
                                            yyerror("Arg 1 must be integer");
                                            return(1);
                                        }
                                        if(!isIntCompatible($3.type))
                                        {
                                            yyerror("Arg 2 must be integer");
                                            return(1);
                                        }
                                        
                                        if(arith.top() == '+')
                                        {
                                            $$.nval = $2.nval + $3.nval;
                                            arith.pop();
                                        }
                                        else if(arith.top() == '-')
                                        {
                                            $$.nval = $2.nval - $3.nval;
                                            arith.pop();
                                        }
                                        else if(arith.top() == '/')
                                        {
                                            if($3.nval == 0)
                                            {
                                                yyerror("Attempted division by zero");
                                            }
                                            $$.nval = $2.nval / $3.nval;
                                            arith.pop();
                                        }
                                         else if(arith.top() == '*')
                                        {
                                            $$.nval = $2.nval * $3.nval;
                                            arith.pop();
                                        }
                                    break;
                                    
                                    case(RELATIONAL_OP):
                                    {
                                        if(!isIntOrStrCompatible($2.type))
                                        {
                                            yyerror("Arg 1 must be integer or string");
                                            return(1);
                                        }
                                        if(!isIntOrStrCompatible($3.type))
                                        {
                                            yyerror("Arg 2 must be integer or string");
                                            return(1);
                                        }
                                         if(isIntCompatible($2.type)&&!isIntCompatible($3.type))
                                        {
                                            yyerror("Arg 2 must be integer");
                                            return(1);
                                        }
                                         if(isStrCompatible($2.type)&&!isStrCompatible($3.type))
                                        {
                                            yyerror("Arg 2 must be string");
                                            return(1);
                                        }
                                        
                                        $$.type = BOOL;
                                        $$.bval = false;
                                        bool isStrings = ($2.type == STR && $3.type == STR);
                                        if(rel.top() == ">")
                                        {
                                            if(isStrings)
                                            {
                                                $$.bval = false;
                                            }
                                            else if($2.nval > $3.nval)
                                            {
                                                $$.bval = true;
                                            }
                                            else
                                            {
                                                $$.bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == "<")
                                        {
                                            if(isStrings)
                                            {
                                                $$.bval = false;
                                            }
                                            else if($2.nval < $3.nval)
                                            {
                                                $$.bval = true;
                                            }
                                            else
                                            {
                                                $$.bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == ">=")
                                        {
                                            if(isStrings)
                                            {
                                                $$.bval = false;
                                            }
                                            else if($2.nval >= $3.nval)
                                            {
                                                $$.bval = true;
                                            }
                                            else
                                            {
                                                $$.bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == "<=")
                                        {
                                            if(isStrings)
                                            {
                                                $$.bval = false;
                                            }
                                            else if($2.nval <= $3.nval)
                                            {
                                                $$.bval = true;
                                            }
                                            else
                                            {
                                                $$.bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == "=")
                                        {
                                            if(isStrings)
                                            {
                                                $$.bval = (strcmp($2.sval, $3.sval) == 0);
                                            }
                                            else if($2.nval == $3.nval)
                                            {
                                                $$.bval = true;
                                            }
                                            else
                                            {
                                                $$.bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == "/=")
                                        {
                                            if(isStrings)
                                            {
                                                $$.bval = (strcmp($2.sval, $3.sval) != 0);
                                            }
                                            else if($2.nval != $3.nval)
                                            {
                                                $$.bval = true;
                                            }
                                            else
                                            {
                                                $$.bval = false;
                                            }
                                            rel.pop();
                                        }
                                    break;
                                    }
                                    case(LOGICAL_OP):
                                        if($1.logop == OR)
                                        {
                                            $$.type = BOOL;
                                            $$.bval = true;
                                            if($2.bval == false && $3.bval == false)
                                            {
                                                $$.bval = false;
                                            }
                                        }
                                        else if($1.logop == AND)
                                        {
                                            $$.type = BOOL;
                                            $$.bval = false;
                                            if($2.bval == true && $3.bval == true)
                                            {
                                                $$.bval = true;
                                            }
                                        }
                                    break;
                                }
                            }
                            ;
N_IF_EXPR               : T_IF N_EXPR N_EXPR N_EXPR
                            {
                                printRule("IF_EXPR", "if EXPR EXPR EXPR");
                                $$.type = $3.type;
                                $$.sval = $3.sval;
                                $$.nval = $3.nval;
                                $$.bval = $3.bval;
                                if($2.type == BOOL)
                                {
                                    if($2.bval == false)
                                    {
                                        $$.type = $4.type;
                                        $$.sval = $4.sval;
                                        $$.nval = $4.nval;
                                        $$.bval = $4.bval;
                                    }
                                }
                            }
                            ;
N_LET_EXPR              : T_LETSTAR T_LPAREN N_ID_EXPR_LIST T_RPAREN N_EXPR
                            {
                                printRule("LET_EXPR", "let* ( ID_EXPR_LIST ) EXPR");
                                endScope();

                                $$.type = $5.type;
                                $$.nval = $5.nval;
                            }
                            ;
N_ID_EXPR_LIST          : /* epsilon */
                            {
                                printRule("ID_EXPR_LIST", "epsilon");
                            }
                        | N_ID_EXPR_LIST T_LPAREN T_IDENT N_EXPR T_RPAREN
                            {
                                printRule("ID_EXPR_LIST", "ID_EXPR_LIST ( IDENT EXPR )");
                                printf ("___Adding %s to symbol table\n", $3);
                                string lex_entry = string($3);
                                TYPE_INFO expr = $4;
                                
                                if(!scopeStack.top().addEntry(SYMBOL_TABLE_ENTRY(lex_entry, expr)))
                                {
                                  yyerror("Multiply defined identifier");
                                  return(1);
                                }
                                else
                                {
                                  SYMBOL_TABLE_ENTRY entry = SYMBOL_TABLE_ENTRY(lex_entry, expr);
                                  scopeStack.top().addEntry(entry);
                                }
                            }
                            ;
N_PRINT_EXPR            : T_PRINT N_EXPR
                            {
                                printRule("PRINT_EXPR", "print EXPR");
                                if($2.type == BOOL)
                                {
                                    printf("%s\n", ($2.bval) ? "true" : "false");
                                }
                                else if($2.type == INT)
                                {
                                    printf("%d\n", $2.nval);
                                }
                                else
                                {
                                    printf("%s\n", $2.sval);
                                }
                                $$.type = $2.type;
                                $$.sval = $2.sval;
                                $$.nval = $2.nval;
                                $$.bval = $2.bval;
                            }    
                            ;
N_INPUT_EXPR            : T_INPUT
                            {
                                printRule("INPUT_EXPR", "input");
                                string word;
                                getline(cin, word);
                                if(word[0] == '+' || word[0] == '-' || isdigit(word[0]))
                                {
                                    $$.type = INT;
                                    $$.nval = atoi(word.c_str());
                                }
                                else
                                {
                                    $$.type = STR;
                                    $$.sval = (char *)word.c_str();
                                }
                            }   
                            ;                    
N_EXPR_LIST             : N_EXPR N_EXPR_LIST
                            {
                                printRule("EXPR_LIST", "EXPR EXPR_LIST");
                                $$.type = $2.type;
                                $$.sval = $2.sval;
                                $$.nval = $2.nval;
                            }
                        | N_EXPR
                            {
                                printRule("EXPR_LIST", "EXPR");
                                $$.type = $1.type;
                                $$.sval = $1.sval;
                                $$.nval = $1.nval;
                            }
                            ;
N_BIN_OP                : N_ARITH_OP
                            {
                                printRule("BIN_OP", "ARITH_OP");
                                $$.op = ARITHMETIC_OP;
                            }
                        | N_LOG_OP
                            {
                                printRule("BIN_OP", "LOG_OP");
                                $$.op = LOGICAL_OP;
                            }
                        | N_REL_OP
                            {
                                printRule("BIN_OP", "REL_OP");
                                $$.op = RELATIONAL_OP;
                            }
                            ;
N_ARITH_OP              : T_MULT
                            {
                                printRule("ARITH_OP", "*");
                                arith.push('*');
                            }
                        | T_SUB
                            {
                                printRule("ARITH_OP", "-");
                                arith.push('-');
                            }
                        | T_DIV
                            {
                                printRule("ARITH_OP", "/");
                                arith.push('/');
                            }
                        | T_ADD
                            {
                                printRule("ARITH_OP", "+");
                                arith.push('+');
                            }
                            ;
N_LOG_OP                : T_AND
                            {
                                printRule("LOG_OP", "and");
                                $$.logop = AND;
                            }
                        | T_OR
                            {
                                printRule("LOG_OP", "or");
                                $$.logop = OR;
                            }
                            ;
N_REL_OP                : T_LT
                            {
                                printRule ("REL_OP", "<");
                                rel.push("<");
                            }
                        | T_GT
                            {
                                printRule("REL_OP", ">");
                                rel.push(">");
                            }
                        | T_LE
                            {
                                printRule("REL_OP", "<=");
                                rel.push("<=");
                            }
                        | T_GE
                            {
                                printRule("REL_OP", ">=");
                                rel.push(">=");
                            }
                        | T_EQ
                            {
                                printRule("REL_OP", "=");
                                rel.push("=");
                            }
                        | T_NE
                            {
                                printRule("REL_OP", "/=");
                                rel.push("/=");
                            }
                            ;
N_UN_OP                 : T_NOT
                            {
                                printRule("UN_OP", "not");
                                $$.unop = NOT;
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

void endScope()
{
//   int size = scopeStack.top().getMap().size();
  scopeStack.pop();
  printf("\n___Exiting scope...\n\n");
//   return size;
}

void printRule(const char *lhs, const char *rhs)
{
  printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s)
{
  printf("Line %d: %s\n", numLines, s);
  cleanup();
  exit(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme)
{
  printf("TOKEN: %s LEXEME: %s\n", tokenType, lexeme);
}

TYPE_INFO findEntryInAnyScope(const string theName) 
{
    TYPE_INFO info = {UNDEFINED};
  if (scopeStack.empty( )) 
    return(info);
  
  info = scopeStack.top( ).findEntry(theName);
  if (info.type != UNDEFINED) {
    return(info);
  }
  else
  {
    SYMBOL_TABLE symbolTable = scopeStack.top( );
    scopeStack.pop( );
    info = findEntryInAnyScope(theName);
    scopeStack.push(symbolTable);
    return(info);
  }
}

bool isIntCompatible(const int theType)
{
    return((theType == INT) || (theType == INT_OR_STR) || 
            (theType == INT_OR_BOOL) || (theType == INT_OR_STR_OR_BOOL));
}

bool isStrCompatible(const int theType)
{
    return((theType == STR) || (theType == INT_OR_STR) || 
            (theType == STR_OR_BOOL) || (theType == INT_OR_STR_OR_BOOL));
}

bool isIntOrStrCompatible(const int theType) 
{
  return(isStrCompatible(theType) || isIntCompatible(theType));
}

void cleanup()
{
    if(scopeStack.empty())
        return;
    else
    {
        scopeStack.pop();
        cleanup();
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

    cleanup();
    return 0;
}                        