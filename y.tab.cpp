/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING_LITERAL = 259,
     CONSTANT = 260,
     CHAR_CONSTANT = 261,
     CHAR = 262,
     INT = 263,
     VOID = 264,
     EXTERN = 265,
     CHAR_PTR = 266,
     INT_PTR = 267,
     VOID_PTR = 268,
     IF = 269,
     ELSE = 270,
     FOR = 271,
     WHILE = 272,
     CONTINUE = 273,
     BREAK = 274,
     RETURN = 275,
     RIGHT_SHIFT = 276,
     LEFT_SHIFT = 277,
     LOGIC_AND = 278,
     LOGIC_OR = 279,
     COM_LE = 280,
     COM_GE = 281,
     COM_EQ = 282,
     COM_NE = 283,
     SEMICOLON = 284,
     LBRACE = 285,
     RBRACE = 286,
     COMMA = 287,
     ASSIGN = 288,
     LPAREN = 289,
     RPAREN = 290,
     LBRACKET = 291,
     RBRACKET = 292,
     BIT_AND = 293,
     BIT_XOR = 294,
     BIT_OR = 295,
     BIT_NOT = 296,
     BIT_INVERSION = 297,
     MINUS = 298,
     PLUS = 299,
     MUL = 300,
     DIV = 301,
     MOD = 302,
     COM_L = 303,
     COM_G = 304,
     LOWER_THAN_ELSE = 305
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define STRING_LITERAL 259
#define CONSTANT 260
#define CHAR_CONSTANT 261
#define CHAR 262
#define INT 263
#define VOID 264
#define EXTERN 265
#define CHAR_PTR 266
#define INT_PTR 267
#define VOID_PTR 268
#define IF 269
#define ELSE 270
#define FOR 271
#define WHILE 272
#define CONTINUE 273
#define BREAK 274
#define RETURN 275
#define RIGHT_SHIFT 276
#define LEFT_SHIFT 277
#define LOGIC_AND 278
#define LOGIC_OR 279
#define COM_LE 280
#define COM_GE 281
#define COM_EQ 282
#define COM_NE 283
#define SEMICOLON 284
#define LBRACE 285
#define RBRACE 286
#define COMMA 287
#define ASSIGN 288
#define LPAREN 289
#define RPAREN 290
#define LBRACKET 291
#define RBRACKET 292
#define BIT_AND 293
#define BIT_XOR 294
#define BIT_OR 295
#define BIT_NOT 296
#define BIT_INVERSION 297
#define MINUS 298
#define PLUS 299
#define MUL 300
#define DIV 301
#define MOD 302
#define COM_L 303
#define COM_G 304
#define LOWER_THAN_ELSE 305




