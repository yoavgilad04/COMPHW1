#include <stdio.h>
#include "tokens.hpp"

int main()
{
    printf("Im Above");
    int token = yylex();
	while ((token = yylex())) {
        printf("Im Inside");
    }
    printf("Im Below");
    return 0;
}
