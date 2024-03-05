#include "pch.h"
#include "../StaticLib1/fsm_lib.h"
#include "../StaticLib1/Lexer_lib.h"
#include <string> 
#include <vector>
using namespace std;
TEST(TestCaseName, TestName) {
	initializer_list<string> l1{ "<", ">", "-", "gg" };
	vector<string>Tokens(l1);
	auto lex = Lexer(Tokens[0]);
	EXPECT_EQ(lex.getNextLexem(), Lexem(0, "oplt "));
	lex = Lexer(Tokens[1]);
	cl();
	EXPECT_EQ(lex.getNextLexem(), Lexem(0, "opgt "));
	lex = Lexer(Tokens[2]);
	cl();
	EXPECT_EQ(lex.getNextLexem(), Lexem(0, "opminus "));
	lex = Lexer(Tokens[3]);
	cl();
	auto a = lex.getNextLexem();
	string stream;	
	while (a != LEX_EOF) {
		stream += a.second;
		a = lex.getNextLexem();
	}
	EXPECT_EQ(stream, "id(gg) ");
	EXPECT_TRUE(true);
}