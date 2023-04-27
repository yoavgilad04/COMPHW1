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
instring       ([\x20-\x21\x23-\x5b\x5d-\x7e])
incomment      ([^\x0A\x0D])


%x STR
%x ESC

%%
\"                          BEGIN(STR); return INITSTRING;
<STR>\"                     BEGIN(INITIAL); return STRING;
<STR>{instring}*            return ADDSTRING;
<STR>{escape}               BEGIN(ESC);
<STR>[\x0a]                 return LINESTRINGERROR;
<STR>.                      return STRINGERROR;
<ESC>n|t|r|0|\"|\\|x({digit}|[a-fA-F]){2}            BEGIN(STR); return STRINGESC;
<ESC>.|x..;                      return ESCERROR;
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
break                       return BREAK;
continue                    return CONTINUE;
;                           return SC;
,                           return COMMA;
\(                           return  LPAREN;
\)                           return  RPAREN;
\{                           return  LBRACE;
\}                           return  RBRACE;
\=                           return ASSIGN;
==|!=|<|>|<=|>=             return RELOP;
\+|\-|\*|\/                  return BINOP;
override                    return OVERRIDE;
0|[1-9]{digit}*             return NUM;
{letter}({letter}|{digit})* return ID;
\/\/{incomment}*              return COMMENT;
.		                    return ERROR;


%%







