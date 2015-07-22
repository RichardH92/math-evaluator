#pragma once
#include "Expression.h"
#include "Add_Expr.h"
#include "Sub_Expr.h"
#include "Mult_Expr.h"
#include "Div_Expr.h"
#include "Term.h"
#include "Paren_Expr.h"
#include "Lexical_Analyzer.h"
#include "Term_Expr.h"
#include "Constant.h"
#include "Variable.h"
#include "Function.h"
#include <list>

class Math_Parser
{
private:
	Lexical_Analyzer *lexxer;
	list<Variable *> *var_list;
	Expression *root_ast;

	Add_Expr * Parse_Add_Expr();
	Sub_Expr * Parse_Sub_Expr();
	Mult_Expr * Parse_Mult_Expr();
	Div_Expr * Parse_Div_Expr();
	Paren_Expr * Parse_Paren_Expr();
	Term_Expr * Parse_Term_Expr();
	Term * Parse_Term();
	Function * Parse_Function();
	Function * Parse_Sin_Function();
	Function * Parse_Cos_Function();
	Function * Parse_Tan_Function();
	Function * Parse_Exp_Function();
	Function * Parse_Ln_Function();
	Constant * Parse_Constant();
	Variable * Parse_Variable();

public:
	Math_Parser(char *p_expression);
	~Math_Parser();
	Expression * Parse_Expression();
};

