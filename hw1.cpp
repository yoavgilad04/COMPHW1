#include <stdio.h>
#include "tokens.hpp"

int main()
{
	int token;
	while ((token = yylex())) {
        printf("Im here");
        exit(0);
	}
	return 0;
}
