//
//  Pawn.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Pawn.hpp"

Pawn::Pawn()
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

   potentialMoves.insert(ChessSquare(startingSquare.file(), startingSquare.rank() + 1));
   if (startingSquare.rank() == 2)
   {
      potentialMoves.insert(ChessSquare(startingSquare.file(), startingSquare.rank() + 2));
   }
   return potentialMoves;
}
