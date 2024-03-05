// StaticLib1.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "Lexer_lib.h"
#include "fsm_lib.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;


Lexer::Lexer(string stroka) : state{ 0 }, stroka{ stroka }
{}


Lexer::~Lexer()
{
    //dtor
}

Lexem Lexer::getNextLexem() {
    Lexem lex = LEX_EMPTY;
    string lexem = "";

    auto res = tick(state, stroka);
    state = res.first;
    if (res == LEX_ERROR) {
        lex = LEX_ERROR;
    }
    else if (res == LEX_EOF) {
        lex = LEX_EOF;
    }
    else if (res == LEX_EMPTY) {
        lex = { 0, lexem };
        return getNextLexem();
    }
    else {
        lexem.append(res.second);
        lex = { state, lexem };
    }
    return lex;
}