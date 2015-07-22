#pragma once
#include "Term.h"
#include <string>

using namespace std;

class Expression {
public:
	//virtual double Evaluate() = 0;
	//virtual Expression * Derive() = 0;
	virtual string toString() = 0;
};

