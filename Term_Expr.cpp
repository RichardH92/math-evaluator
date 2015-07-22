#include "Term_Expr.h"
#include <string>
#include <assert.h>

Term_Expr::~Term_Expr() {
	assert(LHS != NULL);

	delete LHS;

	if (RHS != NULL)
		delete RHS;
}

string Term_Expr::toString() {
	assert(LHS != NULL);

	if (RHS != NULL)
		return LHS->toString() + RHS->toString();
	
	return LHS->toString();
}
