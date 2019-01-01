/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     CONSTANT = 259,
     CHAR_CONSTANT = 260,
     STRING_LITERAL = 261,
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
#define CONSTANT 259
#define CHAR_CONSTANT 260
#define STRING_LITERAL 261
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
	VariableDecAST* var_dec;
	std::string* name;
	int token;
	std::vector<VariableDecAST*> *var_dec_list;
	std::vector<ExpAST*> *call_list;
	std::vector<AST*> *statement_list;
}
/* Line 1529 of yacc.c.  */
#line 165 "y.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

