/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "youngmaersch.y" /* yacc.c:339  */

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

#line 106 "youngmaersch.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_IDENT = 258,
    T_UNKNOWN = 259,
    T_STRCONST = 260,
    T_LETSTAR = 261,
    T_INTCONST = 262,
    T_INPUT = 263,
    T_PRINT = 264,
    T_IF = 265,
    T_LPAREN = 266,
    T_RPAREN = 267,
    T_LAMBDA = 268,
    T_ADD = 269,
    T_MULT = 270,
    T_DIV = 271,
    T_SUB = 272,
    T_AND = 273,
    T_OR = 274,
    T_NOT = 275,
    T_LT = 276,
    T_GT = 277,
    T_LE = 278,
    T_GE = 279,
    T_EQ = 280,
    T_NE = 281,
    T_T = 282,
    T_NIL = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 48 "youngmaersch.y" /* yacc.c:355  */

  char* text;
  TYPE_INFO typeinfo;
  int num;

#line 178 "youngmaersch.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 195 "youngmaersch.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   78

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  41
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  58

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    97,   103,   116,   125,   132,   139,   145,
     152,   159,   167,   172,   177,   182,   188,   201,   395,   414,
     424,   427,   446,   467,   484,   491,   499,   504,   509,   515,
     520,   525,   530,   536,   541,   547,   552,   557,   562,   567,
     572,   578
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_IDENT", "T_UNKNOWN", "T_STRCONST",
  "T_LETSTAR", "T_INTCONST", "T_INPUT", "T_PRINT", "T_IF", "T_LPAREN",
  "T_RPAREN", "T_LAMBDA", "T_ADD", "T_MULT", "T_DIV", "T_SUB", "T_AND",
  "T_OR", "T_NOT", "T_LT", "T_GT", "T_LE", "T_GE", "T_EQ", "T_NE", "T_T",
  "T_NIL", "$accept", "N_START", "N_EXPR", "N_CONST",
  "N_PARENTHESIZED_EXPR", "N_ARITHLOGIC_EXPR", "N_IF_EXPR", "N_LET_EXPR",
  "N_ID_EXPR_LIST", "N_PRINT_EXPR", "N_INPUT_EXPR", "N_EXPR_LIST",
  "N_BIN_OP", "N_ARITH_OP", "N_LOG_OP", "N_REL_OP", "N_UN_OP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

#define YYPACT_NINF -14

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-14)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -2,   -14,   -14,   -14,    50,   -14,   -14,     2,   -14,   -14,
      -7,   -14,    -2,    -2,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,    -2,    -4,   -14,
     -14,   -14,   -14,   -14,   -14,    -2,   -14,   -14,   -14,    -2,
     -14,   -14,   -14,    -2,   -14,   -14,    -2,   -14,    -5,    -2,
     -14,     7,    -2,   -14,    -2,   -14,    -1,   -14
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     4,     7,     6,     0,     8,     9,     0,     2,     3,
       0,    23,     0,     0,    32,    29,    31,    30,    33,    34,
      41,    35,    36,    37,    38,    39,    40,    25,     0,    10,
      11,    12,    13,    14,    15,     0,    26,    27,    28,     0,
       1,    20,    22,     0,    24,     5,     0,    16,     0,     0,
      17,     0,     0,    18,     0,    19,     0,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -14,   -14,     0,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,   -13,   -14,   -14,   -14,   -14,   -14
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,    27,     9,    28,    29,    30,    31,    48,    32,
      33,    34,    35,    36,    37,    38,    39
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,     1,    40,     2,    41,     3,    51,    52,    45,     4,
      54,    57,    42,    43,    44,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     0,     0,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,    47,
       0,     0,     0,    49,     0,     0,    50,     0,     0,    53,
       0,     0,    55,     1,    56,     2,    10,     3,    11,    12,
      13,     4,     0,     0,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,     5,     6
};

