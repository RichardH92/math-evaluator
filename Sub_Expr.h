#pragma once
#include "Expression.h"
class Sub_Expr : public Expression {
public:
	Expression *RHS;

	Sub_Expr();
	~Sub_Expr();
	string toString();
};

