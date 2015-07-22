#pragma once
#include "Expression.h"
class Compound_Expression : public Expression
{
public:
	Expression *LHS;
	Expression *RHS;
	Compound_Expression(Expression *p_LHS, Expression *p_RHS);
	~Compound_Expression();
	string toString();
};

