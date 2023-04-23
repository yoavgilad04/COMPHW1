#include <stdio.h>
#include "tokens.hpp"
#include <iostream>
int main()
{
    int token;
	while ((token = yylex())) {
        std::cout << token << std::endl;
    }
    return 0;
}
