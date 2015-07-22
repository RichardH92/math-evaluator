#pragma once
#include "Token.h"
class Lexical_Analyzer
{
private:
	char *in_str;
	int len;

public:
	Lexical_Analyzer(char *p_str);
	~Lexical_Analyzer();
	Token Peek_Token();
	void Consume_Token();
};

