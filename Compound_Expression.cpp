#include "Compound_Expression.h"
#include <assert.h>

Compound_Expression::Compound_Expression(Expression *p_LHS, Expression *p_RHS) {
	assert(p_LHS != NULL);
	assert(p_RHS != NULL);

	LHS = p_LHS;
	RHS = p_RHS;
}

Compound_Expression::~Compound_Expression() {
	assert(LHS != NULL);
	assert(RHS != NULL);

	delete LHS;
	delete RHS;
}

string Compound_Expression::toString() {
	assert(LHS != NULL);
	assert(RHS != NULL);

	return LHS->toString() + RHS->toString();
}
