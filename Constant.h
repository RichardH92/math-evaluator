#pragma once
#include "Term.h"
class Constant : public Term
{
private:
	double value;
public:
	Constant(double val);
	double getValue();
	string toString();
};

