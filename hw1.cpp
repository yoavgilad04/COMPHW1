#include <stdio.h>
#include "tokens.hpp"

int main()
{
	int token;
	while ((token = yylex())) {
        if(token == NUM)
            printf("asdfdsf");
	}
	return 0;
}
