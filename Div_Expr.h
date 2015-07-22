#pragma once
#include "Expression.h"
class Div_Expr : public Expression
{
public:
	Expression *RHS;

	~Div_Expr();
	string toString();
};

