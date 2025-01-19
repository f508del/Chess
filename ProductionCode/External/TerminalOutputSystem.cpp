//
//  TerminalOutputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#include "TerminalOutputSystem.hpp"
#include "ChessMoveDescriber.hpp"
#include <cstdio>

TerminalOutputSystem::TerminalOutputSystem()
: moveDescriber_(new ChessMoveDescriber())
{

}

TerminalOutputSystem::~TerminalOutputSystem()
{

}

void TerminalOutputSystem::showTextToUser(const char* displayString)
{
    fprintf(stdout, "%s\n", displayString);
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

void TerminalOutputSystem::displayMoveToUser(const ChessMove &/*move*/, const I_ReadOnlyChessBoard &/*board*/)
{ 

}




