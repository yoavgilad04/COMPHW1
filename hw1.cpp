#include <stdio.h>
#include "tokens.hpp"
#include <iostream>
int main()
{
    printf("Im Above");
    int token = yylex();
    printf("%d", (token = yylex()));
	while ((token = yylex())) {
        printf("Im Inside");
    }
    printf("Im Below");
    return 0;
}
