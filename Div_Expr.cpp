#include "Div_Expr.h"
#include <assert.h>

Div_Expr::~Div_Expr() {
	assert(RHS != NULL);

	delete RHS;
}

string Div_Expr::toString() {
	assert(RHS != NULL);

	return " / " + RHS->toString();
}
