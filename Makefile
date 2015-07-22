PARSE_HDR_DIR=Headers/Parser/*.h
EXPR_HDR_DIR=Headers/Parser/Expressions/*.h
TERM_HDR_DIR=Headers/Parser/Terms/*.h
FUNC_HDR_DIR=Headers/Parser/Functions/*.h
LEX_HDR_DIR=Headers/Lexxer/*.h

CC=g++
CFLAGS=-Wall -Werror -g

make:
	gcc -std=c++11 -Wall -Werror -g -c *.cpp