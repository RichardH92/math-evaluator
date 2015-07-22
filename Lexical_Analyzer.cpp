#include "Lexical_Analyzer.h"
#include "Lex_Exception.h"
#include <string>
#include <assert.h>
#include <malloc.h>
#include <cstring>

using namespace std;

Lexical_Analyzer::Lexical_Analyzer(char *p_str) {
	assert(p_str != NULL);

	len = strlen(p_str);
	in_str = (char *)malloc(sizeof(char) * (len + 1));

	if (in_str == NULL)
		throw new Lex_Exception("Could not allocate memory.");

	strcpy(in_str, p_str);
}

Lexical_Analyzer::~Lexical_Analyzer() {
	assert(in_str != NULL);

	free(in_str);
}

Token Lexical_Analyzer::Peek_Token() {
	Token t;
	t.isVar = false;
	t.isC = false;

	if (curr_pos == len)
		t.t_str = END;
	else if (is_cos())
		t.t_str = COS;
	else if (is_sin())
		t.t_str = SIN;
	else if (is_tan())
		t.t_str = TAN;
	else if (is_add())
		t.t_str = ADD;
	else if (is_sub())
		t.t_str = SUB;
	else if (is_mult())
		t.t_str = MULT;
	else if (is_div())
		t.t_str = DIV;
	else if (is_lparen())
		t.t_str = LPAREN;
	else if (is_rparen())
		t.t_str = RPAREN;
	else if (is_exp())
		t.t_str = EXP;
	else if (is_ln())
		t.t_str = LN;
	else if (is_space()) {
		curr_pos = peek_pos;
		return Peek_Token();
	}
	else if (is_constant()) {
		char temp[100];
		strncpy(temp, in_str + curr_pos, peek_pos - curr_pos);
		temp[peek_pos - curr_pos] = '\0';
		t.t_str = temp;
		t.isC = true;
	}
	else if (is_variable()) {
		char temp[100];
		strncpy(temp, in_str + curr_pos, peek_pos - curr_pos);
		temp[peek_pos - curr_pos] = '\0';
		t.t_str = temp;
		t.isVar = true;
	}
	else
		throw new Lex_Exception("Invalid token.");

	return t;
}

void Lexical_Analyzer::Consume_Token() {
	assert(peek_pos >= curr_pos);

	if (peek_pos == curr_pos)
		Peek_Token();

	curr_pos = peek_pos;
}

bool Lexical_Analyzer::is_cos() {
	if (in_str[curr_pos] == 'c' && in_str[curr_pos + 1] == 'o' && in_str[curr_pos + 2] == 's') {
		peek_pos = curr_pos + 3;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_sin() {
	if (in_str[curr_pos] == 's' && in_str[curr_pos + 1] == 'i' && in_str[curr_pos + 2] == 'n') {
		peek_pos = curr_pos + 3;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_tan() {
	if (in_str[curr_pos] == 't' && in_str[curr_pos + 1] == 'a' && in_str[curr_pos + 2] == 'n') {
		peek_pos = curr_pos + 3;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_exp() {
	if (in_str[curr_pos] == '^') {
		peek_pos = curr_pos + 1;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_add() {
	if (in_str[curr_pos] == '+') {
		peek_pos = curr_pos + 1;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_sub() {
	if (in_str[curr_pos] == '-') {
		peek_pos = curr_pos + 1;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_mult() {
	if (in_str[curr_pos] == '*') {
		peek_pos = curr_pos + 1;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_div() {
	if (in_str[curr_pos] == '/') {
		peek_pos = curr_pos + 1;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_lparen() {
	if (in_str[curr_pos] == '(') {
		peek_pos = curr_pos + 1;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_rparen() {
	if (in_str[curr_pos] == ')') {
		peek_pos = curr_pos + 1;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_ln() {
	if (in_str[curr_pos] == 'l' && in_str[curr_pos + 1] == 'n') {
		peek_pos = curr_pos + 2;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_space() {
	if (in_str[curr_pos] == ' ') {
		peek_pos = curr_pos + 1;
		return true;
	}

	return false;
}

bool Lexical_Analyzer::is_constant() {
	bool loop = true;
	int count = -1;

	peek_pos = curr_pos;

	while (loop) {
		count++;

		if (in_str[peek_pos] == '0')
			loop = true;
		else if (in_str[peek_pos] == '1')
			loop = true;
		else if (in_str[peek_pos] == '2')
			loop = true;
		else if (in_str[peek_pos] == '3')
			loop = true;
		else if (in_str[peek_pos] == '4')
			loop = true;
		else if (in_str[peek_pos] == '5')
			loop = true;
		else if (in_str[peek_pos] == '6')
			loop = true;
		else if (in_str[peek_pos] == '7')
			loop = true;
		else if (in_str[peek_pos] == '8')
			loop = true;
		else if (in_str[peek_pos] == '9')
			loop = true;
		else
			loop = false;

		peek_pos++;
	}

	if (count == 0) {
		peek_pos = curr_pos;
		return false;
	}

	peek_pos--;
	return true;
}

bool Lexical_Analyzer::is_variable() {
	bool r_val = false;

	peek_pos = curr_pos;

	while (isalnum(in_str[peek_pos])) {
		peek_pos++;
		r_val = true;
	}

	return r_val;
}


