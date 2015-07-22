#include "Sub_Expr.h"
#include <string>
#include <assert.h>

Sub_Expr::~Sub_Expr() {
	delete RHS;
}

string Sub_Expr::toString() {
	assert(RHS != NULL);

	return " - " + RHS->toString();
}
