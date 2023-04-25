#include <stdio.h>
#include <stdlib.h>
#include "tokens.hpp"
#include <iostream>
#include <string.h>
#include <string>

using std::cout;
using std::string;
using std::endl;

void printLine(int line, string id, string lexema)
{
    string sp = " ";
    cout << line << sp << id << sp << lexema << endl;
}

void printError(string lexema)
{
    cout << "Error " << lexema << endl;
    exit(0);
}

void printString(int line,string id,string str)
{
    string sp = " ";
    cout << line << sp << id << sp;
    cout << str << endl;
}

int main()
{
    cout << "_________________________________________________________" << endl;
    int token;
    string id;
    string str = "";
    bool seen_zero_char = false;
    string str_with_zero_char = "";
	while ((token = yylex()))
    {
        switch (token)
        {
            case VOID:
                id = "VOID";
                break;
            case INT:
                id = "INT";
                break;
            case BYTE:
                id = "BYTE";
                break;
            case B:
                id = "B";
                break;
            case BOOL:
                id = "BOOL";
                break;
            case AND:
                id = "AND";
                break;
            case OR:
                id = "OR";
                break;
            case NOT:
                id = "NOT";
                break;
            case TRUE:
                id = "TRUE";
                break;
            case FALSE:
                id = "FALSE";
                break;
            case RETURN:
                id = "RETURN";
                break;
            case IF:
                id = "IF";
                break;
            case ELSE:
                id = "ELSE";
                break;
            case WHILE:
                id = "WHILE";
                break;
            case BREAK:
                id = "BREAK";
                break;
            case CONTINUE:
                id = "CONTINUE";
                break;
            case SC:
                id = "SC";
                break;
            case COMMA:
                id = "COMMA";
                break;
            case LPAREN:
                id = "LPAREN";
                break;
            case RPAREN:
                id = "RPAREN";
                break;
            case LBRACE:
                id = "LBRACE";
                break;
            case RBRACE:
                id = "RBRACE";
                break;
            case ASSIGN:
                id = "ASSIGN";
                break;
            case RELOP:
                id = "RELOP";
                break;
            case BINOP:
                id = "BINOP";
                break;
            case COMMENT:
                id = "COMMENT";
                break;
            case ID:
                id = "ID";
                break;
            case NUM:
                id = "NUM";
                break;
            case STRING:
                id = "STRING";
                if(seen_zero_char)
                    str = str_with_zero_char;
                printString(yylineno, id, str);
                continue;
            case OVERRIDE:
                id = "OVERRIDE";
                break;
            case ERROR:
                printError(yytext);
                break;
            case INITSTRING:
                str = "";
                str_with_zero_char = "";
                seen_zero_char = false;
                continue;
            case ADDSTRING:
                    str += yytext;
                continue;
            case STRINGESC:
                if (strcmp(yytext, "n") == 0)
                    str += "\n";
                else if (strcmp(yytext, "t") == 0)
                    str += "\t";
                else if (strcmp(yytext, "r") == 0)
                    str += "\r";
                else if (strcmp(yytext, "0") == 0)
                {
                    str_with_zero_char = str;
                    seen_zero_char = true;
                }
                else if (strcmp(yytext, "\"") == 0)
                    str += "\"";
                else if (strcmp(yytext, "\\") == 0)
                    str += "\\";
                else if (yytext[0] == 'x')
                {
                    yytext += 1;
                    long num = strtol(yytext, nullptr, 16);
                    str += char(num);
                }
                continue;
            default:
                printError(yytext);
                break;
        }
        printLine(yylineno, id, yytext);
    }
    return 0;
}
