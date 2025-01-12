//
//  TerminalInputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#include "TerminalInputSystem.hpp"
#include <cctype>
#include <cstdio>

TerminalInputSystem::TerminalInputSystem()
{

}

TerminalInputSystem::~TerminalInputSystem()
{

}

std::string TerminalInputSystem::readNextUserEntry()
{
    char inputString[64];
    fscanf(stdin, "%63s", inputString);
    
    std::string lowerInputString(inputString);
    std::transform(lowerInputString.begin(), lowerInputString.end(), lowerInputString.begin(),
                   [](unsigned char c){return std::tolower(c);});
    return lowerInputString;
}
