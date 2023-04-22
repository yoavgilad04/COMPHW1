#include <stdio.h>
#include "tokens.hpp"

int main()
{
	int token;
	while ((token = yylex())) {
        printf(token);
        exit(0);
	}
	return 0;
}
