#pragma once
#include <exception>

using namespace std;

class Semantic_Exception : public exception {
private:
	char *error_msg;

public:
	Semantic_Exception();
	~Semantic_Exception();
};

