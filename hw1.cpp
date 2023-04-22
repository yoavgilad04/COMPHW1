#include <stdio.h>
#include "tokens.hpp"

int main()
{
    printf("Im Above");
    int token;
	while ((token = yylex())) {
        exit(0);
    }
    printf("Im Below");
    return 0;
}
