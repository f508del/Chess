//
//  ChessMoveValidator.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#include "ChessMoveValidator.hpp"

#include "ChessBoard.hpp"
#include "ChessMove.hpp"
#include "ChessSquare.hpp"
#include "OutputErrorDefines.hpp"

using namespace std;
using namespace OutputErrorDefines;

ChessMoveValidator::ChessMoveValidator(const ChessBoard& board)
: commentOnLastMove_()
, board_(board)
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
   if (board_.blackPieceExistsAt(currentMove.startingSquare()))
   {
      commentOnLastMove_ = OPPOSING_PLAYERS_PIECE_ERROR;
      return false;
   }
   if (!board_.anyPieceExistsAt(currentMove.startingSquare()))
   {
      commentOnLastMove_ = NO_PIECE_AT_COORDINATES_ERROR;
      return false;
   }
   commentOnLastMove_ = currentMove.toString();
   return true;
}

string ChessMoveValidator::commentOnLastMove() const
{
   return commentOnLastMove_;
}
