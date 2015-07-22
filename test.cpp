#include "Math_Parser.h"
#include "Lexical_Analyzer.h"
#include <iostream>
#include "Token.h"
#include "Compound_Expression.h"
#include "Sin_Func.h"
#include "Cos_Func.h"
#include "Tan_Func.h"
#include "Ln_Func.h"
#include "Exp_Func.h"
#include "Lex_Exception.h"
#include "Parse_Exception.h"

static void test_cos_token();
static void test_sin_token();
static void test_tan_token();
static void test_exp_token();
static void test_ln_token();
static void test_mult_token();
static void test_sub_token();
static void test_add_token();
static void test_div_token();
static void test_space_ignored();
static void test_constant_int_token();
static void test_variable_token_all_letters();
static void test_multiple_tokens();

static void test_end_of_tokens();
static void test_invalid_token_fails();

static void test_single_constant();
static void test_single_variable();
static void test_mult_expr();
static void test_sub_expr();
static void test_add_expr();
static void test_div_expr();
static void test_paren_expr();
static void test_compound_expr();
static void test_sin_func();
static void test_cos_func();
static void test_tan_func();
static void test_exp_func();
static void test_ln_func();
static void test_long_expr_toString();

static void test_no_matching_parens_fails();
static void test_parens_no_expr_fails();
static void test_sin_no_parens_fails();
static void test_sin_no_expr_fails();
static void test_cos_no_parens_fails();
static void test_cos_no_expr_fails();
static void test_tan_no_parens_fails();
static void test_tan_no_expr_fails();
static void test_exp_no_parens_fails();
static void test_exp_no_expr_fails();
static void test_ln_no_parens_fails();
static void test_ln_no_expr_fails();

int total = 0;
int passed = 0;

int main() {
	test_cos_token();
	test_sin_token();
	test_tan_token();
	test_exp_token();
	test_ln_token();
	test_mult_token();
	test_sub_token();
	test_add_token();
	test_div_token();
	test_space_ignored();
	test_constant_int_token();
	test_variable_token_all_letters();
	test_multiple_tokens();

	test_end_of_tokens();
	test_invalid_token_fails();

	test_single_constant();
	test_single_variable();
	test_mult_expr();
	test_div_expr();
	test_add_expr();
	test_sub_expr();
	test_paren_expr();
	test_compound_expr();

	test_sin_func();
	test_cos_func();
	test_tan_func();
	test_exp_func();
	test_ln_func();

	test_long_expr_toString();

	test_no_matching_parens_fails();
	test_parens_no_expr_fails();
	test_sin_no_parens_fails();
	test_sin_no_expr_fails();
	test_cos_no_parens_fails();
	test_cos_no_expr_fails();
	test_tan_no_parens_fails();
	test_tan_no_expr_fails();
	test_exp_no_parens_fails();
	test_exp_no_expr_fails();
	test_ln_no_parens_fails();
	test_ln_no_expr_fails();

	cout << "\r\nPassed tests: " << passed << "/" << total << ".\r\n";

	char test;
	cin >> test;
}

