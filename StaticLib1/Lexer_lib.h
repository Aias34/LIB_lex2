#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <string>

class Lexer
{
public:
    Lexer(std::string);
    virtual ~Lexer();
    std::pair<int, std::string> getNextLexem();

protected:

private:
    int state;
    char cache;
    std::string stroka;
};

#endif // LEXER_H
#pragma once