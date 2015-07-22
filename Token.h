#pragma once
#include <string>

#define ADD "+"
#define LPAREN "("
#define RPAREN ")"
#define SUB "-"
#define MULT "*"
#define DIV "/"
#define SPACE " "
#define COS "cos"
#define SIN "sin"
#define TAN "tan"
#define EXP "^"
#define LN "ln"
#define END "END"
#define NONE "NONE"

using namespace std;

class Token
{
public:
	bool isVar;
	bool isC;
	string t_str;

	bool isVariable();
	bool isConstant();
	string toString();
	bool operator==(char *str);
	bool operator!=(char *str);
};

