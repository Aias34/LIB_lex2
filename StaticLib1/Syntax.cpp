#include "pch.h"
#include "Syntax.h"
#include "Lexer_lib.h"
#include "fsm_lib.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Syntax::Syntax(istream& stream) : lexer{ stream }
{
    cur = lexer.getNextLexem();
    bool res = DeclareStmt();

    if (res) {
        if (cur == LEX_EOF) {
            cout << "YES" << endl;
        }
        else {
            cout << "FAIL" << endl;
        }
    }
    else {
        cout << "FAIL" << endl;
    }
}

Syntax::~Syntax()
{
    // dtor
}

bool Syntax::E(vector <int>& tree) {

    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += " ";
            }
            else if (tree[i] == 1) {
                d += "|";
            }
        }
    }
    d += sub;
    d += "E";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return false;
    }
    tree.push_back(0);
    if (!E7(tree)) {
        tree.pop_back();
        return false;
    }
    tree.pop_back();
    return true;
}

bool Syntax::E7(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E7";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return false;
    }
    tree.push_back(1);
    if (!E6(tree)) {
        tree.pop_back();
        return false;
    }
    tree.push_back(0);
    if (!E7L(tree)) {
        tree.pop_back();
        return false;
    }
    tree.pop_back();
    return true;
}

bool Syntax::E7L(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E7L";
    cout << d << endl;
    d = "";
    sub = "";

    if (cur == LEX_EOF) {
        tree.pop_back();
        return true;
    }

    if (cur.first == "opor") {
        cur = lexer.getNextLexem();
        sub += " opor ";
        tree.push_back(1);
        if (!E6(tree)) {
            tree.pop_back();
            return false;
        }
        tree.push_back(0);
        if (!E7L(tree)) {
            tree.pop_back();
            return false;
        }

    }
    tree.pop_back();
    return true;
}

bool Syntax::E6(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E6";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return false;
    }
    tree.push_back(1);
    if (!E5(tree)) {
        tree.pop_back();
        return false;
    }
    tree.push_back(0);
    if (!E6L(tree)) {
        tree.pop_back();
        return false;
    }
    tree.pop_back();
    return true;
}

bool Syntax::E6L(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E6L";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return true;
    }
    if (cur.first == "opand") {
        cur = lexer.getNextLexem();
        sub += " opand ";
        tree.push_back(1);
        if (!E5(tree)) {
            tree.pop_back();
            return false;
        }
        tree.push_back(0);
        if (!E6L(tree)) {
            tree.pop_back();
            return false;
        }

    }

    tree.pop_back();
    return true;
}

bool Syntax::E5(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E5";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return false;
    }
    tree.push_back(1);
    if (!E4(tree)) {
        tree.pop_back();
        return false;
    }
    tree.push_back(0);
    if (!E5L(tree)) {
        tree.pop_back();
        return false;
    }
    tree.pop_back();
    return true;
}

bool Syntax::E5L(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E5L";
    cout << d << endl;
    d = "";
    sub = "";;
    if (cur == LEX_EOF) {
        tree.pop_back();
        return true;
    }

    if (cur.first == "opeq") {
        cur = lexer.getNextLexem();
        sub += " opeq ";
        tree.push_back(0);
        if (!E4(tree)) {
            tree.pop_back();
            return false;
        }
    }
    else if (cur.first == "opne") {
        cur = lexer.getNextLexem();
        sub += " opne ";
        tree.push_back(0);
        if (!E4(tree)) {
            tree.pop_back();
            return false;
        }
    }
    else if (cur.first == "opgt") {
        cur = lexer.getNextLexem();
        sub += " opgt ";
        tree.push_back(0);
        if (!E4(tree)) {
            tree.pop_back();
            return false;
        }
    }
    else if (cur.first == "oplt") {
        cur = lexer.getNextLexem();
        sub += " oplt ";
        tree.push_back(0);
        if (!E4(tree)) {
            tree.pop_back();
            return false;
        }
    }
    else if (cur.first == "ople") {
        cur = lexer.getNextLexem();
        sub += " ople ";
        tree.push_back(0);
        if (!E4(tree)) {
            tree.pop_back();
            return false;
        }
    }
    tree.pop_back();
    return true;
}

bool Syntax::E4(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E4";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return false;
    }
    tree.push_back(1);
    if (!E3(tree)) {
        tree.pop_back();
        return false;
    }
    tree.push_back(0);
    if (!E4L(tree)) {
        tree.pop_back();
        return false;
    }
    tree.pop_back();
    return true;
}

