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
#line 1 "compiler.y" /* yacc.c:339  */

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

#line 80 "y.tab.cpp" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.hpp".  */
#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "compiler.y" /* yacc.c:355  */

	BlockAST* block;
	ExpAST* expression;
	StmAST* statement;
	FunctionDefAST* function_def;
	FunctionDecAST* function_dec;
	IdentifierExpAST* identifier;
	FunctionCallAST* function_call;
	ArrayIndexAST* array_index;
	VariableDecAST* var_dec;
	GlobalVariableDecAST* glo_var_dec;
	std::string* name;
	int token;
	std::vector<VariableDecAST*> *var_dec_list;
	std::vector<ExpAST*> *call_list;
	std::vector<AST*> *statement_list;

#line 238 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 255 "y.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    58,    58,    62,    63,    67,    68,    69,    73,    74,
      77,    87,    88,    91,   102,   115,   129,   130,   131,   136,
     137,   142,   150,   151,   152,   164,   177,   182,   183,   189,
     200,   201,   206,   207,   208,   209,   214,   215,   216,   217,
     222,   223,   224,   229,   230,   231,   236,   237,   238,   239,
     240,   245,   246,   247,   252,   253,   258,   259,   264,   265,
     270,   271,   276,   277,   282,   283,   284,   293,   294,   295,
     296,   297,   298,   302,   307,   308,   309,   310,   311,   316,
     317,   321,   326,   335,   339,   344,   345,   350,   351,   358,
     363,   374,   379,   384,   393,   394,   395,   396
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "translation_unit", "external_declaration",
  "global_variable_declaration", "variable_declaration",
  "function_declaration", "function_definition", "func_decl_arguments",
  "argument_expression_list", "primary_expression", "postfix_expression",
  "unary_expression", "unary_operator", "multiplicative_expression",
  "additive_expression", "shift_expression", "relational_expression",
  "equality_expression", "and_expression", "exclusive_or_expression",
  "inclusive_or_expression", "logical_and_expression",
  "logical_or_expression", "expression", "type_specifier", "identifier",
  "statement", "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
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

