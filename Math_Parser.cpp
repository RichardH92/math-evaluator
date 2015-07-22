#include "Math_Parser.h"
#include "Parse_Exception.h"
#include "Token.h"
#include "Lexical_Analyzer.h"
#include "Function.h"
#include "Term_Expr.h"
#include "Constant.h"
#include "Variable.h"
#include "Sin_Func.h"
#include "Cos_Func.h"
#include "Add_Expr.h"
#include "Sub_Expr.h"
#include "Paren_Expr.h"
#include "Mult_Expr.h"
#include "Div_Expr.h"
#include "Exp_Func.h"
#include "Ln_Func.h"
#include "Compound_Expression.h"
#include <assert.h>
#include "Tan_Func.h"
#include <cstdlib>

Math_Parser::Math_Parser(char *p_expression) {
	assert(p_expression != NULL);
	lexxer = new Lexical_Analyzer(p_expression);
	assert(lexxer != NULL);
	var_list = new list<Variable *>();
	assert(var_list != NULL);
}

Math_Parser::~Math_Parser() {
	assert(lexxer != NULL);
	delete lexxer;
	delete var_list;

	//if (root_ast != NULL)
	//	delete root_ast;
}

Expression * Math_Parser::Parse_Expression() {
	Expression *ret = NULL;

	if (((ret = Parse_Paren_Expr()) != NULL) || ((ret = Parse_Add_Expr()) != NULL) || ((ret = Parse_Sub_Expr()) != NULL)
		|| ((ret = Parse_Mult_Expr()) != NULL) || ((ret = Parse_Div_Expr()) != NULL) || ((ret = Parse_Term_Expr()) != NULL)) {

		Expression *RHS = Parse_Expression();
		if (RHS) {
			ret = new Compound_Expression(ret, RHS);
			assert(ret != NULL);
		}
	}

	root_ast = ret;
	return ret;
}

Term_Expr * Math_Parser::Parse_Term_Expr() {
	Term *t = Parse_Term();

	if (!t)
		return NULL;

	Term_Expr *ret = new Term_Expr();
	assert(ret != NULL);
	ret->LHS = t;
	ret->RHS = Parse_Expression();

	return ret;
}

Add_Expr * Math_Parser::Parse_Add_Expr() {
	if (lexxer->Peek_Token() != ADD)
		return NULL;

	lexxer->Consume_Token();
	Add_Expr *ret = new Add_Expr();
	assert(ret != NULL);

	if (!(ret->RHS = Parse_Expression()))
		throw new Parse_Exception("Expected expression.");

	return ret;
}

Sub_Expr * Math_Parser::Parse_Sub_Expr() {
	if (lexxer->Peek_Token() != SUB)
		return NULL;

	lexxer->Consume_Token();
	Sub_Expr *ret = new Sub_Expr();
	assert(ret != NULL);

	if (!(ret->RHS = Parse_Expression()))
		throw new Parse_Exception("Expected expression.");

	return ret;
}

Mult_Expr * Math_Parser::Parse_Mult_Expr() {
	if (lexxer->Peek_Token() != MULT)
		return NULL;

	lexxer->Consume_Token();
	Mult_Expr *ret = new Mult_Expr();
	assert(ret != NULL);

	if (!(ret->RHS = Parse_Expression()))
		throw new Parse_Exception("Expected expression.");

	return ret;
}

Div_Expr * Math_Parser::Parse_Div_Expr() {
	if (lexxer->Peek_Token() != DIV)
		return NULL;

	lexxer->Consume_Token();
	Div_Expr *ret = new Div_Expr();
	assert(ret != NULL);

	if (!(ret->RHS = Parse_Expression()))
		throw new Parse_Exception("Expected expression.");

	return ret;
}

Paren_Expr * Math_Parser::Parse_Paren_Expr() {
	if (lexxer->Peek_Token() != LPAREN)
		return NULL;

	lexxer->Consume_Token();
	Paren_Expr *ret = new Paren_Expr();
	assert(ret != NULL);
	
	if (!(ret->expr = Parse_Expression()))
		throw new Parse_Exception("Expected expression.");

	if (lexxer->Peek_Token() != RPAREN)
		throw new Parse_Exception("Expected right paren.");

	lexxer->Consume_Token();

	return ret;
}

Term * Math_Parser::Parse_Term() {
	Term * ret = NULL;

	if ((ret = Parse_Constant()))
		return ret;
	else if ((ret = Parse_Variable()))
		return ret;
	else
		ret = Parse_Function();

	return ret;
}

