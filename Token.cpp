#include "Token.h"
#include <string>
#include <cstring>

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