#define YYPACT_NINF -113

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-113)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      52,   -42,   -40,   -35,   103,    20,    52,  -113,     1,  -113,
    -113,    31,  -113,  -113,  -113,    31,  -113,  -113,  -113,  -113,
     -18,     7,   228,   103,    48,   103,  -113,  -113,  -113,   228,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,   228,    68,     4,
      86,   -17,    89,    44,    59,    82,    77,   108,  -113,    50,
    -113,   -31,    31,    96,    60,   100,  -113,    54,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   103,
     111,    63,  -113,   118,  -113,   228,  -113,  -113,  -113,    68,
      68,     4,     4,    86,    86,    86,    86,   -17,   -17,    89,
      44,    59,    82,    77,  -113,    74,  -113,   115,  -113,   120,
    -113,   228,   148,  -113,   119,   228,  -113,   122,   123,   124,
     125,   131,   143,   213,  -113,  -113,   144,   145,  -113,  -113,
     162,     8,  -113,  -113,  -113,  -113,  -113,   138,  -113,  -113,
     228,   228,   228,   228,  -113,  -113,  -113,   154,  -113,  -113,
    -113,   159,   181,  -113,  -113,  -113,  -113,   142,   160,   155,
    -113,  -113,  -113,   111,   228,   111,   179,   173,  -113,   111,
     224,  -113,   111,   172,  -113,   111,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    68,    69,    67,     0,     0,     2,     3,     0,     6,
       5,     0,    71,    72,    70,     0,     1,     4,     7,    73,
       8,     0,     0,    16,     0,    16,    25,    23,    24,     0,
      35,    34,    33,    32,    27,    30,    36,     0,    40,    43,
      46,    51,    54,    56,    58,    60,    62,    64,     9,    22,
      17,     0,     0,     0,     0,     0,    31,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,     0,     0,
       0,    11,    10,     0,    26,     0,    37,    38,    39,    42,
      41,    45,    44,    49,    50,    47,    48,    52,    53,    55,
      57,    59,    61,    63,    65,     0,    20,     0,    18,     0,
      15,     0,     0,    14,     0,     0,    29,    28,     0,     0,
       0,     0,     0,     0,    87,    79,     0,     0,    85,    74,
       0,     0,    75,    76,    77,    78,    12,     0,    28,    21,
       0,     0,     0,     0,    94,    95,    96,     0,    83,    88,
      81,     0,     0,    80,    86,    13,    66,     0,     0,     0,
      97,    84,    82,     0,     0,     0,    89,     0,    91,     0,
       0,    90,     0,     0,    92,     0,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,   202,  -113,   -73,  -113,  -113,   184,  -113,
    -113,  -113,   -14,  -113,    69,    80,    37,    76,   149,   141,
     153,   140,   146,  -113,   -22,    29,     6,  -112,   -78,  -113,
     105,  -113,  -113,  -113,  -113
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    50,     9,    10,    51,   105,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   127,    52,    49,   128,   129,   130,
     131,   132,   133,   134,   135
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      48,    79,   110,    12,    80,    13,   108,    55,    65,    66,
      14,    19,    26,    27,    28,    22,    23,    20,    24,   154,
      16,    21,   118,    56,   119,   120,   121,   122,   123,    11,
      18,    67,    68,    15,    19,    11,   126,   124,   109,   153,
     154,    25,    29,    57,    86,    87,    88,    61,    62,    30,
      31,    32,    33,    53,   104,   106,   107,   151,    81,     1,
       2,     3,     4,   114,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    71,    76,    77,   166,    78,   168,    77,   136,
      85,   171,    79,   139,   174,    83,   111,   176,    72,   112,
      74,   147,    93,    94,    95,    96,   115,    63,    64,   116,
       1,     2,     3,    58,    59,    60,    69,    70,   156,   157,
     158,   159,    73,    19,    26,    27,    28,     1,     2,     3,
      89,    90,    75,    82,   118,    84,   119,   120,   121,   122,
     123,   109,   167,    91,    92,    97,    98,   113,   173,   124,
     109,   125,   117,   137,    29,   140,   138,   141,   142,   143,
     144,    30,    31,    32,    33,    19,    26,    27,    28,     1,
       2,     3,   145,   148,   149,   155,   118,   163,   119,   120,
     121,   122,   123,   160,    19,    26,    27,    28,   161,   164,
     165,   124,   109,   150,   169,   118,    29,   119,   120,   121,
     122,   123,   170,    30,    31,    32,    33,   175,    17,    54,
     124,   109,   162,   100,   102,    29,    19,    26,    27,    28,
      99,   103,    30,    31,    32,    33,   101,    19,    26,    27,
      28,    19,    26,    27,    28,   152,     0,     0,     0,     0,
       0,     0,   146,     0,     0,     0,     0,    29,     0,     0,
       0,     0,     0,     0,    30,    31,    32,    33,    29,   172,
       0,     0,    29,     0,     0,    30,    31,    32,    33,    30,
      31,    32,    33
};

