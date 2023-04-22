#include <stdio.h>
#include "tokens.hpp"
#include <iostream>
int main()
{
	int token;
	while ((token = yylex())) {
        std::cout<< token << "I'm here";
        exit(0);
	}
	return 0;
}
