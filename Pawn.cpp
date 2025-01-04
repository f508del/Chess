//
//  Pawn.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Pawn.hpp"

Pawn::Pawn(ChessPieceAffiliation affiliation)
: affiliation_(affiliation)
{
}

Pawn::~Pawn()
{
}

ExtendedSet<ChessSquare> Pawn::potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare)
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
   return potentialMoves;
}

ChessPieceAffiliation Pawn::affiliation() const
{
   return affiliation_;
}

std::string Pawn::pieceName() const
{
   return std::string("Pawn");
}

int Pawn::movementDirectionForCurrentAffiliation() const
{
   if (affiliation_ == WHITE_PIECE)
   {
      return 1;
   }
   return -1;
}

unsigned int Pawn::startingRankForCurrentAffiliation() const
{
   if (affiliation_ == WHITE_PIECE)
   {
      return 2u;
   }
   return 7u;
}

bool Pawn::pieceCanJumpOtherPieces() const
{
    return false;
}

