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

	return t;
}

void Lexical_Analyzer::Consume_Token() {

}