static const yytype_int8 yycheck[] =
{
       0,     3,     0,     5,    11,     7,    11,    12,    12,    11,
       3,    12,    12,    13,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    43,    -1,    -1,    46,    -1,    -1,    49,
      -1,    -1,    52,     3,    54,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,    11,    27,    28,    30,    31,    32,
       6,     8,     9,    10,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    31,    33,    34,
      35,    36,    38,    39,    40,    41,    42,    43,    44,    45,
       0,    11,    31,    31,    40,    12,    31,    31,    37,    31,
      31,    11,    12,    31,     3,    31,    31,    12
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    31,    31,    31,    32,    32,    32,    32,
      33,    33,    33,    33,    33,    33,    34,    34,    35,    36,
      37,    37,    38,    39,    40,    40,    41,    41,    41,    42,
      42,    42,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    45
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     3,     4,     5,
       0,     5,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 72 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("START", "EXPR");
                                printf("\n---- Completed parsing ----\n\n");
                                if((yyvsp[0].typeinfo).type == INT)
                                {
                                    printf("\nValue of the expression is: %d\n", (yyvsp[0].typeinfo).nval);
                                }
                                else if((yyvsp[0].typeinfo).type == STR)
                                {
                                    printf("\nValue of the expression is: %s\n", (yyvsp[0].typeinfo).sval);
                                }
                                else
                                {
                                    if((yyvsp[0].typeinfo).bval == true)
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
#line 1337 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 98 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("EXPR", "CONST");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                                (yyval.typeinfo).sval = (yyvsp[0].typeinfo).sval;                               
                            }
#line 1347 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 104 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("EXPR","IDENT");
                                string id = string((yyvsp[0].text));
                                TYPE_INFO expr = findEntryInAnyScope(id);
                                if(expr.type == UNDEFINED)
                                {
                                  yyerror("Undefined identifier");
                                  return(0);
                                }
                                (yyval.typeinfo).type = expr.type;
                                (yyval.typeinfo).nval = expr.nval;
                            }
#line 1364 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("EXPR", "( PARENTHESIZED_EXPR )");
                                (yyval.typeinfo).type = (yyvsp[-1].typeinfo).type;
                                (yyval.typeinfo).sval = (yyvsp[-1].typeinfo).sval;
                                (yyval.typeinfo).nval = (yyvsp[-1].typeinfo).nval;
                                (yyval.typeinfo).bval = (yyvsp[-1].typeinfo).bval;
                            }
#line 1376 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 126 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("CONST", "INTCONST");
                                (yyval.typeinfo).type = INT;
                                (yyval.typeinfo).nval = atoi((yyvsp[0].text));
                                (yyval.typeinfo).bval = true;
                            }
#line 1387 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 133 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("CONST", "STRCONST");
                                (yyval.typeinfo).type = STR;
                                (yyval.typeinfo).sval = (yyvsp[0].text);
                                (yyval.typeinfo).bval = true;
                            }
#line 1398 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 140 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("CONST", "t");
                                (yyval.typeinfo).type = BOOL;
                                (yyval.typeinfo).bval = true;
                            }
#line 1408 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 146 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("CONST", "nil");
                                (yyval.typeinfo).type = BOOL;
                                (yyval.typeinfo).bval = false;
                            }
#line 1418 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 153 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "ARITHLOGIC_EXPR");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                                (yyval.typeinfo).nval = (yyvsp[0].typeinfo).nval;
                                (yyval.typeinfo).bval = (yyvsp[0].typeinfo).bval;
                            }
#line 1429 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 160 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "IF_EXPR");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                                (yyval.typeinfo).sval = (yyvsp[0].typeinfo).sval;
                                (yyval.typeinfo).nval = (yyvsp[0].typeinfo).nval;
                                (yyval.typeinfo).bval = (yyvsp[0].typeinfo).bval;
                            }
