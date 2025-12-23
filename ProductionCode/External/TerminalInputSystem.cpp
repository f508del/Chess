//
//  TerminalInputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#include "TerminalInputSystem.hpp"
#include "CommandDefines.hpp"
#include "ChessMoveRequest.hpp"
#include "TerminalWrapper.hpp"
#include <cctype>
#include <cstdio>

using namespace CommandDefines;
using namespace std;

TerminalInputSystem::TerminalInputSystem(TerminalWrapper& wrapper)
: newGameCallback_([]{})
, quitCallback_([]{})
, moveAttemptCallback_([](const ChessMoveRequest&){})
, terminalWrapper_(wrapper)
{

}

TerminalInputSystem::~TerminalInputSystem()
{

}

void TerminalInputSystem::getNextInput()
{
    string lowerInputString = terminalWrapper_.readFromTerminal();
    
    transform(lowerInputString.begin(), lowerInputString.end(), lowerInputString.begin(),
                   [](unsigned char c){return tolower(c);});
    
    if (lowerInputString == NEW_GAME_COMMAND)
    {
        newGameCallback_();
    }
    else if (lowerInputString == QUIT_COMMAND)
    {
        quitCallback_();
    }
    else
    {
        // attempt to read in the input as a move...
        ChessMoveRequest move;
        move.populateFromString(lowerInputString);
        moveAttemptCallback_(move);
    }
    return;
}

void TerminalInputSystem::registerNewGameCallback(function<void ()> callback)
{
    newGameCallback_ = callback;
    return;
}

void TerminalInputSystem::registerQuitCallback(function<void ()> callback)
{
    quitCallback_ = callback;
    return;
}

void TerminalInputSystem::registerMoveAttemptCallback(function<void(const ChessMoveRequest&)> callback)
{
    moveAttemptCallback_ = callback;
    return;
}