bool Syntax::E4L(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E4L";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return true;
    }
    if (cur.first == "opplus") {
        cur = lexer.getNextLexem();
        sub += " opplus ";
        tree.push_back(1);
        if (!E3(tree)) {
            tree.pop_back();
            return false;
        }
        tree.push_back(0);
        if (!E4L(tree)) {
            tree.pop_back();
            return false;
        }
    }
    else if (cur.first == "opminus") {
        cur = lexer.getNextLexem();
        sub += " opminus ";
        tree.push_back(1);
        if (!E3(tree)) {
            tree.pop_back();
            return false;
        }
        tree.push_back(0);
        if (!E4L(tree)) {
            tree.pop_back();
            return false;
        }
    }
    tree.pop_back();
    return true;
}

bool Syntax::E3(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E3";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return false;
    }
    tree.push_back(1);
    if (!E2(tree)) {
        tree.pop_back();
        return false;
    }
    tree.push_back(0);
    if (!E3L(tree)) {
        tree.pop_back();
        return false;
    }
    tree.pop_back();
    return true;
}

bool Syntax::E3L(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E3L";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return true;
    }
    if (cur.first == "opmul") {
        cur = lexer.getNextLexem();
        sub += " opmul ";
        tree.push_back(1);
        if (!E2(tree)) {
            tree.pop_back();
            return false;
        }
        tree.push_back(0);
        if (!E3L(tree)) {
            tree.pop_back();
            return false;
        }
    }
    tree.pop_back();
    return true;
}

bool Syntax::E2(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E2";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return false;
    }
    tree.push_back(0);
    if (cur.first == "opnot") {
        cur = lexer.getNextLexem();
        sub += " opnot ";
        if (!E1(tree)) {
            tree.pop_back();
            return false;
        }
    }
    else if (!E1(tree)) {
        tree.pop_back();
        return false;
    }

    tree.pop_back();
    return true;
}

bool Syntax::E1(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E1";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return false;
    }
    if (cur.first == "opinc") {
        cur = lexer.getNextLexem();
        sub += " opinc ";
        if (cur.first == "id") {
            sub += " ";
            sub += cur.second;
            sub += " ";
            cur = lexer.getNextLexem();
            tree.pop_back();
            return true;
        }
        else {
            tree.pop_back();
            return false;
        }
    }
    else if (cur.first == "lpar") {
        cur = lexer.getNextLexem();
        sub += " lpar ";
        tree.push_back(0);
        if (!E(tree)) {
            tree.pop_back();
            return false;
        }
        if (cur.first == "rpar") {
            cur = lexer.getNextLexem();
            sub += "rpar ";
            tree.pop_back();
            return true;
        }
        else {
            tree.pop_back();
            return false;
        }
    }
    else if (cur.first == "num") {
        sub += " ";
        sub += cur.second;
        sub += " ";
        cur = lexer.getNextLexem();


        tree.pop_back();
        return true;
    }
    else if (cur.first == "id") {
        cur = lexer.getNextLexem();
        sub += " id ";
        tree.push_back(0);
        if (!E1L(tree)) {
            tree.pop_back();
            return false;
        }
    }
    tree.pop_back();
    return true;
}

bool Syntax::E1L(vector <int>& tree) {
    for (int i = 1; i < tree.size(); i++) {
        if (tree.size() == 1) {
            break;
        }
        if (i == tree.size() - 1) {
            if (tree[i] == 0) {
                d += "|_";
            }
            else if (tree[i] == 1) {
                d += "|-";
            }
        }
        else {
            if (tree[i] == 0) {
                d += ' ';
            }
            else if (tree[i] == 1) {
                d += '|';
            }
        }
    }
    d += sub;
    d += "E1L";
    cout << d << endl;
    d = "";
    sub = "";
    if (cur == LEX_EOF) {
        tree.pop_back();
        return true;
    }
    if (cur.first == "opinc") {
        sub += " opinc ";
        cur = lexer.getNextLexem();
        tree.pop_back();
        return true;
    }
    else {
        tree.pop_back();
        return false;
    }
}

bool Syntax::Type() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "kwint") {
        cur = lexer.getNextLexem();
        return true;
    }
    else if (cur.first == "kwchar") {
        cur = lexer.getNextLexem();
        return true;
    }
    return false;
}

