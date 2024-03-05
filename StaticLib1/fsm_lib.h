#ifndef FSM_H_INCLUDED
#define FSM_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using Lexem = std::pair<int, std::string>;

const Lexem LEX_EMPTY = { 0, "" };
const Lexem LEX_ERROR = { -1, "error" };
const Lexem LEX_EOF = { -1, "end" };

Lexem tick(int state, std::string stroka);
void cl();
#endif // FSM_H_INCLUDED
#pragma once