/* Copy the first part of user declarations.  */
#line 1 "compiler.y"

	#include "AST.h"
	#include <stdio.h>
	#include <cstdlib>
	BlockAST* programBlock = nullptr;
	extern char *yytext;
	extern FILE * yyin;
	extern FILE * yyout;
	extern int column;

	extern int yylex(void);
	void yyerror(const char*);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 14 "compiler.y"
{
	BlockAST* block;
	ExpAST* expression;
	StmAST* statement;
	FunctionDefAST* function_def;
	FunctionDecAST* function_dec;
	IdentifierExpAST* identifier;
	FunctionCallAST* function_call;
	ArrayIndexAST* array_index;
	VariableDecAST* var_dec;
	std::string* name;
	int token;
	std::vector<VariableDecAST*> *var_dec_list;
	std::vector<ExpAST*> *call_list;
	std::vector<AST*> *statement_list;
}
/* Line 193 of yacc.c.  */
#line 227 "y.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 240 "y.tab.cpp"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   298

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNRULES -- Number of states.  */
#define YYNSTATES  172

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    17,    20,
      25,    31,    39,    46,    47,    49,    53,    54,    56,    60,
      62,    64,    66,    68,    72,    74,    79,    84,    86,    89,
      91,    93,    95,    97,    99,   103,   107,   111,   113,   117,
     121,   123,   127,   131,   133,   137,   141,   145,   149,   151,
     155,   159,   161,   165,   167,   171,   173,   177,   179,   183,
     185,   189,   191,   195,   202,   204,   206,   208,   211,   214,
     217,   219,   221,   223,   225,   227,   229,   232,   236,   240,
     245,   248,   252,   254,   257,   259,   262,   268,   276,   282,
     291,   301,   304,   307,   310
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      52,     0,    -1,    53,    -1,    54,    -1,    53,    54,    -1,
      57,    -1,    56,    -1,    55,    29,    -1,    75,    76,    -1,
      75,    76,    33,    74,    -1,    75,    76,    36,     5,    37,
      -1,    10,    75,    76,    34,    58,    35,    29,    -1,    75,
      76,    34,    58,    35,    78,    -1,    -1,    55,    -1,    58,
      32,    55,    -1,    -1,    74,    -1,    59,    32,    74,    -1,
      76,    -1,     5,    -1,     6,    -1,     4,    -1,    34,    74,
      35,    -1,    60,    -1,    76,    36,    74,    37,    -1,    76,
      34,    59,    35,    -1,    61,    -1,    63,    62,    -1,    44,
      -1,    43,    -1,    42,    -1,    41,    -1,    62,    -1,    64,
      45,    62,    -1,    64,    46,    62,    -1,    64,    47,    62,
      -1,    64,    -1,    65,    44,    64,    -1,    65,    43,    64,
      -1,    65,    -1,    66,    22,    65,    -1,    66,    21,    65,
      -1,    66,    -1,    67,    48,    66,    -1,    67,    49,    66,
      -1,    67,    25,    66,    -1,    67,    26,    66,    -1,    67,
      -1,    68,    27,    67,    -1,    68,    28,    67,    -1,    68,
      -1,    69,    38,    68,    -1,    69,    -1,    70,    39,    69,
      -1,    70,    -1,    71,    40,    70,    -1,    71,    -1,    72,
      23,    71,    -1,    72,    -1,    73,    24,    72,    -1,    73,
      -1,    76,    33,    74,    -1,    76,    36,    74,    37,    33,
      74,    -1,     9,    -1,     7,    -1,     8,    -1,     9,    45,
      -1,     7,    45,    -1,     8,    45,    -1,     3,    -1,    78,
      -1,    81,    -1,    82,    -1,    83,    -1,    84,    -1,    30,
      31,    -1,    30,    80,    31,    -1,    30,    79,    31,    -1,
      30,    79,    80,    31,    -1,    55,    29,    -1,    79,    55,
      29,    -1,    77,    -1,    80,    77,    -1,    29,    -1,    74,
      29,    -1,    14,    34,    74,    35,    77,    -1,    14,    34,
      74,    35,    77,    15,    77,    -1,    17,    34,    74,    35,
      77,    -1,    16,    34,    74,    29,    74,    29,    35,    77,
      -1,    16,    34,    74,    29,    74,    29,    74,    35,    77,
      -1,    18,    29,    -1,    19,    29,    -1,    20,    29,    -1,
      20,    74,    29,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    56,    56,    60,    61,    65,    66,    67,    72,    73,
      76,    87,   100,   114,   115,   116,   121,   122,   127,   135,
     136,   137,   138,   142,   147,   148,   154,   165,   166,   171,
     172,   173,   174,   179,   180,   181,   182,   187,   188,   189,
     194,   195,   196,   201,   202,   203,   204,   205,   210,   211,
     212,   217,   218,   223,   224,   229,   230,   235,   236,   241,
     242,   247,   248,   249,   258,   259,   260,   261,   262,   263,
     267,   272,   273,   274,   275,   276,   281,   282,   286,   291,
     300,   304,   309,   310,   315,   316,   321,   326,   337,   342,
     347,   356,   357,   358,   359
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING_LITERAL",
  "CONSTANT", "CHAR_CONSTANT", "CHAR", "INT", "VOID", "EXTERN", "CHAR_PTR",
  "INT_PTR", "VOID_PTR", "IF", "ELSE", "FOR", "WHILE", "CONTINUE", "BREAK",
  "RETURN", "RIGHT_SHIFT", "LEFT_SHIFT", "LOGIC_AND", "LOGIC_OR", "COM_LE",
  "COM_GE", "COM_EQ", "COM_NE", "SEMICOLON", "LBRACE", "RBRACE", "COMMA",
  "ASSIGN", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "BIT_AND",
  "BIT_XOR", "BIT_OR", "BIT_NOT", "BIT_INVERSION", "MINUS", "PLUS", "MUL",
  "DIV", "MOD", "COM_L", "COM_G", "LOWER_THAN_ELSE", "$accept", "program",
  "translation_unit", "external_declaration", "variable_declaration",
  "function_declaration", "function_definition", "func_decl_arguments",
  "argument_expression_list", "primary_expression", "postfix_expression",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "expression", "type_specifier", "identifier",
  "statement", "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    55,    55,
      55,    56,    57,    58,    58,    58,    59,    59,    59,    60,
      60,    60,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    65,
      66,    66,    66,    67,    67,    67,    67,    67,    68,    68,
      68,    69,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    74,    75,    75,    75,    75,    75,    75,
      76,    77,    77,    77,    77,    77,    78,    78,    78,    78,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      83,    84,    84,    84,    84
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     2,     4,
       5,     7,     6,     0,     1,     3,     0,     1,     3,     1,
       1,     1,     1,     3,     1,     4,     4,     1,     2,     1,
       1,     1,     1,     1,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     6,     1,     1,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     3,     3,     4,
       2,     3,     1,     2,     1,     2,     5,     7,     5,     8,
       9,     2,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    65,    66,    64,     0,     0,     2,     3,     0,     6,
       5,     0,    68,    69,    67,     0,     1,     4,     7,    70,
       8,     0,     0,    13,     0,    13,    22,    20,    21,     0,
      32,    31,    30,    29,    24,    27,    33,     0,    37,    40,
      43,    48,    51,    53,    55,    57,    59,    61,     9,    19,
      14,     0,     0,     0,     0,     0,    28,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,     0,     0,
       0,     8,    10,     0,    23,     0,    34,    35,    36,    39,
      38,    42,    41,    46,    47,    44,    45,    49,    50,    52,
      54,    56,    58,    60,    62,     0,    17,     0,    15,     0,
      12,    11,     0,     0,    26,    25,     0,     0,     0,     0,
       0,     0,    84,    76,     0,     0,    82,    71,     0,     0,
      72,    73,    74,    75,    25,    18,     0,     0,     0,     0,
      91,    92,    93,     0,    80,    85,    78,     0,     0,    77,
      83,    63,     0,     0,     0,    94,    81,    79,     0,     0,
       0,    86,     0,    88,     0,     0,    87,     0,     0,    89,
       0,    90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    51,   105,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,   125,    52,    49,   126,   127,   128,   129,
     130,   131,   132,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -45