bool Syntax::DeclareStmt() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (!Type()) {
        return false;
    }
    if (cur.first == "id") {
        cur = lexer.getNextLexem();
        if (!DeclareStmtList()) {
            return false;
        }
    }
    return true;
}

bool Syntax::DeclareStmtList() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "lpar") {
        cur = lexer.getNextLexem();
        if (!ParamList()) {
            return false;
        }
        if (cur.first == "rpar") {
            cur = lexer.getNextLexem();
            if (cur.first == "lbrace") {
                cur = lexer.getNextLexem();
                if (!StmtList()) {
                    return false;
                }
                if (cur.first == "rbrace") {
                    cur = lexer.getNextLexem();
                    return true;
                }
            }
        }
    }
    else if (cur.first == "opassign") {
        cur = lexer.getNextLexem();
        if (cur.first == "num") {
            cur = lexer.getNextLexem();
            if (!DeclVarList()) {
                return false;
            }
            if (cur.first == "semicolon") {
                cur = lexer.getNextLexem();
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
    else if (DeclVarList()) {
        if (cur.first == "semicolon") {
            cur = lexer.getNextLexem();
            return true;
        }
        else {
            return false;
        }
    }
    return true;
}

bool Syntax::DeclVarList() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (cur.first == "comma") {
        cur = lexer.getNextLexem();
        if (cur.first == "id") {
            cur = lexer.getNextLexem();
            if (!InitVar()) {
                return false;
            }
            if (!DeclVarList()) {
                return false;
            }
        }
    }
    return true;
}

bool Syntax::InitVar() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (cur.first == "opassign") {
        cur = lexer.getNextLexem();
        if (cur.first == "num") {
            cur = lexer.getNextLexem();
            return true;
        }
        else if (cur.first == "char") {
            cur = lexer.getNextLexem();
            return true;
        }
    }
    return true;
}

bool Syntax::ParamList() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (!Type()) {
        return false;
    }
    if (cur.first == "id") {
        cur = lexer.getNextLexem();
        if (!ParamListList()) {
            return false;
        }
        return true;
    }
    return true;
}

bool Syntax::ArgList() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (!E(tree)) {
        return true;
    }
    if (cur.first == "comma") {
        cur = lexer.getNextLexem();
        if (!ArgList()) {
            return true;
        }
    }
    return true;
}

bool Syntax::ParamListList() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (cur.first == "comma") {
        cur = lexer.getNextLexem();
        if (!Type()) {
            return false;
        }
        if (cur.first == "id") {
            cur = lexer.getNextLexem();
            if (!ParamListList()) {
                return false;
            }
            return true;
        }
    }
    return true;
}

bool Syntax::StmtList() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (!Stmt()) {
        return true;
    }
    if (!StmtList()) {
        return true;
    }
    return true;
}

bool Syntax::Stmt() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (DeclareStmt()) {
        return true;
    }
    else if (AssignOrCallOp()) {
        return true;
    }
    else if (ForOp()) {
        return true;
    }
    else if (IfOp()) {
        return true;
    }
    else if (SwitchOp()) {
        return true;
    }
    else if (IOp()) {
        return true;
    }
    else if (OOp()) {
        return true;
    }
    else if (cur.first == "semicolon") {
        cur = lexer.getNextLexem();
        return true;
    }
    else if (cur.first == "lbrace") {
        cur = lexer.getNextLexem();
        if (!StmtList()) {
            return false;
        }
        if (cur.first == "rbrace") {
            cur = lexer.getNextLexem();
            return true;
        }
    }
    else if (cur.first == "kwreturn") {
        cur = lexer.getNextLexem();
        if (!E(tree)) {
            return false;
        }
        return true;
    }
    return false;
}

bool Syntax::AssignOrCallOp() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (AssignOrCall()) {
        if (cur.first == "semicolon") {
            cur = lexer.getNextLexem();
            return true;
        }
    }
    return false;
}

bool Syntax::AssignOrCall() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "id") {
        cur = lexer.getNextLexem();
        if (!AssignOrCallList()) {
            return false;
        }
        return true;
    }
    return false;
}

