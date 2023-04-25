%{

/* Declarations section */
#include <stdio.h>
#include "tokens.hpp"
#include <string.h>

%}

%option yylineno
%option noyywrap
digit   		([0-9])
letter  		([a-zA-Z])
escape          ([\\])
whitespace		([\r\n\t ])
instring       ([\x20-\x21\x23-\x5b\x5d-\x7e\x09\x0a\x0d])


%x STR
%x ESC

%%
\"                          BEGIN(STR); return INITSTRING;
<STR>\"                     BEGIN(INITIAL); return STRING;
<STR>{instring}*           return ADDSTRING;
<STR>{escape}              BEGIN(ESC);
<STR>.                      return ERROR;
<ESC>n|t|r|0|\"|\\|x({digit}|{letter}){2}            BEGIN(STR); return STRINGESC;
<ESC>.                      return ERROR;
{whitespace}				;
void                        return VOID;
int                         return INT;
byte                        return BYTE;
bool                        return BOOL;
b                           return B;
and                         return AND;
or                          return OR;
not                         return NOT;
true                        return TRUE;
false                       return FALSE;
return                      return RETURN;
else                        return ELSE;
while                       return WHILE;
if                          return IF;
.		                    return ERROR;

%%