static const yytype_int16 yypact[] =
{
      76,   -44,   -40,   -24,    94,    37,    76,   -45,    58,   -45,
     -45,    93,   -45,   -45,   -45,    93,   -45,   -45,   -45,   -45,
      28,    78,   241,    94,   108,    94,   -45,   -45,   -45,   241,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   241,    59,   -33,
      20,   -17,    21,    87,    88,    86,   105,   106,   -45,    64,
     -45,   -29,    93,    99,   -16,   103,   -45,    -1,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,   241,
     241,   241,   241,   241,   241,   241,   241,   241,   241,    94,
     109,    24,   -45,   111,   -45,   241,   -45,   -45,   -45,    59,
      59,   -33,   -33,    20,    20,    20,    20,   -17,   -17,    21,
      87,    88,    86,   105,   -45,   -15,   -45,   104,   -45,   115,
     -45,   -45,   110,   241,   -45,   117,   114,   118,   119,   113,
     122,   226,   -45,   -45,   125,   126,   -45,   -45,   157,     9,
     -45,   -45,   -45,   -45,   -45,   -45,   241,   241,   241,   241,
     -45,   -45,   -45,   138,   -45,   -45,   -45,   139,   176,   -45,
     -45,   -45,   134,   141,   137,   -45,   -45,   -45,   208,   241,
     208,   163,   154,   -45,   208,   230,   -45,   208,   149,   -45,
     208,   -45
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -45,   -45,   -45,   179,   -21,   -45,   -45,   164,   -45,   -45,
     -45,   -13,   -45,    47,    26,    27,    41,   131,   132,   124,
     129,   133,   -45,   -22,    30,     7,   128,   135,   -45,    81,
     -45,   -45,   -45,   -45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      48,    12,    50,    79,    50,    13,    80,    55,    65,    66,
      61,    62,    19,    26,    27,    28,    79,   113,    20,    83,
     114,    14,    21,   116,    56,   117,   118,   119,   120,   121,
      11,    67,    68,    77,    15,    85,    11,    16,   122,   109,
     149,    63,    64,    29,    57,    86,    87,    88,    69,    70,
      30,    31,    32,    33,   104,   106,   107,    22,   108,    81,
      24,    22,    23,   112,    24,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,     1,     2,     3,     4,    18,   124,    91,
      92,   135,    93,    94,    95,    96,    19,    76,    77,   143,
      78,     1,     2,     3,    58,    59,    60,   147,    89,    90,
      97,    98,    25,    53,   151,   152,   153,   154,    19,    26,
      27,    28,     1,     2,     3,    71,    73,    72,    74,   116,
      75,   117,   118,   119,   120,   121,    82,   162,    84,   109,
     111,   115,   140,   168,   122,   109,   123,   134,   137,    29,
     136,   141,   138,   139,   144,   145,    30,    31,    32,    33,
      19,    26,    27,    28,     1,     2,     3,   155,   156,   158,
     159,   116,   160,   117,   118,   119,   120,   121,   164,    19,
      26,    27,    28,   165,   170,    17,   122,   109,   146,    54,
     116,    29,   117,   118,   119,   120,   121,   101,    30,    31,
      32,    33,    99,   102,   100,   122,   109,   157,   103,   148,
      29,    19,    26,    27,    28,   110,     0,    30,    31,    32,
      33,     0,   116,     0,   117,   118,   119,   120,   121,    19,
      26,    27,    28,    19,    26,    27,    28,   122,   109,     0,
       0,     0,    29,     0,    19,    26,    27,    28,     0,    30,
      31,    32,    33,     0,     0,   142,     0,   150,     0,     0,
      29,     0,     0,     0,    29,   167,     0,    30,    31,    32,
      33,    30,    31,    32,    33,    29,   150,     0,     0,     0,
       0,     0,    30,    31,    32,    33,   161,     0,   163,     0,
       0,     0,   166,     0,     0,   169,     0,     0,   171
};

