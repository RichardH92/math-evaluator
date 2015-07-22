#pragma once
#include "Expression.h"
#include "Term.h"

class Function : public Term {

public:
	Expression *expr;
};