#line 1441 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 168 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "LET_EXPR");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                            }
#line 1450 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 173 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "PRINT_EXPR");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                            }
#line 1459 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 178 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "INPUT_EXPR");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                            }
#line 1468 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 183 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "EXPR_LIST");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                            }
#line 1477 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 189 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("ARITHLOGIC_EXPR", "UN_OP EXPR");
                                (yyval.typeinfo).type = BOOL;
                                if((yyvsp[-1].typeinfo).unop == NOT)
                                {
                                    (yyval.typeinfo).bval = !(yyvsp[0].typeinfo).bval;
                                }
                                else
                                {
                                    (yyval.typeinfo).bval = (yyvsp[0].typeinfo).bval;
                                }
                            }
#line 1494 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 202 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("ARITHLOGIC_EXPR", "BIN_OP EXPR EXPR");
                                (yyval.typeinfo).type = BOOL;

                                switch((yyvsp[-2].typeinfo).op)
                                {
                                    case(ARITHMETIC_OP):
                                        (yyval.typeinfo).type = INT;
                                        (yyval.typeinfo).bval = true;
                                        if(!isIntCompatible((yyvsp[-1].typeinfo).type))
                                        {
                                            yyerror("Arg 1 must be integer");
                                            return(1);
                                        }
                                        if(!isIntCompatible((yyvsp[0].typeinfo).type))
                                        {
                                            yyerror("Arg 2 must be integer");
                                            return(1);
                                        }
                                        
                                        if(arith.top() == '+')
                                        {
                                            (yyval.typeinfo).nval = (yyvsp[-1].typeinfo).nval + (yyvsp[0].typeinfo).nval;
                                            arith.pop();
                                        }
                                        else if(arith.top() == '-')
                                        {
                                            (yyval.typeinfo).nval = (yyvsp[-1].typeinfo).nval - (yyvsp[0].typeinfo).nval;
                                            arith.pop();
                                        }
                                        else if(arith.top() == '/')
                                        {
                                            if((yyvsp[0].typeinfo).nval == 0)
                                            {
                                                yyerror("Attempted division by zero");
                                            }
                                            (yyval.typeinfo).nval = (yyvsp[-1].typeinfo).nval / (yyvsp[0].typeinfo).nval;
                                            arith.pop();
                                        }
                                         else if(arith.top() == '*')
                                        {
                                            (yyval.typeinfo).nval = (yyvsp[-1].typeinfo).nval * (yyvsp[0].typeinfo).nval;
                                            arith.pop();
                                        }
                                    break;
                                    
                                    case(RELATIONAL_OP):
                                    {
                                        if(!isIntOrStrCompatible((yyvsp[-1].typeinfo).type))
                                        {
                                            yyerror("Arg 1 must be integer or string");
                                            return(1);
                                        }
                                        if(!isIntOrStrCompatible((yyvsp[0].typeinfo).type))
                                        {
                                            yyerror("Arg 2 must be integer or string");
                                            return(1);
                                        }
                                         if(isIntCompatible((yyvsp[-1].typeinfo).type)&&!isIntCompatible((yyvsp[0].typeinfo).type))
                                        {
                                            yyerror("Arg 2 must be integer");
                                            return(1);
                                        }
                                         if(isStrCompatible((yyvsp[-1].typeinfo).type)&&!isStrCompatible((yyvsp[0].typeinfo).type))
                                        {
                                            yyerror("Arg 2 must be string");
                                            return(1);
                                        }
                                        
                                        (yyval.typeinfo).type = BOOL;
                                        (yyval.typeinfo).bval = false;
                                        bool isStrings = ((yyvsp[-1].typeinfo).type == STR && (yyvsp[0].typeinfo).type == STR);
                                        if(rel.top() == ">")
                                        {
                                            if(isStrings)
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            else if((yyvsp[-1].typeinfo).nval > (yyvsp[0].typeinfo).nval)
                                            {
                                                (yyval.typeinfo).bval = true;
                                            }
                                            else
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == "<")
                                        {
                                            if(isStrings)
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            else if((yyvsp[-1].typeinfo).nval < (yyvsp[0].typeinfo).nval)
                                            {
                                                (yyval.typeinfo).bval = true;
                                            }
                                            else
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == ">=")
                                        {
                                            if(isStrings)
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            else if((yyvsp[-1].typeinfo).nval >= (yyvsp[0].typeinfo).nval)
                                            {
                                                (yyval.typeinfo).bval = true;
                                            }
                                            else
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == "<=")
                                        {
                                            if(isStrings)
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            else if((yyvsp[-1].typeinfo).nval <= (yyvsp[0].typeinfo).nval)
                                            {
                                                (yyval.typeinfo).bval = true;
                                            }
                                            else
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == "=")
                                        {
                                            if(isStrings)
                                            {
                                                (yyval.typeinfo).bval = (strcmp((yyvsp[-1].typeinfo).sval, (yyvsp[0].typeinfo).sval) == 0);
                                            }
                                            else if((yyvsp[-1].typeinfo).nval == (yyvsp[0].typeinfo).nval)
                                            {
                                                (yyval.typeinfo).bval = true;
                                            }
                                            else
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            rel.pop();
                                        }
                                        else if(rel.top() == "/=")
                                        {
                                            if(isStrings)
                                            {
                                                (yyval.typeinfo).bval = (strcmp((yyvsp[-1].typeinfo).sval, (yyvsp[0].typeinfo).sval) != 0);
                                            }
                                            else if((yyvsp[-1].typeinfo).nval != (yyvsp[0].typeinfo).nval)
                                            {
                                                (yyval.typeinfo).bval = true;
                                            }
                                            else
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                            rel.pop();
                                        }
                                    break;
                                    }
                                    case(LOGICAL_OP):
                                        if((yyvsp[-2].typeinfo).logop == OR)
                                        {
                                            (yyval.typeinfo).type = BOOL;
                                            (yyval.typeinfo).bval = true;
                                            if((yyvsp[-1].typeinfo).bval == false && (yyvsp[0].typeinfo).bval == false)
                                            {
                                                (yyval.typeinfo).bval = false;
                                            }
                                        }
                                        else if((yyvsp[-2].typeinfo).logop == AND)
                                        {
                                            (yyval.typeinfo).type = BOOL;
                                            (yyval.typeinfo).bval = false;
                                            if((yyvsp[-1].typeinfo).bval == true && (yyvsp[0].typeinfo).bval == true)
                                            {
                                                (yyval.typeinfo).bval = true;
                                            }
                                        }
                                    break;
                                }
                            }