static const yytype_int16 yycheck[] =
{
      22,    45,    23,    32,    25,    45,    35,    29,    25,    26,
      43,    44,     3,     4,     5,     6,    32,    32,    11,    35,
      35,    45,    15,    14,    37,    16,    17,    18,    19,    20,
       0,    48,    49,    34,     4,    36,     6,     0,    29,    30,
      31,    21,    22,    34,    37,    58,    59,    60,    27,    28,
      41,    42,    43,    44,    76,    77,    78,    33,    79,    52,
      36,    33,    34,    85,    36,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     7,     8,     9,    10,    29,   109,    63,
      64,   113,    65,    66,    67,    68,     3,    33,    34,   121,
      36,     7,     8,     9,    45,    46,    47,   128,    61,    62,
      69,    70,    34,     5,   136,   137,   138,   139,     3,     4,
       5,     6,     7,     8,     9,    38,    40,    39,    23,    14,
      24,    16,    17,    18,    19,    20,    37,   159,    35,    30,
      29,    37,    29,   165,    29,    30,    31,    37,    34,    34,
      33,    29,    34,    34,    29,    29,    41,    42,    43,    44,
       3,     4,     5,     6,     7,     8,     9,    29,    29,    35,
      29,    14,    35,    16,    17,    18,    19,    20,    15,     3,
       4,     5,     6,    29,    35,     6,    29,    30,    31,    25,
      14,    34,    16,    17,    18,    19,    20,    73,    41,    42,
      43,    44,    71,    74,    72,    29,    30,    31,    75,   128,
      34,     3,     4,     5,     6,    80,    -1,    41,    42,    43,
      44,    -1,    14,    -1,    16,    17,    18,    19,    20,     3,
       4,     5,     6,     3,     4,     5,     6,    29,    30,    -1,
      -1,    -1,    34,    -1,     3,     4,     5,     6,    -1,    41,
      42,    43,    44,    -1,    -1,    29,    -1,   129,    -1,    -1,
      34,    -1,    -1,    -1,    34,    35,    -1,    41,    42,    43,
      44,    41,    42,    43,    44,    34,   148,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,   158,    -1,   160,    -1,
      -1,    -1,   164,    -1,    -1,   167,    -1,    -1,   170
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    52,    53,    54,    55,    56,
      57,    75,    45,    45,    45,    75,     0,    54,    29,     3,
      76,    76,    33,    34,    36,    34,     4,     5,     6,    34,
      41,    42,    43,    44,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    76,
      55,    58,    75,     5,    58,    74,    62,    76,    45,    46,
      47,    43,    44,    21,    22,    25,    26,    48,    49,    27,
      28,    38,    39,    40,    23,    24,    33,    34,    36,    32,
      35,    76,    37,    35,    35,    36,    62,    62,    62,    64,
      64,    65,    65,    66,    66,    66,    66,    67,    67,    68,
      69,    70,    71,    72,    74,    59,    74,    74,    55,    30,
      78,    29,    74,    32,    35,    37,    14,    16,    17,    18,
      19,    20,    29,    31,    55,    74,    77,    78,    79,    80,
      81,    82,    83,    84,    37,    74,    33,    34,    34,    34,
      29,    29,    29,    74,    29,    29,    31,    55,    80,    31,
      77,    74,    74,    74,    74,    29,    29,    31,    35,    29,
      35,    77,    74,    77,    15,    29,    77,    35,    74,    77,
      35,    77
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

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
#line 56 "compiler.y"
    {programBlock = (yyvsp[(1) - (1)].block);}
    break;

  case 3:
#line 60 "compiler.y"
    { (yyval.block) = new BlockAST(); (yyval.block)->addAST((yyvsp[(1) - (1)].block)); }
    break;

  case 4:
#line 61 "compiler.y"
    { (yyvsp[(1) - (2)].block)->addAST((yyvsp[(2) - (2)].block)); }
    break;

  case 5:
#line 65 "compiler.y"
    { (yyval.function_def) = (yyvsp[(1) - (1)].function_def);}
    break;

  case 6:
#line 66 "compiler.y"
    { (yyval.function_dec) = (yyvsp[(1) - (1)].function_dec); }
    break;

  case 7:
#line 67 "compiler.y"
    { (yyval.var_dec) = (yyvsp[(1) - (2)].var_dec); }
    break;

  case 8:
#line 72 "compiler.y"
    { (yyval.var_dec) = new VariableDecAST((yyvsp[(1) - (2)].token), (yyvsp[(2) - (2)].identifier), nullptr); }
    break;

  case 9:
#line 73 "compiler.y"
    {
		(yyval.var_dec) = new VariableDecAST((yyvsp[(1) - (4)].token), (yyvsp[(2) - (4)].identifier), (yyvsp[(4) - (4)].expression));
	}
    break;

  case 10:
#line 76 "compiler.y"
    {
		// array
		int length = atoi((yyvsp[(4) - (5)].name)->c_str());
		if (length <= 0) yyerror("array length cannot be less than 0");
		(yyvsp[(2) - (5)].identifier)->setToArray(length);
		(yyval.var_dec) = new VariableDecAST((yyvsp[(1) - (5)].token), (yyvsp[(2) - (5)].identifier));
	}
    break;

  case 11:
#line 87 "compiler.y"
    {
		/* AS: extern int printf(char* format); */
		/* add a field to tell whether it is extern*/
		(yyval.function_dec) = new FunctionDecAST();
		(yyval.function_dec)->setName((yyvsp[(3) - (7)].identifier)->getName());
		(yyval.function_dec)->setType((yyvsp[(2) - (7)].token));
		for (auto p = (yyvsp[(5) - (7)].var_dec_list)->begin(); p != (yyvsp[(5) - (7)].var_dec_list)->end(); p++) {
			(yyval.function_dec)->addArg((*p)->type, (*p)->lhs->name);
		}
	}
    break;

  case 12:
#line 100 "compiler.y"
    {
		/* AS: int func(int a, char b){...} */
		FunctionDecAST* func_dec = new FunctionDecAST();
		func_dec->setName((yyvsp[(2) - (6)].identifier)->getName());
		func_dec->setType((yyvsp[(1) - (6)].token));
		for (auto p = (yyvsp[(4) - (6)].var_dec_list)->begin(); p != (yyvsp[(4) - (6)].var_dec_list)->end(); p++) {
			func_dec->addArg((*p)->type, (*p)->lhs->name);
		}
		(yyval.function_def) = new FunctionDefAST(func_dec, (yyvsp[(6) - (6)].block));
	}
    break;

  case 13:
#line 114 "compiler.y"
    { (yyval.var_dec_list) = new std::vector<VariableDecAST*>();}
    break;

  case 14:
#line 115 "compiler.y"
    { (yyval.var_dec_list) = new std::vector<VariableDecAST*>(); (yyval.var_dec_list)->push_back((yyvsp[(1) - (1)].var_dec)); }
    break;

  case 15:
#line 116 "compiler.y"
    { (yyvsp[(1) - (3)].var_dec_list)->push_back((yyvsp[(3) - (3)].var_dec)); }
    break;

  case 16:
#line 121 "compiler.y"
    { (yyval.call_list) = new std::vector<ExpAST*>(); }
    break;

  case 17:
#line 122 "compiler.y"
    {
		//参数
		(yyval.call_list) = new std::vector<ExpAST*>(); 
		(yyval.call_list)->push_back((yyvsp[(1) - (1)].expression));
	}
    break;

  case 18:
#line 127 "compiler.y"
    {
		//多个参数
		(yyvsp[(1) - (3)].call_list)->push_back((yyvsp[(3) - (3)].expression));
	}
    break;

  case 19:
#line 135 "compiler.y"
    { /*标识符*/ (yyval.identifier) = (yyvsp[(1) - (1)].identifier); }
    break;

  case 20:
#line 136 "compiler.y"
    { /*常数*/ (yyval.expression) = new IntExpAST(atoi((yyvsp[(1) - (1)].name)->c_str())); }
    break;

  case 21:
#line 137 "compiler.y"
    { (yyval.expression) = new CharExpAST((*(yyvsp[(1) - (1)].name))[0]); }
    break;

  case 22:
#line 138 "compiler.y"
    {/*字符串常数*/
		/* $$ = new StringLiteral(*$1); */
		(yyval.expression) = nullptr;
    }
    break;

  case 23:
#line 142 "compiler.y"
    { (yyval.expression) = (yyvsp[(2) - (3)].expression); }
    break;

  case 24:
#line 147 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 25:
#line 148 "compiler.y"
    { 
		/*数组调用*/
		(yyvsp[(1) - (4)].identifier)->setToArray(0);
		ArrayIndexAST* arrayIndex = new ArrayIndexAST((yyvsp[(1) - (4)].identifier), (yyvsp[(3) - (4)].expression));
		(yyval.array_index) = arrayIndex;
	}
    break;

  case 26:
#line 154 "compiler.y"
    {
        /*有参数的函数调用 (和定义一样，改为直接设置argument list) */
		FunctionCallAST* func_call = new FunctionCallAST((yyvsp[(1) - (4)].identifier)->getName());
		for (auto p = (yyvsp[(3) - (4)].call_list)->begin(); p != (yyvsp[(3) - (4)].call_list)->end(); p++)
			func_call->addArg(*p);
		(yyval.function_call) = func_call;
    }
    break;

  case 27:
#line 165 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 28:
#line 166 "compiler.y"
    { /* $$ = new UnaryExp(); ... */ }
    break;

  case 29:
#line 171 "compiler.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 30:
#line 172 "compiler.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 31:
#line 173 "compiler.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 32:
#line 174 "compiler.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 33:
#line 179 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 34:
#line 180 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 35:
#line 181 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 36:
#line 182 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 37:
#line 187 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 38:
#line 188 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 39:
#line 189 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 40:
#line 194 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 41:
#line 195 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 42:
#line 196 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 43:
#line 201 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 44:
#line 202 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 45:
#line 203 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 46:
#line 204 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 47:
#line 205 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 48:
#line 210 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 49:
#line 211 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 50:
#line 212 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 51:
#line 217 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 52:
#line 218 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 53:
#line 223 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 54:
#line 224 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 55:
#line 229 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 56:
#line 230 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 57:
#line 235 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 58:
#line 236 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 59:
#line 241 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 60:
#line 242 "compiler.y"
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[(2) - (3)].token), (yyvsp[(1) - (3)].expression), (yyvsp[(3) - (3)].expression)); }
    break;

  case 61:
