//
//  TerminalInputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#include "TerminalInputSystem.hpp"
#include "CommandDefines.hpp"
#include "TerminalWrapper.hpp"
#include <cctype>
#include <cstdio>

using namespace CommandDefines;

TerminalInputSystem::TerminalInputSystem(TerminalWrapper& wrapper)
: newGameCallback_([]{})
, terminalWrapper_(wrapper)
{

}

TerminalInputSystem::~TerminalInputSystem()
{

}

std::string TerminalInputSystem::getNextInput()
{
    std::string lowerInputString = terminalWrapper_.readFromTerminal();
    
    std::transform(lowerInputString.begin(), lowerInputString.end(), lowerInputString.begin(),
                   [](unsigned char c){return std::tolower(c);});
    
    if (lowerInputString == NEW_GAME_COMMAND)
    {
        newGameCallback_();
    }
    return lowerInputString;
}

void TerminalInputSystem::registerNewGameCallback(std::function<void ()> callback)
{
    newGameCallback_ = callback;
    return;
}

