#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <string>

class Lexer
{
public:
    Lexer(std::istream&);
    virtual ~Lexer();
    std::pair<std::string, std::string> getNextLexem();

protected:

private:
    int state;
    char cache;
    std::istream& stream;
};

#endif // LEXER_H
#pragma once