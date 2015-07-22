#pragma once
#include "Expression.h"
class Paren_Expr : public Expression {
public:
	Expression *expr;

	~Paren_Expr();
	string toString();
};

