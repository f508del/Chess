//
//  FakeOutputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "FakeOutputSystem.hpp"
#include "I_ChessPiece.hpp"
#include "I_ReadOnlyChessBoard.hpp"

using namespace std;
using namespace Chess;

FakeOutputSystem::FakeOutputSystem()
: lastPieceMoved_(PieceType::NONE)
, lastRejectedMoveReason_(Chess::MoveValidity::VALID_MOVE)
{

}

FakeOutputSystem::~FakeOutputSystem()
{

}

void FakeOutputSystem::showTextToUser(const char* displayString)
{
   mostRecentOutput_ = displayString;
   capturedOutput_.push_back(displayString);
}

size_t FakeOutputSystem::size() const
{
   return capturedOutput_.size();
}

string FakeOutputSystem::mostRecentOutput() const
{
   return mostRecentOutput_;
}

bool FakeOutputSystem::contains(const string& outputEntry) const
{
   for (list<string>::const_iterator it = capturedOutput_.begin(); it != capturedOutput_.end(); it++)
      {
         if (*it == outputEntry)
         {
            return true;
         }
      }

   return false;
}

void FakeOutputSystem::initializeChessUserInterface()
{ 
    return;
}

void FakeOutputSystem::endUserInteraction()
{
    showTextToUser("quitting chess...");
}

void FakeOutputSystem::resetUxForNewGame()
{
    showTextToUser("New game requested...");
    showTextToUser("you are playing as white...");
    showTextToUser("please enter a move in fully specified notation...");
}

void FakeOutputSystem::displayMoveToUser(const ChessMove &move, const I_ReadOnlyChessBoard & board)
{
    mostRecentMove_ = move;
    const I_ChessPiece* piece = board.pieceAt(move.startingSquare());
    if (piece != nullptr)
    {
        lastPieceMoved_ = piece->pieceType();
    }
    else
    {
        lastPieceMoved_ = PieceType::NONE;
    }
    
}

ChessMove FakeOutputSystem::lastMoveDisplayedToUser() const
{
    return mostRecentMove_;
}

PieceType FakeOutputSystem::lastPieceMoved() const
{
    return lastPieceMoved_;
}

void FakeOutputSystem::rejectMoveAttempt(Chess::MoveValidity validity) {
    lastRejectedMoveReason_ = validity;
}

Chess::MoveValidity FakeOutputSystem::lastRejectedMoveReason() const{
    return lastRejectedMoveReason_;
}
