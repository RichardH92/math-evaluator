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
	double intpart;
	if (modf(value, &intpart) == 0.0) {
		int temp = (int)value;
		return to_string(temp);
	}

	return to_string(value);
}
