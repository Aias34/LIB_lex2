#include <iostream>
#include "../StaticLib1/Lexer_lib.h"
#include "../StaticLib1/Syntax.h"
#include "../StaticLib1/SY.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


int abc(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    string abc = "int abc(int a){}";
    stringstream prog{ abc };
    vector<Lexem> after;

    Syntax syntax(prog);
    /*
    Lexer lexer(prog);
    auto lexem = lexer.getNextLexem();
    while (lexem.first != "error" && lexem.first != "end") {

        std::cout << lexem.first << " ";
        std::cout << lexem.second << endl;
        lexem = lexer.getNextLexem();
    }
    std::cout << lexem.first << endl;
    std::cout << lexem.second << endl;
    */

}