static const yytype_int16 yycheck[] =
{
      22,    32,    80,    45,    35,    45,    79,    29,    25,    26,
      45,     3,     4,     5,     6,    33,    34,    11,    36,   131,
       0,    15,    14,    37,    16,    17,    18,    19,    20,     0,
      29,    48,    49,     4,     3,     6,   109,    29,    30,    31,
     152,    34,    34,    37,    58,    59,    60,    43,    44,    41,
      42,    43,    44,     5,    76,    77,    78,   130,    52,     7,
       8,     9,    10,    85,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    38,    33,    34,   163,    36,   165,    34,   111,
      36,   169,    32,   115,   172,    35,    33,   175,    39,    36,
      23,   123,    65,    66,    67,    68,    32,    21,    22,    35,
       7,     8,     9,    45,    46,    47,    27,    28,   140,   141,
     142,   143,    40,     3,     4,     5,     6,     7,     8,     9,
      61,    62,    24,    37,    14,    35,    16,    17,    18,    19,
      20,    30,   164,    63,    64,    69,    70,    29,   170,    29,
      30,    31,    37,     5,    34,    33,    37,    34,    34,    34,
      29,    41,    42,    43,    44,     3,     4,     5,     6,     7,
       8,     9,    29,    29,    29,    37,    14,    35,    16,    17,
      18,    19,    20,    29,     3,     4,     5,     6,    29,    29,
      35,    29,    30,    31,    15,    14,    34,    16,    17,    18,
      19,    20,    29,    41,    42,    43,    44,    35,     6,    25,
      29,    30,    31,    72,    74,    34,     3,     4,     5,     6,
      71,    75,    41,    42,    43,    44,    73,     3,     4,     5,
       6,     3,     4,     5,     6,   130,    -1,    -1,    -1,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    43,    44,    34,    35,
      -1,    -1,    34,    -1,    -1,    41,    42,    43,    44,    41,
      42,    43,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    52,    53,    54,    55,    57,
      58,    76,    45,    45,    45,    76,     0,    54,    29,     3,
      77,    77,    33,    34,    36,    34,     4,     5,     6,    34,
      41,    42,    43,    44,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    77,
      56,    59,    76,     5,    59,    75,    63,    77,    45,    46,
      47,    43,    44,    21,    22,    25,    26,    48,    49,    27,
      28,    38,    39,    40,    23,    24,    33,    34,    36,    32,
      35,    77,    37,    35,    35,    36,    63,    63,    63,    65,
      65,    66,    66,    67,    67,    67,    67,    68,    68,    69,
      70,    71,    72,    73,    75,    60,    75,    75,    56,    30,
      79,    33,    36,    29,    75,    32,    35,    37,    14,    16,
      17,    18,    19,    20,    29,    31,    56,    75,    78,    79,
      80,    81,    82,    83,    84,    85,    75,     5,    37,    75,
      33,    34,    34,    34,    29,    29,    29,    75,    29,    29,
      31,    56,    81,    31,    78,    37,    75,    75,    75,    75,
      29,    29,    31,    35,    29,    35,    79,    75,    79,    15,
      29,    79,    35,    75,    79,    35,    79
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    54,    55,    55,
      55,    56,    56,    56,    57,    58,    59,    59,    59,    60,
      60,    60,    61,    61,    61,    61,    61,    62,    62,    62,
      63,    63,    64,    64,    64,    64,    65,    65,    65,    65,
      66,    66,    66,    67,    67,    67,    68,    68,    68,    68,
      68,    69,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    75,    76,    76,    76,
      76,    76,    76,    77,    78,    78,    78,    78,    78,    79,
      79,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    84,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     2,     2,     4,
       5,     2,     4,     5,     7,     6,     0,     1,     3,     0,
       1,     3,     1,     1,     1,     1,     3,     1,     4,     4,
       1,     2,     1,     1,     1,     1,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     6,     1,     1,     1,
       2,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     3,     4,     2,     3,     1,     2,     1,     2,     5,
       7,     5,     8,     9,     2,     2,     2,     3
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
#line 58 "compiler.y" /* yacc.c:1646  */
    {programBlock = (yyvsp[0].block);}
#line 1486 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 62 "compiler.y" /* yacc.c:1646  */
    { (yyval.block) = new BlockAST(); (yyval.block)->addAST((yyvsp[0].block)); }
#line 1492 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 63 "compiler.y" /* yacc.c:1646  */
    { (yyvsp[-1].block)->addAST((yyvsp[0].block)); }
#line 1498 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 67 "compiler.y" /* yacc.c:1646  */
    { (yyval.function_def) = (yyvsp[0].function_def);}
#line 1504 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 68 "compiler.y" /* yacc.c:1646  */
    { (yyval.function_dec) = (yyvsp[0].function_dec); }
#line 1510 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 69 "compiler.y" /* yacc.c:1646  */
    { (yyval.glo_var_dec) = (yyvsp[-1].glo_var_dec); }
#line 1516 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 73 "compiler.y" /* yacc.c:1646  */
    { (yyval.glo_var_dec) = new GlobalVariableDecAST((yyvsp[-1].token), (yyvsp[0].identifier), nullptr); }
#line 1522 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 74 "compiler.y" /* yacc.c:1646  */
    {
		(yyval.glo_var_dec) = new GlobalVariableDecAST((yyvsp[-3].token), (yyvsp[-2].identifier), (yyvsp[0].expression));
	}
#line 1530 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 77 "compiler.y" /* yacc.c:1646  */
    {
		// array
		int length = atoi((yyvsp[-1].name)->c_str());
		if (length <= 0) yyerror("array length cannot be less than 0");
		(yyvsp[-3].identifier)->setToArray(length);
		(yyval.glo_var_dec) = new GlobalVariableDecAST((yyvsp[-4].token), (yyvsp[-3].identifier));
	}
#line 1542 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 87 "compiler.y" /* yacc.c:1646  */
    { (yyval.var_dec) = new VariableDecAST((yyvsp[-1].token), (yyvsp[0].identifier), nullptr); }
#line 1548 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 88 "compiler.y" /* yacc.c:1646  */
    {
		(yyval.var_dec) = new VariableDecAST((yyvsp[-3].token), (yyvsp[-2].identifier), (yyvsp[0].expression));
	}
#line 1556 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 91 "compiler.y" /* yacc.c:1646  */
    {
		// array
		int length = atoi((yyvsp[-1].name)->c_str());
		if (length <= 0) yyerror("array length cannot be less than 0");
		(yyvsp[-3].identifier)->setToArray(length);
		(yyval.var_dec) = new VariableDecAST((yyvsp[-4].token), (yyvsp[-3].identifier));
	}
#line 1568 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 102 "compiler.y" /* yacc.c:1646  */
    {
		/* AS: extern int printf(char* format); */
		/* add a field to tell whether it is extern*/
		(yyval.function_dec) = new FunctionDecAST();
		(yyval.function_dec)->setName((yyvsp[-4].identifier)->getName());
		(yyval.function_dec)->setType((yyvsp[-5].token));
		for (auto p = (yyvsp[-2].var_dec_list)->begin(); p != (yyvsp[-2].var_dec_list)->end(); p++) {
			(yyval.function_dec)->addArg((*p)->type, (*p)->lhs->name);
		}
	}
#line 1583 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 115 "compiler.y" /* yacc.c:1646  */
    {
		/* AS: int func(int a, char b){...} */
		FunctionDecAST* func_dec = new FunctionDecAST();
		func_dec->setName((yyvsp[-4].identifier)->getName());
		func_dec->setType((yyvsp[-5].token));
		for (auto p = (yyvsp[-2].var_dec_list)->begin(); p != (yyvsp[-2].var_dec_list)->end(); p++) {
			func_dec->addArg((*p)->type, (*p)->lhs->name);
		}
		(yyval.function_def) = new FunctionDefAST(func_dec, (yyvsp[0].block));
	}
#line 1598 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 129 "compiler.y" /* yacc.c:1646  */
    { (yyval.var_dec_list) = new std::vector<VariableDecAST*>();}
#line 1604 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 130 "compiler.y" /* yacc.c:1646  */
    { (yyval.var_dec_list) = new std::vector<VariableDecAST*>(); (yyval.var_dec_list)->push_back((yyvsp[0].var_dec)); }
#line 1610 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 131 "compiler.y" /* yacc.c:1646  */
    { (yyvsp[-2].var_dec_list)->push_back((yyvsp[0].var_dec)); }
#line 1616 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 136 "compiler.y" /* yacc.c:1646  */
    { (yyval.call_list) = new std::vector<ExpAST*>(); }
#line 1622 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 137 "compiler.y" /* yacc.c:1646  */
    {
		//参数
		(yyval.call_list) = new std::vector<ExpAST*>(); 
		(yyval.call_list)->push_back((yyvsp[0].expression));
	}
#line 1632 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 142 "compiler.y" /* yacc.c:1646  */
    {
		//多个参数
		(yyvsp[-2].call_list)->push_back((yyvsp[0].expression));
	}
#line 1641 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 150 "compiler.y" /* yacc.c:1646  */
    { /*标识符*/ (yyval.identifier) = (yyvsp[0].identifier); }
#line 1647 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 151 "compiler.y" /* yacc.c:1646  */
    { /*常数*/ (yyval.expression) = new IntExpAST(atoi((yyvsp[0].name)->c_str())); }
#line 1653 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "compiler.y" /* yacc.c:1646  */
    {
		char result;
		std::string number_str;
		int length = (*(yyvsp[0].name)).size();
		int status = 0;
		if ((*(yyvsp[0].name))[1] == '\\') {
			for (int i = 2; i < length && (*(yyvsp[0].name))[i] != '\''; i++)
				number_str.push_back((*(yyvsp[0].name))[i]);
			(yyval.expression) = new CharExpAST((char)atoi(number_str.c_str()));
		}
		else (yyval.expression) = new CharExpAST((*(yyvsp[0].name))[1]);
	}
#line 1670 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 164 "compiler.y" /* yacc.c:1646  */
    {/*字符串常数*/
		std::string result;
		int length = (*(yyvsp[0].name)).size();
		int start = 0;
		for (int i = 0; i < length; i++){
			if (start == 0 && (*(yyvsp[0].name))[i] == '"') start = 1;
			else if (start == 1 && (*(yyvsp[0].name))[i] == '"') break;
			else if (start == 1){
				result.push_back((*(yyvsp[0].name))[i]);
			}
		}
		(yyval.expression) = new StringLiteralExpAST(result);
    }
#line 1688 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 177 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[-1].expression); }
#line 1694 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 182 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1700 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 183 "compiler.y" /* yacc.c:1646  */
    { 
		/*数组调用*/
		(yyvsp[-3].identifier)->setToArray(0);
		ArrayIndexAST* arrayIndex = new ArrayIndexAST((yyvsp[-3].identifier), (yyvsp[-1].expression));
		(yyval.array_index) = arrayIndex;
	}
#line 1711 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 189 "compiler.y" /* yacc.c:1646  */
    {
        /*有参数的函数调用 (和定义一样，改为直接设置argument list) */
		FunctionCallAST* func_call = new FunctionCallAST((yyvsp[-3].identifier)->getName());
		for (auto p = (yyvsp[-1].call_list)->begin(); p != (yyvsp[-1].call_list)->end(); p++)
			func_call->addArg(*p);
		(yyval.function_call) = func_call;
    }
#line 1723 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 200 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1729 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 201 "compiler.y" /* yacc.c:1646  */
    { /* $$ = new UnaryExp(); ... */ }
#line 1735 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 206 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1741 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 207 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1747 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 208 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1753 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 209 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1759 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 214 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1765 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 215 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1771 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 216 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1777 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 217 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1783 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 222 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1789 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 223 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1795 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 224 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1801 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 229 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1807 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 230 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1813 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 231 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1819 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 236 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1825 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 237 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1831 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 238 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1837 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 239 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1843 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 240 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1849 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 245 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1855 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 246 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1861 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 247 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1867 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 252 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1873 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 253 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1879 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 258 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1885 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 259 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1891 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 264 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1897 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 265 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1903 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 270 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1909 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 271 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1915 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 276 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1921 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 277 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new BinaryOptExpAST((yyvsp[-1].token), (yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1927 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 282 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 1933 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 283 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = new VariableAssignAST((yyvsp[-2].identifier), (yyvsp[0].expression)); }
#line 1939 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 284 "compiler.y" /* yacc.c:1646  */
    {
		(yyvsp[-5].identifier)->setToArray(0);
		ArrayIndexAST* arrayIndex = new ArrayIndexAST((yyvsp[-5].identifier), (yyvsp[-3].expression));
		(yyval.expression) = new ArrayAssignAST(arrayIndex, (yyvsp[0].expression));
	}
#line 1949 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 293 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1955 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 294 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1961 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 295 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1967 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 296 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = VOID_PTR; }
#line 1973 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 297 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = CHAR_PTR; }
#line 1979 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 298 "compiler.y" /* yacc.c:1646  */
    { (yyval.token) = INT_PTR; }
#line 1985 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 302 "compiler.y" /* yacc.c:1646  */
    { (yyval.identifier) = new IdentifierExpAST(*(yyvsp[0].name)); }
#line 1991 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 307 "compiler.y" /* yacc.c:1646  */
    { (yyval.block) = (yyvsp[0].block); }
#line 1997 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 308 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = (yyvsp[0].expression); }
#line 2003 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 311 "compiler.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2009 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 316 "compiler.y" /* yacc.c:1646  */
    { (yyval.block) = new BlockAST(); }
#line 2015 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 317 "compiler.y" /* yacc.c:1646  */
    { 
		(yyval.block) = new BlockAST();
		for (auto p = (yyvsp[-1].statement_list)->begin(); p != (yyvsp[-1].statement_list)->end(); p++) (yyval.block)->addAST(*p);	
	}
#line 2024 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 321 "compiler.y" /* yacc.c:1646  */
    {
		(yyval.block) = new BlockAST();
		// need VariableDeclaration
		for (auto p = (yyvsp[-1].var_dec_list)->begin(); p != (yyvsp[-1].var_dec_list)->end(); p++) (yyval.block)->addAST(*p);
	}
#line 2034 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 326 "compiler.y" /* yacc.c:1646  */
    {
		(yyval.block) = new BlockAST();
		for (auto p = (yyvsp[-2].var_dec_list)->begin(); p != (yyvsp[-2].var_dec_list)->end(); p++) (yyval.block)->addAST(*p);
		for (auto p = (yyvsp[-1].statement_list)->begin(); p != (yyvsp[-1].statement_list)->end(); p++) (yyval.block)->addAST(*p);
	}
#line 2044 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 335 "compiler.y" /* yacc.c:1646  */
    {
		(yyval.var_dec_list) = new std::vector<VariableDecAST*>();
		(yyval.var_dec_list)->push_back((yyvsp[-1].var_dec));
	}
#line 2053 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 339 "compiler.y" /* yacc.c:1646  */
    { (yyvsp[-2].var_dec_list)->push_back((yyvsp[-1].var_dec)); }
#line 2059 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 344 "compiler.y" /* yacc.c:1646  */
    { (yyval.statement_list) = new std::vector<AST*>(); (yyval.statement_list)->push_back((yyvsp[0].statement)); }
#line 2065 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 345 "compiler.y" /* yacc.c:1646  */
    { (yyvsp[-1].statement_list)->push_back((yyvsp[0].statement)); }
#line 2071 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 350 "compiler.y" /* yacc.c:1646  */
    { (yyval.expression) = nullptr; }
#line 2077 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 351 "compiler.y" /* yacc.c:1646  */
    { /*$$ = new BlockAST(); $$->addAST($1);*/
		(yyval.expression) = (yyvsp[-1].expression);
	}
#line 2085 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 358 "compiler.y" /* yacc.c:1646  */
    {
		// BlockAST* stmt_block = new BlockAST();
		// stmt_block->addAST($5);
		(yyval.statement) = new IfExpAST((yyvsp[-2].expression), (yyvsp[0].block), nullptr);
	}
#line 2095 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 363 "compiler.y" /* yacc.c:1646  */
    {
		// BlockAST* if_stmt_block = new BlockAST();
		// if_stmt_block->addAST($5);
		// BlockAST* else_stmt_block = new BlockAST();
		// else_stmt_block->addAST($7);
		(yyval.statement) = new IfExpAST((yyvsp[-4].expression), (yyvsp[-2].block), (yyvsp[0].block));
	}
#line 2107 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 374 "compiler.y" /* yacc.c:1646  */
    {
		// BlockAST* stmt_block = new BlockAST();
		// stmt_block->addAST($5);
		(yyval.statement) = new WhileExpAST((yyvsp[-2].expression), (yyvsp[0].block));
	}
#line 2117 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 379 "compiler.y" /* yacc.c:1646  */
    {
		// BlockAST* stmt_block = new BlockAST();
		// stmt_block->addAST($8);
		(yyval.statement) = new ForExpAST((yyvsp[-5].expression), (yyvsp[-3].expression), nullptr, (yyvsp[0].block));
	}
#line 2127 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 384 "compiler.y" /* yacc.c:1646  */
    {
		// BlockAST* stmt_block = new BlockAST();
		// stmt_block->addAST($9);
		(yyval.statement) = new ForExpAST((yyvsp[-6].expression), (yyvsp[-4].expression), (yyvsp[-2].expression), (yyvsp[0].block));
	}
#line 2137 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 393 "compiler.y" /* yacc.c:1646  */
    { }
#line 2143 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 394 "compiler.y" /* yacc.c:1646  */
    { }
#line 2149 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 395 "compiler.y" /* yacc.c:1646  */
    { (yyval.statement) = new ReturnExpAST(); }
#line 2155 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 396 "compiler.y" /* yacc.c:1646  */
    { (yyval.statement) = new ReturnExpAST((yyvsp[-1].expression)); }
#line 2161 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2165 "y.tab.cpp" /* yacc.c:1646  */
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
#line 399 "compiler.y" /* yacc.c:1906  */


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
