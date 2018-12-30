%{
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
%}
%union{
	BlockAST* block;
	ExpAST* expression;
	StmAST* statement;
	FunctionDefAST* function_def;
	FunctionDecAST* function_dec;
	IdentifierExpAST* identifier;
	FunctionCallAST* function_call;
	/* VariableDeclaration* var_dec; */
	std::string* name;
	int token;
	std::vector<std::pair<int,std::string>> *var_dec_list;
	std::vector<ExpAST*> *call_list;
	std::vector<AST*> *statement_list;
}

%token <name> IDENTIFIER CONSTANT CHAR_CONSTANT STRING_LITERAL
%token <token> CHAR INT VOID EXTERN CHAR_PTR INT_PTR VOID_PTR
%token <token> IF ELSE FOR WHILE CONTINUE BREAK RETURN
%token <token> RIGHT_SHIFT LEFT_SHIFT
%token <token> LOGIC_AND LOGIC_OR COM_LE COM_GE COM_EQ COM_NE
%token <token> SEMICOLON LBRACE RBRACE COMMA ASSIGN LPAREN RPAREN LBRACKET RBRACKET
%token <token> BIT_AND BIT_XOR BIT_OR BIT_NOT BIT_INVERSION MINUS PLUS MUL DIV MOD COM_L COM_G

%type <block> program translation_unit external_declaration compound_statement expression_statement
%type <statement> statement iteration_statement jump_statement selection_statement
%type <statement_list> statement_list
%type <function_def> function_definition
%type <function_dec> function_declaration
%type <var_dec> variable_declaration
%type <identifier> identifier
%type <var_dec_list> func_decl_arguments declaration_list
%type <token> type_specifier unary_operator
%type <expression> primary_expression postfix_expression unary_expression multiplicative_expression additive_expression shift_expression relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression expression 
%type <call_list> argument_expression_list

%start program

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%
program: translation_unit {programBlock = $1;}
	;

/*开始解析单元*/
translation_unit: external_declaration { $$ = new BlockAST(); $$->addAST($1); }
	| translation_unit external_declaration { $1->addAST($2); }
	;

/*外部声明，函数定义或声明*/
external_declaration: function_definition { $<function_def>$ = $1;}
	| function_declaration { $<function_dec>$ = $1; }
	| variable_declaration SEMICOLON { /*$<var_dec>$ = $1;*/ }
	;

/*变量声明*/
variable_declaration:
	type_specifier identifier{/* $$ = new VariableDeclaration($1, $2, nullptr); */}
	| type_specifier identifier ASSIGN expression{
		/* $$ = new VariableDeclaration($1, $2, $4); */
	}
	| type_specifier identifier LBRACKET CONSTANT RBRACKET{
		// $5 as the size
		/* $$ = new ArrayInitialization($1, $2, $4); */	
	}
	;

/*函数声明*/
function_declaration:
	EXTERN type_specifier identifier LPAREN func_decl_arguments RPAREN SEMICOLON{
		/* AS: extern int printf(char* format); */
		/* add a field to tell whether it is extern*/
		$$ = new FunctionDecAST();
		$$->setName($3->getName());
		$$->setType($2);
		for (auto p = $5->begin(); p != $5->end(); p++) {
			$$->addArg(p->first, p->second);
		}
	}
	;
/*函数定义*/
function_definition:
	type_specifier identifier LPAREN func_decl_arguments RPAREN compound_statement {
		/* AS: int func(int a, char b){...} */
		FunctionDecAST* func_dec = new FunctionDecAST();
		func_dec->setName($2->getName());
		func_dec->setType($1);
		for (auto p = $4->begin(); p != $4->end(); p++) {
			func_dec->addArg(p->first, p->second);
		}
		$$ = new FunctionDefAST(func_dec, $6);
	}
	;

/*函数声明的参数*/
func_decl_arguments:
	/* blank */ { $$ = new std::vector<std::pair<int,std::string>>();}
	| variable_declaration { /*$$ = new std::vector<std::pair<int,std::string>>(); $$->push_back($1);*/ }
	| func_decl_arguments COMMA variable_declaration { /*$1->push_back($3);*/ }
	;

/*调用函数参数列表*/
argument_expression_list:
	/* blank */{ /* $$ = new ExpressionList(); */ }
	| expression {
		//参数
		/* $$ = new ExpressionList(); 
		*  $$->push_back($1);
		*/
	}
	| argument_expression_list COMMA expression {
		//多个参数
		/* $1->push_back($3); */
	}
	;

/*基本表达式*/
primary_expression:
	identifier { /*标识符*/ $<identifier>$ = $1; }
	| CONSTANT { /*常数*/ $$ = new IntExpAST(atoi($1->c_str())); }
	| CHAR_CONSTANT { $$ = new CharExpAST((*$1)[0]); }
	| STRING_LITERAL {/*字符串常数*/
		/* $$ = new StringLiteral(*$1); */
    }
	| LPAREN expression RPAREN { $$ = $2; }
	;

/*后缀表达式*/
postfix_expression:
	primary_expression { $$ = $1; }
	| identifier LBRACKET expression RBRACKET { /*数组调用*/ /* $$ = new ArrayIndex(); ... */ }
	| identifier LPAREN argument_expression_list RPAREN {
        /*有参数的函数调用 (和定义一样，改为直接设置argument list) */
		FunctionCallAST* func_call = new FunctionCallAST($1->getName());
		for (auto p = $3->begin(); p != $3->end(); p++)
			func_call->addArg(*p);
		$<function_call>$ = func_call;
    }
	;

/*一元表达式*/
unary_expression:
	postfix_expression { $$ = $1; }
	| unary_operator unary_expression { /* $$ = new UnaryExp(); ... */ }
	;

