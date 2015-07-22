#include "Tan_Func.h"


Tan_Func::Tan_Func()
{
}


Tan_Func::~Tan_Func()
{
}

string Tan_Func::toString() {
	return "tan(" + expr->toString() + ")";
}
