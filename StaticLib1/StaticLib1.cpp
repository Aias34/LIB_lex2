// StaticLib1.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "fsm_lib.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// TODO: Это пример библиотечной функции.
int i = 0;
string keyword;


void cl() {
    i = 0;
}

void read(char& cache, istream& stroka) {
    if (stroka) {
        stroka.get(cache);
    }
    if (!stroka) {
        cache = 0;
    }
}

Lexem tick(int state, string stroka) {
    char cache = stroka[i];
    string ch = "";
    switch (state) {
    case 0:
        switch (cache) {
        case '>':
            ++i;
            return { 0, "opgt " };

        case '(':
            ++i;
            return { 0, "lpar " };

        case ')':
            ++i;
            return { 0, "rpar " };

        case '{':
            ++i;
            return { 0, "lbrace " };

        case '}':
            ++i;
            return { 0, "rbrace " };

        case ';':
            ++i;
            return { 0, "semicolon " };

        case ',':
            ++i;
            return { 0, "comma " };

        case '.':
            ++i;
            return { 0, "colon " };

        case '*':
            ++i;
            return { 0, "opmul " };

        case '<':
            if (i + 1 < stroka.length() && stroka[i + 1] == '=') {
                i += 2;
                return { 0, "ople " };
            }
            else {
                ++i;
                return { 0, "oplt " };
            }

        case '!':
            if (i + 1 < stroka.length() && stroka[i + 1] == '=') {
                i += 2;
                return { 0, "opne " };
            }
            else {
                ++i;
                return { 0, "opnot " };
            }

        case '=':
            if (i + 1 < stroka.length() && stroka[i + 1] == '=') {
                i += 2;
                return { 0, "opeq " };
            }
            else {
                ++i;
                return { 0, "opassign " };
            }

        case '+':
            if (i + 1 < stroka.length() && stroka[i + 1] == '+') {
                i += 2;
                return { 0, "opinc " };
            }
            else {
                ++i;
                return { 0, "opplus " };
            }

        case '|':
            if (i + 1 < stroka.length() && stroka[i + 1] == '|') {
                i += 2;
                return { 0, "opor " };
            }
            else {
                return  LEX_ERROR;
            }

        case '&':
            if (i + 1 < stroka.length() && stroka[i + 1] == '&') {
                i += 2;
                return { 0, "opand " };
            }
            else {
                return LEX_ERROR;
            }

        case '\'':
            if (i + 1 > stroka.length() || stroka[i + 1] == '\'') {
                return LEX_ERROR;
            }
            else {
                ch.push_back(stroka[i + 1]);
                i += 2;
                return { 0, "char(" + ch + ") " };
            }

        case '"':
            if (i + 1 < stroka.length()) {
                return LEX_ERROR;
            }
            else {
                ++i;
                return{ 1, "str(" };
            }

        case '-':
            if (i + 1 < stroka.length() && isdigit(stroka[i + 1])) {
                ++i;
                return{ 2, "num(-" };
            }
            else {
                ++i;
                return{ 0, "opminus " };
            }

        case ' ':
        case '\t':
        case '\n':
            ++i;
            if (i + 1 <= stroka.length()) {
                return LEX_EMPTY;
            }
            else {
                return LEX_EOF;
            }

        case 0:
            return LEX_EOF;

        default:
            if (isdigit(cache)) {
                if (i + 1 >= stroka.length()) {
                    ch.append("num(");
                    ch.push_back(cache);
                    ch.append(") ");
                    ++i;
                    return{ 0, ch };
                }
                else {
                    ch.append("num(");
                    ch.push_back(cache);
                    ++i;
                    return{ 2, ch };
                }
            }
            if (isalpha(cache)) {
                if (i + 1 > stroka.length()) {
                    ch.append("id(");
                    ch.push_back(cache);
                    ch.append(") ");
                    ++i;
                    return{ 0, ch };
                }
                else {
                    if (isalpha(stroka[i + 1]) || isdigit(stroka[i + 1])) {
                        return{ 3, "" };
                    }
                    else {
                        ++i;
                        ch.append("id(");
                        ch.push_back(cache);
                        ch.append(") ");
                        return{ 0, ch };
                    }
                }
            }
        }
    case 1:
        switch (cache) {
        case '"':
            return { 0, ") " };

        default:
            if (i + 1 >= stroka.length()) {
                return LEX_ERROR;
            }
            else {
                ++i;
                ch.push_back(cache);
                return { 1, ch };
            }
        }

    case 2:
        if (isdigit(cache)) {
            ch.push_back(cache);
            ++i;
            if (i + 1 > stroka.length()) {
                return{ 0, ch + ") " };
            }
            else {
                return{ 2, ch };
            }
        }
        else {
            return{ 0, ") " };
        }


    case 3:
        if (isdigit(cache) || isalpha(cache)) {
            if (i + 1 <= stroka.length()) {
                keyword.push_back(cache);
                if (keyword == "int" || keyword == "char" ||
                    keyword == "if" || keyword == "else" ||
                    keyword == "switch" || keyword == "case" ||
                    keyword == "while" || keyword == "for" ||
                    keyword == "return" || keyword == "in" ||
                    keyword == "out") {
                    if (stroka[i + 1] != 't') {
                        ++i;
                        return{ 4, "kw" + keyword + " " };
                    }
                    else {
                        i += 2;
                        return{ 4, "kw" + keyword + "t " };
                    }

                }
                else {
                    ++i;
                    return{ 3, "" };
                }
            }
            else {
                if (isalpha(cache)) {
                    keyword.push_back(cache);
                }
                ch.append("id(" + keyword + ") ");
                return{ 4, ch };
            }
        }
        else {
            if (isalpha(cache)) {
                keyword.push_back(cache);
            }
            ch.append("id(" + keyword + ") ");
            return{ 4, ch };
        }



    case 4:
        keyword = "";
        return{ 0, "" };

    case -1:
        return LEX_EOF;
    }
}