#line 247 "compiler.y"
    { (yyval.expression) = (yyvsp[(1) - (1)].expression); }
    break;

  case 62:
#line 248 "compiler.y"
    { (yyval.expression) = new VariableAssignAST((yyvsp[(1) - (3)].identifier), (yyvsp[(3) - (3)].expression)); }
    break;

  case 63:
#line 249 "compiler.y"
    {
		(yyvsp[(1) - (6)].identifier)->setToArray(0);
		ArrayIndexAST* arrayIndex = new ArrayIndexAST((yyvsp[(1) - (6)].identifier), (yyvsp[(3) - (6)].expression));
		(yyval.expression) = new ArrayAssignAST(arrayIndex, (yyvsp[(6) - (6)].expression));
	}
    break;

  case 64:
#line 258 "compiler.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 65:
#line 259 "compiler.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 66:
#line 260 "compiler.y"
    { (yyval.token) = (yyvsp[(1) - (1)].token); }
    break;

  case 67:
#line 261 "compiler.y"
    { (yyval.token) = VOID_PTR; }
    break;

  case 68:
#line 262 "compiler.y"
    { (yyval.token) = CHAR_PTR; }
    break;

  case 69:
#line 263 "compiler.y"
    { (yyval.token) = INT_PTR; }
    break;

  case 70:
