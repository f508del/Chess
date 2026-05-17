//
//  StringBasedOutputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#include "StringBasedOutputSystem.hpp"
#include "ChessMoveDescriber.hpp"
#include "I_StringOutputDestination.hpp"
#include "ChessMoveValidity.hpp"
#include "OutputErrorDefines.hpp"
#include "StringifyUtilities.hpp"
#include <cstdio>

using namespace Chess;
using namespace std;

StringBasedOutputSystem::StringBasedOutputSystem(I_StringOutputDestination& wrapper)
: moveDescriber_(new ChessMoveDescriber())
, stringDestination_(wrapper)
{

}

StringBasedOutputSystem::~StringBasedOutputSystem()
{

}

void StringBasedOutputSystem::showTextToUser(const char* displayString)
{
    stringDestination_.writeOutputString(displayString);
}

void StringBasedOutputSystem::initializeChessUserInterface()
{
    showTextToUser("===============Main menu ================");
    showTextToUser("Press 'q' to quit.");
    showTextToUser("Press 'n' for a new game.");
}

void StringBasedOutputSystem::endUserInteraction()
{
    showTextToUser("quitting chess...");
}

void StringBasedOutputSystem::resetUxForNewGame()
{
    showTextToUser("New game requested...");
    showTextToUser("you are playing as white...");
    showTextToUser("please enter a move in fully specified notation...");
}

void StringBasedOutputSystem::displayValidMoveToUser(const std::list<Chess::MoveElement>& moveElements)
{
    string moveDescription = moveDescriber_->describeValidMove(moveElements);
    showTextToUser(moveDescription.c_str());
}

void StringBasedOutputSystem::rejectMoveAttempt(Chess::MoveValidity validity)
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
            break;
        case MoveValidity::CANNOT_LEAVE_KING_IN_DANGER:
            showTextToUser(OutputErrorDefines::CANNOT_LEAVE_KING_IN_DANGER);
            break;
        default:
            break;
    }
}

void StringBasedOutputSystem::declareCheck()
{
    showTextToUser("Check!");
}

void StringBasedOutputSystem::declareCheckmate()
{
    showTextToUser("Checkmate!");
}

void StringBasedOutputSystem::declareStalemate()
{
    showTextToUser("Stalemate!");
}

void StringBasedOutputSystem::requestPromotionDecision()
{
    showTextToUser("Choose a promotion: 1: knight 2: bishop 3: rook 4: queen");
}

void StringBasedOutputSystem::notifyUserOfPromotionTo(Chess::PieceType type)
{
    string output("Pawn was promoted to a ");
    output.append(toString(type));
    output.append(".");
    showTextToUser(output.c_str());
}

void StringBasedOutputSystem::gameEndedDueToTooManyConsecutiveInvalidMoveAttempts()
{
    showTextToUser("GAME ENDED due to 10 consecutive invalid move attempts.\n");
}