bool Syntax::AssignOrCallList() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "opassign") {
        cur = lexer.getNextLexem();
        if (!E(tree)) {
            return false;
        }
        return true;
    }
    else if (cur.first == "lpar") {
        cur = lexer.getNextLexem();
        if (!ArgList()) {
            return false;
        }
        if (cur.first == "rpar") {
            cur = lexer.getNextLexem();
            return true;
        }
        return false;
    }
    return false;
}
bool Syntax::WhileOp() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "kwwhile") {
        cur = lexer.getNextLexem();
        if (cur.first == "lpar") {
            cur = lexer.getNextLexem();
            if (!E(tree)) {
                return false;
            }
            if (cur.first == "rpar") {
                cur = lexer.getNextLexem();
                if (!Stmt()) {
                    return false;
                }
                return true;
            }
        }
    }
    return false;
}

bool Syntax::ForOp() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "kwfor") {
        cur = lexer.getNextLexem();
        if (cur.first == "lpar") {
            cur = lexer.getNextLexem();
            if (!ForInit()) {
                return false;
            }
            if (cur.first == "semicolon") {
                cur = lexer.getNextLexem();
                if (!ForExp()) {
                    return false;
                }
                if (cur.first == "semicolon") {
                    cur = lexer.getNextLexem();
                    if (!ForLoop()) {
                        return false;
                    }
                    if (cur.first == "rpar") {
                        cur = lexer.getNextLexem();
                        if (!Stmt()) {
                            return false;
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Syntax::ForInit() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (!AssignOrCall()) {
        return false;
    }
    return true;
}

bool Syntax::ForExp() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (!E(tree)) {
        return false;
    }
    return true;
}

bool Syntax::ForLoop() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (cur.first == "opinc") {
        cur = lexer.getNextLexem();
        if (cur.first == "id") {
            cur = lexer.getNextLexem();
            return true;
        }
    }
    else if (!AssignOrCall()) {
        return false;
    }
    return true;
}

bool Syntax::IfOp() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "kwif") {
        cur = lexer.getNextLexem();
        if (cur.first == "lpar") {
            cur = lexer.getNextLexem();
            if (!E(tree)) {
                return false;
            }
            if (cur.first == "rpar") {
                cur = lexer.getNextLexem();
                if (!Stmt()) {
                    return false;
                }
                if (!ElsePart()) {
                    return false;
                }
                return true;
            }
        }

    }
    return false;
}

bool Syntax::ElsePart() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (cur.first == "kwelse") {
        cur = lexer.getNextLexem();
        if (!Stmt()) {
            return false;
        }
        return true;
    }
    return true;
}

bool Syntax::SwitchOp() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "kwswitch") {
        cur = lexer.getNextLexem();
        if (cur.first == "lpar") {
            cur = lexer.getNextLexem();
            if (!E(tree)) {
                return false;
            }
            if (cur.first == "rpar") {
                cur = lexer.getNextLexem();
                if (cur.first == "lbrace") {
                    cur = lexer.getNextLexem();
                    if (!Cases()) {
                        return false;
                    }
                    if (cur.first == "rbrace") {
                        cur = lexer.getNextLexem();
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

bool Syntax::Cases() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (!Acase()) {
        return false;
    }
    if (!CasesList()) {
        return false;
    }
    return true;
}

bool Syntax::CasesList() {
    if (cur == LEX_EOF) {
        return true;
    }
    if (!Acase()) {
        return false;
    }
    if (!CasesList()) {
        return false;
    }
    return true;
}

bool Syntax::Acase() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "kwcase") {
        cur = lexer.getNextLexem();
        if (cur.first == "num") {
            cur = lexer.getNextLexem();
            if (cur.first == "colon") {
                cur = lexer.getNextLexem();
                if (!Stmt()) {
                    return false;
                }
                return true;
            }
        }
    }
    else if (cur.first == "kwdefault") {
        cur = lexer.getNextLexem();
        if (!Stmt()) {
            return false;
        }
        return true;
    }
    return false;
}

bool Syntax::IOp() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "kwin") {
        cur = lexer.getNextLexem();
        if (cur.first == "id") {
            cur = lexer.getNextLexem();
            if (cur.first == "semicolon") {
                cur = lexer.getNextLexem();
                return true;
            }
        }
    }
    return false;
}

bool Syntax::OOp() {
    if (cur == LEX_EOF) {
        return false;
    }
    if (cur.first == "kwout") {
        cur = lexer.getNextLexem();
        if (!E(tree)) {
            return false;
        }
        if (cur.first == "semicolon") {
            cur = lexer.getNextLexem();
            return true;
        }
        return true;
    }
    return false;
}