#line 267 "compiler.y"
    { (yyval.identifier) = new IdentifierExpAST(*(yyvsp[(1) - (1)].name)); }
    break;

  case 71:
#line 272 "compiler.y"
    { (yyval.block) = (yyvsp[(1) - (1)].block); }
    break;

  case 72:
#line 273 "compiler.y"
    { (yyval.block) = (yyvsp[(1) - (1)].block); }
    break;

  case 75:
#line 276 "compiler.y"
    { (yyval.statement) = (yyvsp[(1) - (1)].statement); }
    break;

  case 76:
#line 281 "compiler.y"
    { (yyval.block) = new BlockAST(); }
    break;

  case 77:
#line 282 "compiler.y"
    { 
		(yyval.block) = new BlockAST();
		for (auto p = (yyvsp[(2) - (3)].statement_list)->begin(); p != (yyvsp[(2) - (3)].statement_list)->end(); p++) (yyval.block)->addAST(*p);	
	}
    break;

  case 78:
#line 286 "compiler.y"
    {
		(yyval.block) = new BlockAST();
		// need VariableDeclaration
		for (auto p = (yyvsp[(2) - (3)].var_dec_list)->begin(); p != (yyvsp[(2) - (3)].var_dec_list)->end(); p++) (yyval.block)->addAST(*p);
	}
    break;

  case 79:
