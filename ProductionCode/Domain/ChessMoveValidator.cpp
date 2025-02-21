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
using namespace Chess;

ChessMoveValidator::ChessMoveValidator(const ChessBoard& board)
: commentOnLastMove_()
, board_(board)
{

}

ChessMoveValidator::~ChessMoveValidator()
{

}

MoveValidity ChessMoveValidator::validateMove(const ChessMove& currentMove)
{
   if (!currentMove.isOnTheBoard())
   {
       commentOnLastMove_ = currentMove.toString();
       return MoveValidity::END_SQUARE_NOT_ON_BOARD;
   }

   const I_ChessPiece* currentPiece = board_.pieceAt(currentMove.startingSquare());
   if (nullptr == currentPiece)
   {
       commentOnLastMove_ = NO_PIECE_AT_COORDINATES_ERROR;
       return MoveValidity::NO_PIECE_AT_STARTING_LOCATION;
   }
    
    if (currentPiece->pieceType() == PieceType::PAWN)
    {
        // Special case for pawns that try to capture onto an empty square:
        if (!board_.anyPieceExistsAt(currentMove.endingSquare()) && currentMove.startingSquare().file() != currentMove.endingSquare().file())
        {
            return MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE;
        }
        
        // Special case for pawns that try to move vertically to capture another piece
        if (board_.anyPieceExistsAt(currentMove.endingSquare()) && currentMove.startingSquare().file() == currentMove.endingSquare().file())
        {
            return MoveValidity::DESTINATION_BLOCKED_BY_EXISTING_PIECE;
        }
    }

   if (currentPiece->affiliation() != board_.playerToMakeNextMove())
   {
       commentOnLastMove_ = OPPOSING_PLAYERS_PIECE_ERROR;
       return MoveValidity::OPPOSING_PLAYERS_PIECE;
   }

   ExtendedSet<ChessSquare> potentialEmptyBoardMoves = currentPiece->potentialEmptyBoardMovesFrom(currentMove.startingSquare());

   if (!potentialEmptyBoardMoves.contains(currentMove.endingSquare()))
   {
       commentOnLastMove_ = PIECE_CANNOT_CURRENTLY_MOVE_ERROR;
       return MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE;
   }
    
    if (!board_.squaresBetweenEndPointsAreEmpty(currentMove) && !currentPiece->pieceCanJumpOtherPieces())
    {
        commentOnLastMove_ = MOVE_IS_BLOCKED_ERROR;
        return MoveValidity::PATH_BLOCKED_BY_OTHER_PIECES;
    }

    if (board_.anyPieceExistsAt(currentMove.endingSquare()) &&
        (currentPiece->affiliation() ==
         (board_.pieceAt(currentMove.endingSquare())->affiliation())))
   {
       commentOnLastMove_ = PIECE_CANNOT_CURRENTLY_MOVE_ERROR;
       return MoveValidity::DESTINATION_BLOCKED_BY_EXISTING_PIECE;
   }

   commentOnLastMove_ = "";
   return MoveValidity::VALID_MOVE;
}

string ChessMoveValidator::reasonLastMoveWasIllegal() const
{
   return commentOnLastMove_;
}
