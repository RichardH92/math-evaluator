#include "Exp_Func.h"


Exp_Func::Exp_Func()
{
}


Exp_Func::~Exp_Func()
{
}

string Exp_Func::toString() {
	return "^(" + expr->toString() + ")";
}