#line 291 "compiler.y"
    {
		(yyval.block) = new BlockAST();
		for (auto p = (yyvsp[(2) - (4)].var_dec_list)->begin(); p != (yyvsp[(2) - (4)].var_dec_list)->end(); p++) (yyval.block)->addAST(*p);
		for (auto p = (yyvsp[(3) - (4)].statement_list)->begin(); p != (yyvsp[(3) - (4)].statement_list)->end(); p++) (yyval.block)->addAST(*p);
	}
    break;

  case 80:
#line 300 "compiler.y"
    {
		(yyval.var_dec_list) = new std::vector<VariableDecAST*>();
		(yyval.var_dec_list)->push_back((yyvsp[(1) - (2)].var_dec));
	}
    break;

  case 81:
#line 304 "compiler.y"
    { (yyvsp[(1) - (3)].var_dec_list)->push_back((yyvsp[(2) - (3)].var_dec)); }
    break;

  case 82:
#line 309 "compiler.y"
    { (yyval.statement_list) = new std::vector<AST*>(); (yyval.statement_list)->push_back((yyvsp[(1) - (1)].statement)); }
    break;

  case 83:
#line 310 "compiler.y"
    { (yyvsp[(1) - (2)].statement_list)->push_back((yyvsp[(2) - (2)].statement)); }
    break;

  case 84:
