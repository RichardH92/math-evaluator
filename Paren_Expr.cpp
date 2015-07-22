#include "Paren_Expr.h"
#include <assert.h>

Paren_Expr::~Paren_Expr() {
	assert(expr != NULL);

	delete expr;
}

string Paren_Expr::toString() {
	assert(expr != NULL);

	return "(" + expr->toString() + ")";
}
