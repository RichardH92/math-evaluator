#pragma once
#include "Expression.h"
#include <string>
class Add_Expr : public Expression {

public:
	Expression *RHS;

	~Add_Expr();
	string toString();
};

