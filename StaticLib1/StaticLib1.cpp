#include "pch.h"
#include "fsm_lib.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::string word = "";


void read(char& cache, istream& stream) {
    if (stream) {
        stream.get(cache);
    }
    if (!stream) {
        cache = 0;
    }
}

pair<int, Lexem> tick(int state, istream& stream, char& cache) {
    switch (state)
    {
    case 0: {
        switch (cache)
        {
        case 0:
            return { -1, {"end",""} };
        case '(':
            read(cache, stream);
            return { 0, {"lpar",""} };
            break;
        case ')':
            read(cache, stream);
            return { 0, {"rpar",""} };
            break;
        case '{':
            read(cache, stream);
            return { 0, {"lbrace",""} };
            break;
        case '}':
            read(cache, stream);
            return { 0, {"rbrace",""} };
            break;
        case ';':
            read(cache, stream);
            return { 0, {"semicolon",""} };
            break;
        case ',':
            read(cache, stream);
            return { 0, {"comma",""} };
        case '.':
            read(cache, stream);
            return { 0, {"colon",""} };
            break;
        case '>':
            read(cache, stream);
            return { 0, {"opgt",""} };
            break;
        case '*':
            read(cache, stream);
            return { 0, {"opmul",""} };
            break;
        case '|':
            read(cache, stream);
            return { 1 , {"",""} };
        case '&':
            read(cache, stream);
            return { 2, {"",""} };
        case '<':
            read(cache, stream);
            return { 3, {"",""} };
        case '!':
            read(cache, stream);
            return { 4, {"",""} };
        case '=':
            read(cache, stream);
            return { 5, {"",""} };
        case '+':
            read(cache, stream);
            return { 6, {"",""} };
        case '\u0027':
            read(cache, stream);
            return { 7, {"",""} };
        case '"':
            read(cache, stream);
            return { 8, {"",""} };
        case '-':
            read(cache, stream);
            return { 9, {"",""} };
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            word += cache;
            read(cache, stream);
            return { 20, {"",""} };
        case 'a':
        case 'b':
        case 'd':
        case 'g':
        case 'h':
        case 'j':
        case 'k':
        case 'l':
        case 'm':
        case 'n':
        case 'p':
        case 'q':
        case 't':
        case 'u':
        case 'v':
        case 'x':
        case 'y':
        case 'z':
        case 'i':
        case 'c':
        case 'e':
        case 's':
        case 'w':
        case 'f':
        case 'r':
        case 'o':
        case 'Q':
        case 'W':
        case 'E':
        case 'R':
        case 'T':
        case 'Y':
        case 'U':
        case 'I':
        case 'O':
        case 'P':
        case 'A':
        case 'S':
        case 'D':
        case 'F':
        case 'G':
        case 'H':
        case 'J':
        case 'K':
        case 'L':
        case 'Z':
        case 'X':
        case 'C':
        case 'V':
        case 'B':
        case 'N':
        case 'M':
            word += cache;
            read(cache, stream);
            return { 21, {"",""} };
        case ' ':
        case '\t':
        case '\n':
            word.clear();
            read(cache, stream);
            return { 0, {"",""} };
        }
    }
    case 1: {
        if (cache == '|') {
            read(cache, stream);
            return { 11, {"",""} };
        }
        else {
            return { -1, {"error",""} };
        }
        break;
    }
    case 10: {
        return { 0, {"opor",""} };
        break;

    }
    case 2: {
        if (cache == '&') {
            read(cache, stream);
            return { 13, {"",""} };
        }
        else {
            return { -1, {"error",""} };
        }
        break;
    }
    case 11: {
        return { 0, {"opand",""} };
        break;
    }
    case 3: {
        if (cache == '=') {
            read(cache, stream);
            return { 12, {"",""} };
        }
        else {
            return { 0, {"oplt",""} };
        }
        break;
    }
    case 12: {
        return { 0, {"ople",""} };
        break;
    }
    case 4: {
        if (cache == '=') {
            read(cache, stream);
            return { 5, {"",""} };
        }
        else {
            return { 0, {"opnot",""} };
        }
        break;
    }
    case 13: {
        return { 0, {"opne",""} };
        break;
    }
    case 5: {
        if (cache == '=') {
            read(cache, stream);
            return { 14, {"",""} };
        }
        else {
            return { 0, {"opassign",""} };
        }
        break;
    }
    case 14: {
        return { 0, {"opeq",""} };
        break;
    }
    case 6: {
        if (cache == '+') {
            read(cache, stream);
            return { 15, {"",""} };
        }
        else {
            return { 0, {"opplus",""} };
        }
        break;
    }
    case 15: {
        return { 0, {"opinc",""} };
        break;
    }
    case 7: {
        if (cache == '\u0027') {
            return { -1, {"error",""} };
        }
        else {
            read(cache, stream);
            return { 16, {"",""} };
        }
        break;
    }
    case 16: {
        if (cache == '\u0027') {
            read(cache, stream);
            return { 17, {"",""} };
        }
        else {
            return { -1, {"error",""} };
        }
        break;
    }
    case 17: {
        return { 0, {"char(value)",""} };
        break;
    }
    case 8: {
        if (cache != '"' && cache != ' ') {
            read(cache, stream);
            return { 18, {"",""} };
        }
        else {
            return { -1, {"error",""} };
        }
        break;
    }
    case 18: {
        if (cache != ' ' && cache != '"') {
            read(cache, stream);
            return { 18, {"",""} };
        }
        if (cache == '"') {
            read(cache, stream);
            return { 19, {"",""} };
        }
        else {
            return { -1, {"error",""} };
        }
    }
    case 19: {
        return { 0, {"str(value)",""} };
        break;
    }
    case 9: {
        if (isdigit(cache)) {
            word += '-';
            word += cache;
            read(cache, stream);
            return { 20, {"",""} };
        }
        else {

            return { 0, {"opminus",""} };
            break;
        }
        break;
    }
    case 20: {
        if (isdigit(cache)) {
            word += cache;
            read(cache, stream);
            return { 20, {"",""} };
        }
        string temp = word;
        word = "";
        return { 0, {"num",temp} };
    }
    case 21: {
        if (isalpha(cache) || isdigit(cache) || cache == '_') {
            word += cache;
            read(cache, stream);
            return { 21, {"",""} };
        }
        else {
            if (word == "int") {
                word.clear();

                return { 0, {"kwint", ""} };

            }
            if (word == "char") {
                word.clear();
                return { 0, {"kwchar", ""} };

            }
            if (word == "if") {
                word.clear();
                return { 0, {"kwif", ""} };

            }
            if (word == "else") {
                word.clear();
                return { 0, {"kwelse", ""} };

            }
            if (word == "switch") {
                word.clear();
                return { 0, {"kwswitch", ""} };
                word.clear();
            }
            if (word == "case") {
                word.clear();
                return { 0, {"kwcase", ""} };
            }
            if (word == "while") {
                word.clear();
                return { 0, {"kwwhile", ""} };
            }
            if (word == "for") {
                word.clear();
                return { 0, {"kwfor", ""} };
            }
            if (word == "return") {
                word.clear();
                return { 0, {"kwreturn", ""} };
            }
            if (word == "in") {
                word.clear();
                return { 0, {"kwin", ""} };
            }
            if (word == "out") {
                word.clear();
                return { 0, {"kwout", ""} };
            }
        }
        string temp = word;
        word = "";
        return { 0, {"id",temp} };

    }
    default:
        break;
    }
}