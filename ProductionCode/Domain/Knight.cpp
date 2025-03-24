//
//  Knight.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Knight.hpp"

using namespace Chess;

Knight::Knight(PieceAffiliation affiliation)
: affiliation_(affiliation)
{
}

Knight::~Knight()
{
}

ExtendedSet<ChessSquare> Knight::potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const
{
   ExtendedSet<ChessSquare> potentialMoves;

   // forward "L"s:
   ChessSquare destinationSquare(char(startingSquare.file() + 1), startingSquare.rank() + 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(char(startingSquare.file() - 1), startingSquare.rank() + 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   // backward "L"s:
   destinationSquare = ChessSquare(char(startingSquare.file() + 1), startingSquare.rank() - 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(char(startingSquare.file() - 1), startingSquare.rank() - 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }


   // rightward "L"s
   destinationSquare = ChessSquare(char(startingSquare.file() + 2), startingSquare.rank() + 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(char(startingSquare.file() + 2), startingSquare.rank() - 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   // leftward "L"s
   destinationSquare = ChessSquare(char(startingSquare.file() - 2), startingSquare.rank() + 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(char(startingSquare.file() - 2), startingSquare.rank() - 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }
   return potentialMoves;
}

ExtendedSet<ChessSquare> Knight::potentialCaptureMovesFrom(const ChessSquare& startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

PieceAffiliation Knight::affiliation() const
{
   return affiliation_;
}

PieceType Knight::pieceType() const
{
    return PieceType::KNIGHT;
}

bool Knight::pieceCanJumpOtherPieces() const
{
    return true;
}


