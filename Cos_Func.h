#pragma once
#include "Function.h"
#include <string>

using namespace std;

class Cos_Func :
	public Function
{
public:
	Cos_Func();
	~Cos_Func();
	string toString();
};

