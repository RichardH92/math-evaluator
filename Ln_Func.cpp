#include "Ln_Func.h"
#include <string>

using namespace std;

Ln_Func::Ln_Func()
{
}


Ln_Func::~Ln_Func()
{
}

string Ln_Func::toString() {
	return "ln(" + expr->toString() + ")";
}
