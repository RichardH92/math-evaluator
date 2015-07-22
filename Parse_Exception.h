#pragma once
#include <exception>

using namespace std;

class Parse_Exception : public exception {

private:
	char *error_msg;

public:
	Parse_Exception(char *p_error_msg);
	~Parse_Exception();
	char * Get_Error_Msg();
};

