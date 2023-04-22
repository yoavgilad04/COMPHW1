#include <stdio.h>
#include "tokens.hpp"

int main()
{
    printf("Im Above");
    int token = yylex();
	while (token) {
        exit(0);
        token = yylex();
    }
    printf("Im Below");
    return 0;
}
