#include "Sin_Func.h"


Sin_Func::Sin_Func() {

}


Sin_Func::~Sin_Func() {

}

string Sin_Func::toString() {
	return "sin(" + expr->toString() + ")";
}
