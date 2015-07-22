#include "Token.h"
#include <string>
#include <cstring>
#include <assert.h>

using namespace std;

bool Token::operator==(char *str) {
	if (strcmp(t_str.c_str(), str) == 0)
		return true;

	return false;
}

bool Token::operator!=(char *str) {
	if (strcmp(t_str.c_str(), str) == 0)
		return false;

	return true;
}

bool Token::isVariable() {
	assert(!(isVar && isC));
	return isVar;
}

bool Token::isConstant() {
	assert(!(isVar && isC));
	return isC;
}

string Token::toString() {
	return t_str;
}
