#pragma once
#include "Expression.h"
#include "Term.h"

class Term_Expr : public Expression {

public:
	Term *LHS;
	Expression *RHS;

	~Term_Expr();
	string toString();
};

