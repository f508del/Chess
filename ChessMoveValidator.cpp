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
#include "I_ChessPiece.hpp"
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
   I_ChessPiece* currentPiece = board_.pieceAt(currentMove.startingSquare());
   if (nullptr == currentPiece)
   {
      commentOnLastMove_ = NO_PIECE_AT_COORDINATES_ERROR;
      return false;
   }

   ExtendedSet<ChessSquare> potentialEmptyBoardMoves = currentPiece->potentialEmptyBoardMovesFrom(currentMove.startingSquare());

   if (!potentialEmptyBoardMoves.contains(currentMove.endingSquare()))
   {
      commentOnLastMove_ = PIECE_CANNOT_CURRENTLY_MOVE_ERROR;
      return false;
   }

   commentOnLastMove_ = currentMove.toString();
   return true;
}

string ChessMoveValidator::commentOnLastMove() const
{
   return commentOnLastMove_;
}