#line 1691 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 396 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("IF_EXPR", "if EXPR EXPR EXPR");
                                (yyval.typeinfo).type = (yyvsp[-1].typeinfo).type;
                                (yyval.typeinfo).sval = (yyvsp[-1].typeinfo).sval;
                                (yyval.typeinfo).nval = (yyvsp[-1].typeinfo).nval;
                                (yyval.typeinfo).bval = (yyvsp[-1].typeinfo).bval;
                                if((yyvsp[-2].typeinfo).type == BOOL)
                                {
                                    if((yyvsp[-2].typeinfo).bval == false)
                                    {
                                        (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                                        (yyval.typeinfo).sval = (yyvsp[0].typeinfo).sval;
                                        (yyval.typeinfo).nval = (yyvsp[0].typeinfo).nval;
                                        (yyval.typeinfo).bval = (yyvsp[0].typeinfo).bval;
                                    }
                                }
                            }
#line 1713 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 415 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("LET_EXPR", "let* ( ID_EXPR_LIST ) EXPR");
                                endScope();

                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                                (yyval.typeinfo).nval = (yyvsp[0].typeinfo).nval;
                            }
#line 1725 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 424 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("ID_EXPR_LIST", "epsilon");
                            }
#line 1733 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 428 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("ID_EXPR_LIST", "ID_EXPR_LIST ( IDENT EXPR )");
                                printf ("___Adding %s to symbol table\n", (yyvsp[-2].text));
                                string lex_entry = string((yyvsp[-2].text));
                                TYPE_INFO expr = (yyvsp[-1].typeinfo);
                                
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
#line 1755 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 447 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("PRINT_EXPR", "print EXPR");
                                if((yyvsp[0].typeinfo).type == BOOL)
                                {
                                    printf("%s\n", ((yyvsp[0].typeinfo).bval) ? "true" : "false");
                                }
                                else if((yyvsp[0].typeinfo).type == INT)
                                {
                                    printf("%d\n", (yyvsp[0].typeinfo).nval);
                                }
                                else
                                {
                                    printf("%s\n", (yyvsp[0].typeinfo).sval);
                                }
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                                (yyval.typeinfo).sval = (yyvsp[0].typeinfo).sval;
                                (yyval.typeinfo).nval = (yyvsp[0].typeinfo).nval;
                                (yyval.typeinfo).bval = (yyvsp[0].typeinfo).bval;
                            }
