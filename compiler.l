D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include "AST.h"
#include "y.tab.hpp"
#define SAVE_NAME yylval.name = new string(yytext)
#define SAVE_TOKEN(t) yylval.token = t
using namespace std;
int column = 0;
void count();
int check_type();
void comment();
%}

%%
"/*"			{ comment(); }
"//"[^\n]*      ;
"#"[^\n]*       ;

"if"			{ count(); SAVE_TOKEN(IF); return(IF); }
"else"			{ count(); SAVE_TOKEN(ELSE); return(ELSE); }
"for"			{ count(); SAVE_TOKEN(FOR); return(FOR); }
"while"			{ count(); SAVE_TOKEN(WHILE); return(WHILE); }
"break"			{ count(); SAVE_TOKEN(BREAK); return(BREAK); }
"continue"		{ count(); SAVE_TOKEN(CONTINUE); return(CONTINUE); }
"return"		{ count(); SAVE_TOKEN(RETURN); return(RETURN); }

"char"			{ count(); SAVE_TOKEN(CHAR); return(CHAR); }
"int"			{ count(); SAVE_TOKEN(INT); return(INT); }
"void"			{ count(); SAVE_TOKEN(VOID); return(VOID); }
"extern"        { count(); SAVE_TOKEN(EXTERN); return(EXTERN); }

{L}({L}|{D})*		{ count(); SAVE_NAME; return(check_type()); /*标识符*/}

{D}+{IS}?			{ count(); SAVE_NAME; return(CONSTANT); /*10进制*/}  
'(\\.|[^\\'])+'	{ count(); SAVE_NAME; return(CHAR_CONSTANT); /*字符*/}

L?\"(\\.|[^\\"])*\"	{ count(); SAVE_NAME; return(STRING_LITERAL); /*字符串*/}

">>"			{ count(); SAVE_TOKEN(RIGHT_SHIFT); return(RIGHT_SHIFT); }
"<<"			{ count(); SAVE_TOKEN(LEFT_SHIFT); return(LEFT_SHIFT); }

"&&"			{ count(); SAVE_TOKEN(LOGIC_AND); return(LOGIC_AND); }
"||"			{ count(); SAVE_TOKEN(LOGIC_OR); return(LOGIC_OR); }
"<="			{ count(); SAVE_TOKEN(COM_LE); return(COM_LE); }
">="			{ count(); SAVE_TOKEN(COM_GE); return(COM_GE); }
"=="			{ count(); SAVE_TOKEN(COM_EQ); return(COM_EQ); }
"!="			{ count(); SAVE_TOKEN(COM_NE); return(COM_NE); }

";"			    { count(); SAVE_TOKEN(SEMICOLON); return(SEMICOLON); }
"{"		        { count(); SAVE_TOKEN(LBRACE); return(LBRACE); }
"}"		        { count(); SAVE_TOKEN(RBRACE); return(RBRACE); }
","				{ count(); SAVE_TOKEN(COMMA); return(COMMA); }
"="				{ count(); SAVE_TOKEN(ASSIGN); return(ASSIGN); }
"("				{ count(); SAVE_TOKEN(LPAREN); return(LPAREN); }
")"				{ count(); SAVE_TOKEN(RPAREN); return(RPAREN); }
"["  			{ count(); SAVE_TOKEN(LBRACKET); return(LBRACKET); }
"]"	     		{ count(); SAVE_TOKEN(RBRACKET); return(RBRACKET); }

"&"			{ count(); SAVE_TOKEN(BIT_AND); return(BIT_AND); }
"^"			{ count(); SAVE_TOKEN(BIT_XOR); return(BIT_XOR); }
"|"			{ count(); SAVE_TOKEN(BIT_OR); return(BIT_OR); }
"!"			{ count(); SAVE_TOKEN(BIT_NOT); return(BIT_NOT); }
"~"			{ count(); SAVE_TOKEN(BIT_INVERSION); return(BIT_INVERSION); }
"-"			{ count(); SAVE_TOKEN(MINUS); return(MINUS); }
"+"			{ count(); SAVE_TOKEN(PLUS); return(PLUS); }
"*"			{ count(); SAVE_TOKEN(MUL); return(MUL); }
"/"			{ count(); SAVE_TOKEN(DIV); return(DIV); }
"%"			{ count(); SAVE_TOKEN(MOD); return(MOD); }
"<"			{ count(); SAVE_TOKEN(COM_L); return(COM_L); }
">"			{ count(); SAVE_TOKEN(COM_G); return(COM_G); }

[ \t\v\n\f]		{ count(); }
.			{ /* ignore bad characters */ }

%%

int yywrap()
{
	return 1;
}

void comment()
{
	column = 0;
	char c, prev = 0;
	
	while (cin >> c)      /* (EOF maps to 0) */
	{
		if (c == '/' && prev == '*')
			return;
		prev = c;
	}
	printf("unterminated comment");
}

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;

	ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

	return(IDENTIFIER);
}
