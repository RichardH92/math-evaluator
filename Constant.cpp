#include "Constant.h"
#include <string>

using namespace std;

Constant::Constant(double val) {
	value = val;
}

double Constant::getValue() {
	return value;
}

string Constant::toString() {
	return to_string(value);
}
