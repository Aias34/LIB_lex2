#include "pch.h"
#include "framework.h"
#include "fsm_lib.h"
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "SY.h"
#include <sstream>
using namespace std;

ShuntingYard::ShuntingYard(istream& stream)
    : lexer{ stream }
{
    vector<Lexem> lexems;
    auto lex = lexer.getNextLexem();
    while (lex.first != "error" && lex.first != "end") {
        lexems.push_back(lex);
        lex = lexer.getNextLexem();
    }

    if (lexems[0].first != "num" || lexems[0].first != "id") {
        for (auto elem : lexems) {
            if (elem.first == "num" || elem.first == "id") {
                res.push_back(elem);
            }
        }
    }
    else
    {
        res.push_back(LEX_ERROR);
    }

}

ShuntingYard::~ShuntingYard()
{
    // dtor
}

Lexem ShuntingYard::getNextLexem()
{
    // TODO: implement shunting yarg algorithm
    return lexer.getNextLexem();
}