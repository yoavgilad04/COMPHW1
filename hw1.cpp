#include <stdio.h>
#include "tokens.hpp"

int main()
{
	int token;
	while ((token = yylex())) {
        printf("asdfdsf");
	}
	return 0;
}