static void test_cos_token() {
	total++;

	char c_str[100] = "cos";

	cout << "test_cos_token:\t\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == COS) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_sin_token() {
	total++;

	char c_str[100] = "sin";

	cout << "test_sin_token:\t\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == SIN) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_tan_token() {
	total++;
	char c_str[100] = "tan";

	cout << "test_tan_token:\t\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == TAN) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_exp_token() {
	char c_str[100] = "^";
	total++;

	cout << "test_exp_token:\t\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == EXP) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_mult_token() {
	char c_str[100] = "*";
	total++;

	cout << "test_mult_token:\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == MULT) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_sub_token() {
	char c_str[100] = "-";
	total++;

	cout << "test_sub_token:\t\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == SUB) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_add_token() {
	char c_str[100] = "+";
	total++;

	cout << "test_add_token:\t\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == ADD) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_div_token() {
	char c_str[100] = "/";
	total++;

	cout << "test_div_token:\t\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == DIV) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_ln_token() {
	char c_str[100] = "ln";
	total++;

	cout << "test_ln_token:\t\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == LN) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_space_ignored() {
	char c_str[100] = "      ln";
	total++;

	cout << "test_space_ignored:\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t == LN) {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_variable_token_all_letters() {
	char c_str[100] = "abcdef";
	total++;

	cout << "test_variable_token_all_letters:\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t.isVariable() && t.t_str == "abcdef") {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_invalid_token_fails() {
	char c_str[100] = "@";
	total++;

	cout << "test_invalid_token_fails:\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);

	try {
		Token t = lex->Peek_Token();
	}
	catch (Lex_Exception *e) {
		passed++;
		cout << "PASS\r\n";
		delete lex;
		delete e;
		return;
	}

	cout << "FAIL\r\n";
	delete lex;
	return;
}

static void test_constant_int_token() {
	char c_str[100] = "12345";
	total++;

	cout << "test_constant_int_token:\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (t.isConstant() && t.t_str == "12345") {
		cout << "PASS";
		passed++;
	}
	else
		cout << "FAIL";

	cout << "\r\n";

	delete lex;
}

static void test_multiple_tokens() {
	char c_str[100] = "4ln(";
	total++;

	cout << "test_multiple_tokens:\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);
	Token t = lex->Peek_Token();

	if (!t.isConstant() || t != "4") {
		cout << "FAIL\r\n";
		delete lex;
		return;
	}

	lex->Consume_Token();
	t = lex->Peek_Token();

	if (t != LN) {
		cout << "FAIL\r\n";
		delete lex;
		return;
	}

	lex->Consume_Token();
	t = lex->Peek_Token();

	if (t != LPAREN) {
		cout << "FAIL\r\n";
		delete lex;
		return;
	}

	cout << "PASS\r\n";
	passed++;

	delete lex;
}

static void test_end_of_tokens() {
	char c_str[100] = "4ln(";
	total++;

	cout << "test_end_of_tokens:\t\t\t";

	Lexical_Analyzer *lex = new Lexical_Analyzer(c_str);

	lex->Consume_Token();
	lex->Consume_Token();
	lex->Consume_Token();
	Token t = lex->Peek_Token();

	if (t == END) {
		cout << "PASS\r\n";
		passed++;
	}
	else
		cout << "FAIL\r\n";

	delete lex;
}

static void test_single_constant() {
	char c_str[100] = "4";
	total++;

	cout << "test_single_constant:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (Term_Expr *t = dynamic_cast<Term_Expr *>(e)) {
		if (Constant *c = dynamic_cast<Constant *>(t->LHS)) {
			if (c->getValue() == 4 && t->RHS == NULL && c->toString() == "4") {
				cout << "PASS\r\n";
				passed++;
				delete p;
				delete e;
				return;
			}
		}
	}

	cout << "FAIL\r\n";

	delete p;
	delete e;
}

static void test_single_variable() {
	char c_str[100] = "x";
	total++;

	cout << "test_single_variable:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (Term_Expr *t = dynamic_cast<Term_Expr *>(e)) {
		if (Variable *v = dynamic_cast<Variable *>(t->LHS)) {
			if (v->toString() == "x" && t->RHS == NULL) {
				cout << "PASS\r\n";
				passed++;
				delete p;
				delete e;
				return;
			}
		}
	}

	cout << "FAIL\r\n";

	delete p;
	delete e;
}

