#pragma once
#include "Term.h"
#include <string>

using namespace std;

class Variable : public Term {
private:
	string name;

public:
	Variable(string p_name);
	string toString();
};

