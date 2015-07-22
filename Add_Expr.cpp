#include "Add_Expr.h"
#include <assert.h>

Add_Expr::~Add_Expr() {
	assert(RHS != NULL);

	delete RHS;
}

string Add_Expr::toString() {
	assert(RHS != NULL);

	return " + " + RHS->toString();
}
