//
//  Pawn.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Pawn.hpp"

using namespace Chess;

Pawn::Pawn(PieceAffiliation affiliation)
: affiliation_(affiliation)
{
}

Pawn::~Pawn()
{
}

ExtendedSet<ChessSquare> Pawn::potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const
{
   ExtendedSet<ChessSquare> potentialMoves;
   if (!startingSquare.isSquareOnTheBoard() || startingSquare.rank() == 1 ||
       startingSquare.rank() == 8)
   {
      return potentialMoves;
   }

   potentialMoves.insert(ChessSquare(startingSquare.file(), startingSquare.rank()
                                     + (1 * movementDirectionForCurrentAffiliation())));
   if (startingSquare.rank() == startingRankForCurrentAffiliation())
   {
      potentialMoves.insert(ChessSquare(startingSquare.file(), startingSquare.rank()
                                        + (2 * movementDirectionForCurrentAffiliation())));
   }
    
    // Capture moves
    ChessSquare rightwardCaptureMove(startingSquare.file() + 1, startingSquare.rank()
                                      + (1 * movementDirectionForCurrentAffiliation()));
    ChessSquare leftwardCaptureMove(startingSquare.file() - 1, startingSquare.rank()
                                      + (1 * movementDirectionForCurrentAffiliation()));
    if (rightwardCaptureMove.isSquareOnTheBoard())
    {
        potentialMoves.insert(rightwardCaptureMove);
    }
    if (leftwardCaptureMove.isSquareOnTheBoard())
    {
        potentialMoves.insert(leftwardCaptureMove);
    }
   return potentialMoves;
}

ExtendedSet<ChessSquare> Pawn::potentialCaptureMovesFrom(const ChessSquare& startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

PieceAffiliation Pawn::affiliation() const
{
   return affiliation_;
}

PieceType Pawn::pieceType() const
{
    return PieceType::PAWN;
}

int Pawn::movementDirectionForCurrentAffiliation() const
{
   if (affiliation_ == PieceAffiliation::WHITE_PIECE)
   {
      return 1;
   }
   return -1;
}

unsigned int Pawn::startingRankForCurrentAffiliation() const
{
   if (affiliation_ == PieceAffiliation::WHITE_PIECE)
   {
      return 2u;
   }
   return 7u;
}

bool Pawn::pieceCanJumpOtherPieces() const
{
    return false;
}

