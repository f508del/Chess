//
//  ChessMoveValidator.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#include "ChessMoveValidator.hpp"
#include "ChessMove.hpp"

using namespace std;

ChessMoveValidator::ChessMoveValidator()
: commentOnLastMove_()
{

}

ChessMoveValidator::~ChessMoveValidator()
{

}

bool ChessMoveValidator::isLegalMove(const ChessMove& currentMove)
{
   if (!currentMove.isOnTheBoard())
   {
      commentOnLastMove_ = currentMove.toString();
      return false;
   }
   if (isTouchingBlackPiece(currentMove))
   {
      commentOnLastMove_ = "Nice try, that's the other players piece!";
      return false;
   }
   if (!isTouchingWhitePiece(currentMove))
   {
      commentOnLastMove_ = "No piece exists at these coordinates";
      return false;
   }
   commentOnLastMove_ = currentMove.toString();
   return true;
}

string ChessMoveValidator::commentOnLastMove() const
{
   return commentOnLastMove_;
}

bool ChessMoveValidator::isTouchingWhitePiece(const ChessMove& currentMove) const
{
   // Assume starting board setup for now, expand later.
   if (2 >= currentMove.startingRank)
      {
      return true;
      }
   return false;
}

bool ChessMoveValidator::isTouchingBlackPiece(const ChessMove &currentMove) const
{
   // Assume starting board setup for now, expand later.
   if (7 <= currentMove.startingRank)
      {
      return true;
      }
   return false;
}