/*单目运算符*/
unary_operator:
	PLUS { $$ = $1; }
	| MINUS { $$ = $1; }
	| BIT_INVERSION { $$ = $1; }
	| BIT_NOT { $$ = $1; }
	;

/*可乘表达式*/
multiplicative_expression:
	unary_expression { $$ = $1; }
	| multiplicative_expression MUL unary_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	| multiplicative_expression DIV unary_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	| multiplicative_expression MOD unary_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*可加表达式*/
additive_expression:
	multiplicative_expression { $$ = $1; }
	| additive_expression PLUS multiplicative_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	| additive_expression MINUS multiplicative_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*移位*/
shift_expression:
	additive_expression { $$ = $1; }
	| shift_expression LEFT_SHIFT additive_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	| shift_expression RIGHT_SHIFT additive_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*关系表达式*/
relational_expression:
	shift_expression { $$ = $1; }
	| relational_expression COM_L shift_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	| relational_expression COM_G shift_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	| relational_expression COM_LE shift_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	| relational_expression COM_GE shift_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*相等表达式*/
equality_expression:
	relational_expression { $$ = $1; }
	| equality_expression COM_EQ relational_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	| equality_expression COM_NE relational_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*与*/
and_expression:
	equality_expression { $$ = $1; }
	| and_expression BIT_AND equality_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*异或*/
exclusive_or_expression:
	and_expression { $$ = $1; }
	| exclusive_or_expression BIT_XOR and_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*或*/
inclusive_or_expression:
	exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression BIT_OR exclusive_or_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*逻辑与表达式*/
logical_and_expression:
	inclusive_or_expression { $$ = $1; }
	| logical_and_expression LOGIC_AND inclusive_or_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*逻辑或表达式*/
logical_or_expression:
	logical_and_expression { $$ = $1; }
	| logical_or_expression LOGIC_OR logical_and_expression { $$ = new BinaryOptExpAST($2, $1, $3); }
	;

/*赋值语句*/
expression:
	logical_or_expression { $$ = $1; }
	| unary_expression ASSIGN expression { /*$$ = new BinaryOptExpAST($2, $1, $3);*/ }
	;

/*类型规定*/
type_specifier:
	VOID { $$ = $1; }
	| CHAR { $$ = $1; }
	| INT { $$ = $1; }
	| VOID MUL { $$ = VOID_PTR; }
	| CHAR MUL { $$ = CHAR_PTR; }
	| INT MUL { $$ = INT_PTR; }
	;
/*标识符*/
identifier:
	IDENTIFIER  { $$ = new IdentifierExpAST(*$1); }
	;

/*声明*/
statement:
	compound_statement { $<block>$ = $1; }
	| expression_statement { $<block>$ = $1; }
	| selection_statement
	| iteration_statement
	| jump_statement { $$ = $1; }
	;

/*复合语句*/
compound_statement:
	LBRACE RBRACE { $$ = new BlockAST(); }
	| LBRACE statement_list RBRACE { 
		$$ = new BlockAST();
		for (auto p = $2->begin(); p != $2->end(); p++) $$->addAST(*p);	
	}
	| LBRACE declaration_list RBRACE {
		$$ = new BlockAST();
		// need VariableDeclaration
		// for (auto p = $1->begin(); p != $1->end(); p++) $$->addAST()
	}
	| LBRACE declaration_list statement_list RBRACE {
		$$ = new BlockAST();
		for (auto p = $3->begin(); p != $3->end(); p++) $$->addAST(*p);
	}
	;

/*声明部分*/
declaration_list:
	variable_declaration SEMICOLON{ /*$$ = $1;*/ }
	| declaration_list variable_declaration SEMICOLON{ /* $1->push_back($2); */ }
	;

/*语句部分*/
statement_list:
	statement { $$ = new std::vector<AST*>(); $$->push_back($1); }
	| statement_list statement { $1->push_back($2); }
	;

/*表达式语句*/
expression_statement:
	SEMICOLON { $$ = nullptr; }
	| expression SEMICOLON { $$ = new BlockAST(); $$->addAST($1); }
	;

/*条件语句*/
selection_statement:
	IF LPAREN expression RPAREN statement %prec LOWER_THAN_ELSE {
		BlockAST* stmt_block = new BlockAST();
		stmt_block->addAST($5);
		$$ = new IfExpAST($3, stmt_block, nullptr);
	}
	| IF LPAREN expression RPAREN statement ELSE statement {
		BlockAST* if_stmt_block = new BlockAST();
		if_stmt_block->addAST($5);
		BlockAST* else_stmt_block = new BlockAST();
		else_stmt_block->addAST($5);
		$$ = new IfExpAST($3, if_stmt_block, else_stmt_block);
	}
	;

/*循环语句*/
iteration_statement:
	WHILE LPAREN expression RPAREN statement {
		/* $$ = new WhileExpAST($3, $5); */
	}
	| FOR LPAREN expression SEMICOLON expression SEMICOLON RPAREN statement {
		BlockAST* stmt_block = new BlockAST();
		stmt_block->addAST($8);
		$$ = new ForExpAST($3, $5, nullptr, stmt_block);
	}
	| FOR LPAREN expression SEMICOLON expression SEMICOLON expression RPAREN statement {
		BlockAST* stmt_block = new BlockAST();
		stmt_block->addAST($9);
		$$ = new ForExpAST($3, $5, $7, stmt_block);
	}
	;

/*跳转指令*/
jump_statement:
	CONTINUE SEMICOLON { }
	| BREAK SEMICOLON { }
	| RETURN SEMICOLON { $$ = new ReturnExpAST(); }
	| RETURN expression SEMICOLON { $$ = new ReturnExpAST($2); }
	;

%%

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