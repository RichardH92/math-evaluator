#pragma once
#include "Token.h"
class Lexical_Analyzer
{
private:
	char *in_str;
	int len;
	int curr_pos;
	int peek_pos;

	bool is_cos();
	bool is_sin();
	bool is_tan();
	bool is_lparen();
	bool is_rparen();
	bool is_sub();
	bool is_add();
	bool is_mult();
	bool is_div();
	bool is_space();
	bool is_exp();
	bool is_ln();
	bool is_constant();
	bool is_variable();

public:
	Lexical_Analyzer(char *p_str);
	~Lexical_Analyzer();
	Token Peek_Token();
	void Consume_Token();
};