#line 1779 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 468 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("INPUT_EXPR", "input");
                                string word;
                                getline(cin, word);
                                if(word[0] == '+' || word[0] == '-' || isdigit(word[0]))
                                {
                                    (yyval.typeinfo).type = INT;
                                    (yyval.typeinfo).nval = atoi(word.c_str());
                                }
                                else
                                {
                                    (yyval.typeinfo).type = STR;
                                    (yyval.typeinfo).sval = (char *)word.c_str();
                                }
                            }
#line 1799 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 485 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("EXPR_LIST", "EXPR EXPR_LIST");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                                (yyval.typeinfo).sval = (yyvsp[0].typeinfo).sval;
                                (yyval.typeinfo).nval = (yyvsp[0].typeinfo).nval;
                            }
#line 1810 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 492 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("EXPR_LIST", "EXPR");
                                (yyval.typeinfo).type = (yyvsp[0].typeinfo).type;
                                (yyval.typeinfo).sval = (yyvsp[0].typeinfo).sval;
                                (yyval.typeinfo).nval = (yyvsp[0].typeinfo).nval;
                            }
#line 1821 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 500 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("BIN_OP", "ARITH_OP");
                                (yyval.typeinfo).op = ARITHMETIC_OP;
                            }
#line 1830 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 505 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("BIN_OP", "LOG_OP");
                                (yyval.typeinfo).op = LOGICAL_OP;
                            }
#line 1839 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 510 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("BIN_OP", "REL_OP");
                                (yyval.typeinfo).op = RELATIONAL_OP;
                            }
#line 1848 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 516 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("ARITH_OP", "*");
                                arith.push('*');
                            }
#line 1857 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 521 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("ARITH_OP", "-");
                                arith.push('-');
                            }
#line 1866 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 526 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("ARITH_OP", "/");
                                arith.push('/');
                            }
#line 1875 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 531 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("ARITH_OP", "+");
                                arith.push('+');
                            }
#line 1884 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 537 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("LOG_OP", "and");
                                (yyval.typeinfo).logop = AND;
                            }
#line 1893 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 542 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("LOG_OP", "or");
                                (yyval.typeinfo).logop = OR;
                            }
#line 1902 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 548 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule ("REL_OP", "<");
                                rel.push("<");
                            }
#line 1911 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 553 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", ">");
                                rel.push(">");
                            }
#line 1920 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 558 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", "<=");
                                rel.push("<=");
                            }
#line 1929 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 563 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", ">=");
                                rel.push(">=");
                            }
#line 1938 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 568 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", "=");
                                rel.push("=");
                            }
#line 1947 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 573 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", "/=");
                                rel.push("/=");
                            }
#line 1956 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 579 "youngmaersch.y" /* yacc.c:1646  */
    {
                                printRule("UN_OP", "not");
                                (yyval.typeinfo).unop = NOT;
                            }
#line 1965 "youngmaersch.tab.c" /* yacc.c:1646  */
    break;


#line 1969 "youngmaersch.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 584 "youngmaersch.y" /* yacc.c:1906  */


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
