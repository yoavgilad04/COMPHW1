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
//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