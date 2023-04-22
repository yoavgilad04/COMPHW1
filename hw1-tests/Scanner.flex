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
whitespace		([\r\n ])
printable       ([0x20-0x7E\r\n ])

%%

{digit}+          			return NUM;
{letter}+					return WORD;
{letter}+@{letter}+\.com	return EMAIL;
{whitespace}				;
.		printf("Lex doesn't know what that is!\n");
{digit}+          			showToken("number");
{letter}+					showToken("word");
{letter}+@{letter}+\.com		showToken("email address");
{whitespace}				;
.		printf("Lex doesn't know what that is!\n");


%%

void showToken(char * name)
{
    printf("Lex found a %s, the lexeme is %s and its length is %d\n", name, yytext, yyleng);
}