static void test_mult_expr() {
	char c_str[100] = "4 * x";
	total++;

	cout << "test_mult_expr:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);
	
	if (!dynamic_cast<Constant *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Constant *c = dynamic_cast<Constant *>(t->LHS);

	if (c->getValue() != 4 || !dynamic_cast<Mult_Expr *>(t->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Mult_Expr *m = dynamic_cast<Mult_Expr *>(t->RHS);

	if (!dynamic_cast<Term_Expr *>(m->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(m->RHS);

	if (!dynamic_cast<Variable *>(t->LHS) || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "4 * x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}
	
	passed++;
	cout << "PASS\r\n";
	delete p;
	delete e;
	return;
}

static void test_div_expr() {
	char c_str[100] = "4 / x";
	total++;

	cout << "test_div_expr:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);

	if (!dynamic_cast<Constant *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Constant *c = dynamic_cast<Constant *>(t->LHS);

	if (c->getValue() != 4 || !dynamic_cast<Div_Expr *>(t->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Div_Expr *m = dynamic_cast<Div_Expr *>(t->RHS);

	if (!dynamic_cast<Term_Expr *>(m->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(m->RHS);

	if (!dynamic_cast<Variable *>(t->LHS) || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "4 / x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_add_expr() {
	char c_str[100] = "4 + x";
	total++;

	cout << "test_add_expr:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);

	if (!dynamic_cast<Constant *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Constant *c = dynamic_cast<Constant *>(t->LHS);

	if (c->getValue() != 4 || !dynamic_cast<Add_Expr *>(t->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Add_Expr *m = dynamic_cast<Add_Expr *>(t->RHS);

	if (!dynamic_cast<Term_Expr *>(m->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(m->RHS);

	if (!dynamic_cast<Variable *>(t->LHS) || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "4 + x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_sub_expr() {
	char c_str[100] = "4 - x";
	total++;

	cout << "test_sub_expr:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);

	if (!dynamic_cast<Constant *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Constant *c = dynamic_cast<Constant *>(t->LHS);

	if (c->getValue() != 4 || !dynamic_cast<Sub_Expr *>(t->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Sub_Expr *m = dynamic_cast<Sub_Expr *>(t->RHS);

	if (!dynamic_cast<Term_Expr *>(m->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(m->RHS);

	if (!dynamic_cast<Variable *>(t->LHS) || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "4 - x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_paren_expr() {
	char c_str[100] = "(x)";
	total++;

	cout << "test_paren_expr:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Paren_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Paren_Expr *par = dynamic_cast<Paren_Expr *>(e);

	if (!dynamic_cast<Term_Expr *>(par->expr)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(par->expr);

	if (!dynamic_cast<Variable *>(t->LHS) || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "(x)") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_compound_expr() {
	char c_str[100] = "(4 * x) / 4";
	total++;

	cout << "test_compound_expr:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Compound_Expression *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "(4 * x) / 4") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_sin_func() {
	char c_str[100] = "sin(x)";
	total++;

	cout << "test_sin_func:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);

	if (!dynamic_cast<Sin_Func *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Sin_Func *s = dynamic_cast<Sin_Func *>(t->LHS);

	if (!dynamic_cast<Term_Expr *>(s->expr)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(s->expr);

	if (!dynamic_cast<Variable *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x" || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "sin(x)") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_cos_func() {
	char c_str[100] = "cos(x)";
	total++;

	cout << "test_cos_func:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);

	if (!dynamic_cast<Cos_Func *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Cos_Func *s = dynamic_cast<Cos_Func *>(t->LHS);

	if (!dynamic_cast<Term_Expr *>(s->expr)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(s->expr);

	if (!dynamic_cast<Variable *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x" || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "cos(x)") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_tan_func() {
	char c_str[100] = "tan(x)";
	total++;

	cout << "test_tan_func:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);

	if (!dynamic_cast<Tan_Func *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Tan_Func *s = dynamic_cast<Tan_Func *>(t->LHS);

	if (!dynamic_cast<Term_Expr *>(s->expr)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(s->expr);

	if (!dynamic_cast<Variable *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x" || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "tan(x)") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_exp_func() {
	char c_str[100] = "4^(x)";
	total++;

	cout << "test_exp_func:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);

	if (!dynamic_cast<Term_Expr *>(t->RHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(t->RHS);

	if (!dynamic_cast<Exp_Func *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Exp_Func *s = dynamic_cast<Exp_Func *>(t->LHS);

	if (!dynamic_cast<Term_Expr *>(s->expr)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(s->expr);

	if (!dynamic_cast<Variable *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x" || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "4^(x)") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	cout << "PASS\r\n";
	passed++;
	delete p;
	delete e;
	return;
}

static void test_ln_func() {
	char c_str[100] = "ln(x)";
	total++;

	cout << "test_ln_func:\t\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (!dynamic_cast<Term_Expr *>(e)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Term_Expr *t = dynamic_cast<Term_Expr *>(e);

	if (!dynamic_cast<Ln_Func *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Ln_Func *s = dynamic_cast<Ln_Func *>(t->LHS);

	if (!dynamic_cast<Term_Expr *>(s->expr)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	t = dynamic_cast<Term_Expr *>(s->expr);

	if (!dynamic_cast<Variable *>(t->LHS)) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	Variable *v = dynamic_cast<Variable *>(t->LHS);

	if (v->toString() != "x" || t->RHS != NULL) {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	if (e->toString() != "ln(x)") {
		cout << "FAIL\r\n";
		delete p;
		delete e;
		return;
	}

	passed++;
	cout << "PASS\r\n";
	delete p;
	delete e;
	return;
}

static void test_long_expr_toString() {
	char c_str[100] = "4cos(x) * x / sin(7 * 234 * y) * tan(56^(7 * x))";
	total++;

	cout << "test_long_expr_toString:\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = p->Parse_Expression();

	if (e->toString() != "4cos(x) * x / sin(7 * 234 * y) * tan(56^(7 * x))")
		cout << "FAIL\r\n";
	else {
		cout << "PASS\r\n";
		passed++;
	}

	delete p;
	delete e;
	return;
}

static void test_no_matching_parens_fails() {
	total++;
	char c_str[100] = "(x";

	cout << "test_no_matching_parens_fails:\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_parens_no_expr_fails() {
	total++;
	char c_str[100] = "()";

	cout << "test_parens_no_expr_fails:\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_sin_no_parens_fails() {
	total++;
	char c_str[100] = "sinx";

	cout << "test_sin_no_parens_fails:\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_sin_no_expr_fails() {
	total++;
	char c_str[100] = "sin()";

	cout << "test_sin_no_expr_fails:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_cos_no_parens_fails() {
	total++;
	char c_str[100] = "cosx";

	cout << "test_cos_no_parens_fails:\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_cos_no_expr_fails() {
	total++;
	char c_str[100] = "cos()";

	cout << "test_cos_no_expr_fails:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_tan_no_parens_fails() {
	total++;
	char c_str[100] = "tanx";

	cout << "test_tan_no_parens_fails:\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_tan_no_expr_fails() {
	total++;
	char c_str[100] = "tan()";

	cout << "test_tan_no_expr_fails:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_exp_no_parens_fails() {
	total++;
	char c_str[100] = "4^x";

	cout << "test_exp_no_parens_fails:\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_exp_no_expr_fails() {
	total++;
	char c_str[100] = "4^()";

	cout << "test_exp_no_expr_fails:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_ln_no_parens_fails() {
	total++;
	char c_str[100] = "ln^x";

	cout << "test_ln_no_parens_fails:\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

static void test_ln_no_expr_fails() {
	total++;
	char c_str[100] = "ln^()";

	cout << "test_ln_no_expr_fails:\t\t\t";

	Math_Parser *p = new Math_Parser(c_str);
	Expression *e = NULL;

	try {
		e = p->Parse_Expression();
	}
	catch (Parse_Exception *pe) {
		passed++;
		cout << "PASS\r\n";
		delete pe;

		if (e != NULL)
			delete e;

		delete p;
		return;
	}

	delete e;
	delete p;

	cout << "FAIL\r\n";
}

