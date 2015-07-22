#include "Variable.h"
#include <string>

using namespace std;

Variable::Variable(string p_name) {
	name = p_name;
}

string Variable::toString() {
	return name;
}
