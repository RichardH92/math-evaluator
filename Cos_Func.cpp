#include "Cos_Func.h"
#include <string>

using namespace std;

Cos_Func::Cos_Func() {

}


Cos_Func::~Cos_Func() {

}

string Cos_Func::toString() {
	return "cos(" + expr->toString() + ")";
}
