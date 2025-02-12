//
//  TerminalOutputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#include "TerminalOutputSystem.hpp"
#include "ChessMoveDescriber.hpp"
#include "TerminalWrapper.hpp"
#include <cstdio>

TerminalOutputSystem::TerminalOutputSystem(TerminalWrapper* newWrapperToOwn)
: moveDescriber_(new ChessMoveDescriber())
, terminalWrapper_(newWrapperToOwn)
{

}

TerminalOutputSystem::~TerminalOutputSystem()
{

}

void TerminalOutputSystem::showTextToUser(const char* displayString)
{
    terminalWrapper_->writeToTerminal(displayString);
}

void TerminalOutputSystem::initializeChessUserInterface()
{
    showTextToUser("===============Main menu ================");
    showTextToUser("Press 'q' to quit.");
    showTextToUser("Press 'n' for a new game.");
}

void TerminalOutputSystem::endUserInteraction()
{
    showTextToUser("quitting chess...");
}

void TerminalOutputSystem::resetUxForNewGame()
{
    showTextToUser("New game requested...");
    showTextToUser("you are playing as white...");
    showTextToUser("please enter a move in fully specified notation...");
}

void TerminalOutputSystem::displayMoveToUser(const ChessMove & move, const I_ReadOnlyChessBoard & board)
{
    std::string moveDescription = moveDescriber_->describeMove(move, board);
    showTextToUser(moveDescription.c_str());
}

void TerminalOutputSystem::rejectMoveAttempt(Chess::MoveValidity validity)
{
    
}


