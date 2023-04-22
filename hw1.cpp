#include <stdio.h>
#include "tokens.hpp"

int main()
{
	int token;
	while ((token = yylex())) {
        printf("I am inside the loop")
          printf("Im a number");
	}
	return 0;
}
