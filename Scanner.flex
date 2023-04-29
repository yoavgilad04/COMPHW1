%{

/* Declarations section */
#include <stdio.h>
#include "tokens.hpp"
#include <string.h>

void showToken(char *);

%}

%option yylineno
%option noyywrap
digit   		([0-9])
letter  		([a-zA-Z])
whitespace		([\r\n\t ])
printable       ([\x20-\x7e\x09\x0a\x0d])
escape          ([\\])


%x STRING

%%
\"                          BEGIN(STRING);
<STRING>\"                  BEGIN(INITIAL);
<STRING>{printable}[^\"]*    showToken("STRING");
<STRING>.                   showToken("illegal")
\"{printable}[^\"]*\"               showToken("STRING");
{whitespace}				printf("Found whitespace\n");
void                        return VOID;
{digit}+          			showToken("NUM");
{letter}+					showToken("word");
{letter}+@{letter}+\.com		showToken("email address");

.		                    printf("Lex .\n");

%%


void showToken(char * name)
{
    printf("%d %s %s\n", yylineno, name, yytext);
}