Function * Math_Parser::Parse_Function() {
	Function *ret;

	if ((ret = Parse_Sin_Function()))
		return ret;
	else if ((ret = Parse_Cos_Function()))
		return ret;
	else if ((ret = Parse_Tan_Function()))
		return ret;
	else if ((ret = Parse_Exp_Function()))
		return ret;
	else if ((ret = Parse_Ln_Function()))
		return ret;

	return NULL;
}

Function * Math_Parser::Parse_Sin_Function() {
	Function *ret = NULL;

	if (lexxer->Peek_Token() == SIN) {
		lexxer->Consume_Token();

		if (lexxer->Peek_Token() != LPAREN)
			throw new Parse_Exception("Expected left paren.");

		lexxer->Consume_Token();
		ret = new Sin_Func();
		assert(ret != NULL);

		if (!(ret->expr = Parse_Expression()))
			throw new Parse_Exception("Expected expression.");

		if (lexxer->Peek_Token() != RPAREN)
			throw new Parse_Exception("Expected right paren.");

		lexxer->Consume_Token();
	}

	return ret;
}

Function * Math_Parser::Parse_Cos_Function() {
	Function *ret = NULL;

	if (lexxer->Peek_Token() == COS) {
		lexxer->Consume_Token();

		if (lexxer->Peek_Token() != LPAREN)
			throw new Parse_Exception("Expected left paren.");

		lexxer->Consume_Token();
		ret = new Cos_Func();
		assert(ret != NULL);

		if (!(ret->expr = Parse_Expression()))
			throw new Parse_Exception("Expected expression.");

		if (lexxer->Peek_Token() != RPAREN)
			throw new Parse_Exception("Expected right paren.");

		lexxer->Consume_Token();
	}

	return ret;
}

Function * Math_Parser::Parse_Tan_Function() {
	Function *ret = NULL;

	if (lexxer->Peek_Token() == TAN) {
		lexxer->Consume_Token();

		if (lexxer->Peek_Token() != LPAREN)
			throw new Parse_Exception("Expected left paren.");

		lexxer->Consume_Token();
		ret = new Tan_Func();
		assert(ret != NULL);

		if (!(ret->expr = Parse_Expression()))
			throw new Parse_Exception("Expected expression.");

		if (lexxer->Peek_Token() != RPAREN)
			throw new Parse_Exception("Expected right paren.");

		lexxer->Consume_Token();
	}

	return ret;
}

Function * Math_Parser::Parse_Exp_Function() {
	Function *ret = NULL;

	if (lexxer->Peek_Token() == EXP) {
		lexxer->Consume_Token();

		if (lexxer->Peek_Token() != LPAREN)
			throw new Parse_Exception("Expected left paren.");

		lexxer->Consume_Token();
		ret = new Exp_Func();
		assert(ret != NULL);

		if (!(ret->expr = Parse_Expression()))
			throw new Parse_Exception("Expected expression.");

		if (lexxer->Peek_Token() != RPAREN)
			throw new Parse_Exception("Expected right paren.");
	}

	return ret;
}

Function * Math_Parser::Parse_Ln_Function() {
	Function *ret = NULL;

	if (lexxer->Peek_Token() == LN) {
		lexxer->Consume_Token();

		if (lexxer->Peek_Token() != LPAREN)
			throw new Parse_Exception("Expected left paren.");

		lexxer->Consume_Token();
		ret = new Ln_Func();
		assert(ret != NULL);

		if (!(ret->expr = Parse_Expression()))
			throw new Parse_Exception("Expected expression.");

		if (lexxer->Peek_Token() != RPAREN)
			throw new Parse_Exception("Expected right paren.");
	}

	return ret;
}

Constant * Math_Parser::Parse_Constant() {
	Constant *ret = NULL;
	Token t = lexxer->Peek_Token();

	if (t.isConstant()) {
		lexxer->Consume_Token();
		double val = atof(t.toString().c_str());
		ret = new Constant(val);
		assert(ret != NULL);
	}

	return ret;
}

Variable * Math_Parser::Parse_Variable() {
	Variable *ret = NULL;

	Token t = lexxer->Peek_Token();

	if (t.isVariable()) {
		lexxer->Consume_Token();
		ret = new Variable(t.toString());
		var_list->push_back(ret);
		assert(ret != NULL);
	}

	return ret;
}


