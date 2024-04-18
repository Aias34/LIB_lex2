#ifndef SYNTAX_H
#define SYNTAX_H

#include <iostream>
#include <vector>
#include <string>
#include "Lexer_lib.h"
#include "fsm_lib.h"

using namespace std;

class Syntax
{
public:

    Syntax(std::istream&);
    virtual ~Syntax();
    bool Type();
    bool DeclareStmt();
    bool DeclareStmtList();
    bool DeclVarList();
    bool InitVar();
    bool ParamList();
    bool ParamListList();
    bool StmtList();
    bool Stmt();
    bool AssignOrCallOp();
    bool AssignOrCall();
    bool AssignOrCallList();
    bool ArgList();
    bool ForInit();
    bool ForExp();
    bool ForLoop();
    bool ElsePart();
    bool Cases();
    bool Acase();
    bool CasesList();
    bool ForOp();
    bool IfOp();
    bool SwitchOp();
    bool IOp();
    bool WhileOp();
    bool OOp();
    bool E(vector <int>& tree);
    bool E7(vector <int>& tree);
    bool E7L(vector <int>& tree);
    bool E6(vector <int>& tree);
    bool E6L(vector <int>& tree);
    bool E5(vector <int>& tree);
    bool E5L(vector <int>& tree);
    bool E4(vector <int>& tree);
    bool E4L(vector <int>& tree);
    bool E3(vector <int>& tree);
    bool E3L(vector <int>& tree);
    bool E2(vector <int>& tree);
    bool E1(vector <int>& tree);
    bool E1L(vector <int>& tree);

protected:

private:
    Lexer lexer;
    Lexem cur;
    vector<int> tree = { -1 };
    string d = "";
    string sub = "";
    bool res;
    int len = 2;
    int i = 0;
};

#endif // LEXER_H
