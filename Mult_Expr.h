#pragma once
#include "Expression.h"
#include <string>

class Mult_Expr : public Expression {
public:
	Expression *RHS;

	~Mult_Expr();
	string toString();
};

