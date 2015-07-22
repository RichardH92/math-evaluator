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

using namespace std;

class Token
{
private:
	bool isVar;
	bool isC;
	string t_str;
public:
	bool isVariable();
	bool isConstant();
	string toString();
	bool operator==(char *str);
	bool operator!=(char *str);
};