#line 315 "compiler.y"
    { (yyval.block) = nullptr; }
    break;

  case 85:
#line 316 "compiler.y"
    { (yyval.block) = new BlockAST(); (yyval.block)->addAST((yyvsp[(1) - (2)].expression)); }
    break;

  case 86:
#line 321 "compiler.y"
    {
		BlockAST* stmt_block = new BlockAST();
		stmt_block->addAST((yyvsp[(5) - (5)].statement));
		(yyval.statement) = new IfExpAST((yyvsp[(3) - (5)].expression), stmt_block, nullptr);
	}
    break;

  case 87:
#line 326 "compiler.y"
    {
		BlockAST* if_stmt_block = new BlockAST();
		if_stmt_block->addAST((yyvsp[(5) - (7)].statement));
		BlockAST* else_stmt_block = new BlockAST();
		else_stmt_block->addAST((yyvsp[(5) - (7)].statement));
		(yyval.statement) = new IfExpAST((yyvsp[(3) - (7)].expression), if_stmt_block, else_stmt_block);
	}
    break;

  case 88:
#line 337 "compiler.y"
    {
		BlockAST* stmt_block = new BlockAST();
		stmt_block->addAST((yyvsp[(5) - (5)].statement));
		(yyval.statement) = new WhileExpAST((yyvsp[(3) - (5)].expression), stmt_block);
	}
    break;

  case 89:
#line 342 "compiler.y"
    {
		BlockAST* stmt_block = new BlockAST();
		stmt_block->addAST((yyvsp[(8) - (8)].statement));
		(yyval.statement) = new ForExpAST((yyvsp[(3) - (8)].expression), (yyvsp[(5) - (8)].expression), nullptr, stmt_block);
	}
    break;

  case 90:
#line 347 "compiler.y"
    {
		BlockAST* stmt_block = new BlockAST();
		stmt_block->addAST((yyvsp[(9) - (9)].statement));
		(yyval.statement) = new ForExpAST((yyvsp[(3) - (9)].expression), (yyvsp[(5) - (9)].expression), (yyvsp[(7) - (9)].expression), stmt_block);
	}
    break;

  case 91:
#line 356 "compiler.y"
    { }
    break;

  case 92:
#line 357 "compiler.y"
    { }
    break;

  case 93:
#line 358 "compiler.y"
    { (yyval.statement) = new ReturnExpAST(); }
    break;

  case 94:
#line 359 "compiler.y"
    { (yyval.statement) = new ReturnExpAST((yyvsp[(2) - (3)].expression)); }
    break;


/* Line 1267 of yacc.c.  */
#line 2170 "y.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 362 "compiler.y"


void yyerror(const char *s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}

// int main(int argc,char* argv[]) {
// 	yyin = fopen(argv[1],"r");
	
// 	yyparse();
// 	printf("\n");

// 	fclose(yyin);
// 	return 0;
// }
