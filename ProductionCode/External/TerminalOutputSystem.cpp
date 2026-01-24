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
#include "ChessMoveValidity.hpp"
#include "OutputErrorDefines.hpp"
#include "StringifyUtilities.hpp"
#include <cstdio>

using namespace Chess;
using namespace std;

TerminalOutputSystem::TerminalOutputSystem(TerminalWrapper& wrapper)
: moveDescriber_(new ChessMoveDescriber())
, terminalWrapper_(wrapper)
{

}

TerminalOutputSystem::~TerminalOutputSystem()
{

}

void TerminalOutputSystem::showTextToUser(const char* displayString)
{
    terminalWrapper_.writeToTerminal(displayString);
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

void TerminalOutputSystem::displayValidMoveToUser(const std::list<Chess::MoveElement>& moveElements)
{
    string moveDescription = moveDescriber_->describeValidMove(moveElements);
    showTextToUser(moveDescription.c_str());
}

void TerminalOutputSystem::rejectMoveAttempt(Chess::MoveValidity validity)
{
    switch (validity)
    {
        case MoveValidity::END_SQUARE_NOT_ON_BOARD:
            showTextToUser(OutputErrorDefines::MOVE_NOT_ON_BOARD_ERROR);
            break;
        case MoveValidity::NO_PIECE_AT_STARTING_LOCATION:
            showTextToUser(OutputErrorDefines::NO_PIECE_AT_COORDINATES_ERROR);
            break;
        case MoveValidity::OPPOSING_PLAYERS_PIECE:
            showTextToUser(OutputErrorDefines::OPPOSING_PLAYERS_PIECE_ERROR);
            break;
        case MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE:
            showTextToUser(OutputErrorDefines::PIECE_CANNOT_CURRENTLY_MOVE_ERROR);
            break;
        case MoveValidity::PATH_BLOCKED_BY_OTHER_PIECES:
            showTextToUser(OutputErrorDefines::MOVE_IS_BLOCKED_ERROR);
            break;
        case MoveValidity::DESTINATION_BLOCKED_BY_EXISTING_PIECE:
            showTextToUser(OutputErrorDefines::MOVE_IS_BLOCKED_ERROR);
            break;
        case MoveValidity::PROMOTION_NOT_LEGAL:
            showTextToUser(OutputErrorDefines::PROMOTION_NOT_LEGAL);
        default:
            break;
    }
}

void TerminalOutputSystem::declareCheck()
{
    showTextToUser("Check!");
}

void TerminalOutputSystem::requestPromotionDecision()
{
    showTextToUser("Choose a promotion: 1: knight 2: bishop 3: rook 4: queen");
}

void TerminalOutputSystem::notifyUserOfPromotionTo(Chess::PieceType type)
{
    string output("Pawn was promoted to a ");
    output.append(toString(type));
    output.append(".");
    showTextToUser(output.c_str());
}
