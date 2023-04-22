%{

/* Declarations section */
#include <stdio.h>
#include "tokens.hpp"
void showToken(char *);

%}

%option yylineno
%option noyywrap
digit   		([0-9])
letter  		([a-zA-Z])
whitespace		([\r\n\t ])
printable       ([\x21)
escape          ([\\])


%%

void                        printf("Found void \n");
int
byte
bool
{digit}+          			return "NUM";
{letter}+					showToken("word");
{letter}+@{letter}+\.com		showToken("email address");
{whitespace}				;
.		                    printf("Lex .\n");
{printable}+                 printf("printable .\n");

%%

void showToken(char * name)
{
    printf("Lex found a %s, the lexeme is %s and its length is %d\n", name, yytext, yyleng);
}


