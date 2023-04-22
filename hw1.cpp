#include "tokens.hpp"
#include <stdio.h>
int main()
{
	int token;
	while ((token = yylex())) {
        printf("I am inside the loop");
        if (token == NUM)
          printf("Im a number");
	}
	return 0;
}
