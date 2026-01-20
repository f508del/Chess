//
//  TerminalInputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#include "StringBasedInputSystem.hpp"
#include "CommandDefines.hpp"
#include "ChessMoveRequest.hpp"
#include "TerminalWrapper.hpp"
#include <cctype>
#include <cstdio>

using namespace CommandDefines;
using namespace std;

StringBasedInputSystem::StringBasedInputSystem(TerminalWrapper& wrapper)
: newGameCallback_([]{})
, quitCallback_([]{})
, moveAttemptCallback_([](const ChessMoveRequest&){})
, promotionCallback_([](Chess::PieceType){})
, stringSource_(wrapper)
{

}

StringBasedInputSystem::~StringBasedInputSystem()
{

}

void StringBasedInputSystem::getNextInput()
{
    string lowerInputString = stringSource_.readFromTerminal();
    
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
    else if (Chess::pieceTypeFromString(lowerInputString) != Chess::PieceType::NONE)
    {
        Chess::PieceType inputPiece = Chess::pieceTypeFromString(lowerInputString);
        promotionCallback_(inputPiece);
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

void StringBasedInputSystem::registerNewGameCallback(function<void ()> callback)
{
    newGameCallback_ = callback;
    return;
}

void StringBasedInputSystem::registerQuitCallback(function<void ()> callback)
{
    quitCallback_ = callback;
    return;
}

void StringBasedInputSystem::registerMoveAttemptCallback(function<void(const ChessMoveRequest&)> callback)
{
    moveAttemptCallback_ = callback;
    return;
}

void StringBasedInputSystem::registerPromotionSelectionCallback(function<void(Chess::PieceType)> callback)
{
    promotionCallback_ = callback;
    return;
}
