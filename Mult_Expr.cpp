#include "Mult_Expr.h"
#include <assert.h>

Mult_Expr::~Mult_Expr() {
	assert(RHS != NULL);

	delete RHS;
}

string Mult_Expr::toString() {
	assert(RHS != NULL);

	return " * " + RHS->toString();
}
