#pragma once
#include <exception>
#include <string>

using namespace std;

class Lex_Exception : public exception
{
private:
	string error_msg;

public:
	Lex_Exception(string p_error_msg);
};

