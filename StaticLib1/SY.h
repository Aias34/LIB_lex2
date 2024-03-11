#ifndef LEX_TESTS_SHUNTINGYARD_H
#define LEX_TESTS_SHUNTINGYARD_H

#include "Lexer_lib.h"
#include "fsm_lib.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <sstream>

class ShuntingYard {
public:
    ShuntingYard(std::istream&);
    virtual ~ShuntingYard();
    Lexem getNextLexem();


protected:
private:
    Lexer lexer;
    std::vector<Lexem> res;
    std::map<std::string, int> priority = { {"opplus", 1}, {"opminus", 1}, {"opmul", 2} };
    int state;
};

#endif // LEX_TESTS_SHUNTINGYARD_H