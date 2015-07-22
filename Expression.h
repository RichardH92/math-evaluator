#pragma once
#include "Term.h"
#include <string>

using namespace std;

class Expression {
public:
	virtual ~Expression();	
	virtual double Evaluate();
	virtual Expression * Derive();
	virtual string toString();
};

