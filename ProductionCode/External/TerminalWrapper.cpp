//
//  TerminalWrapper.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include "TerminalWrapper.hpp"
using namespace std;

void TerminalWrapper::writeToTerminal(const std::string& text)
{
    fprintf(stdout, "%s\n", text.c_str());
}

string TerminalWrapper::readFromTerminal() {
    char inputString[64];
    fscanf(stdin, "%63s", inputString);
    string result(inputString);
    return result;
}

