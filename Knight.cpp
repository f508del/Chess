//
//  Knight.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Knight.hpp"

Knight::Knight(ChessPieceAffiliation affiliation)
: affiliation_(affiliation)
{
}

Knight::~Knight()
{
}

ExtendedSet<ChessSquare> Knight::potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare)
{
   ExtendedSet<ChessSquare> potentialMoves;

   // forward "L"s:
   ChessSquare destinationSquare(startingSquare.file() + 1, startingSquare.rank() + 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(startingSquare.file() - 1, startingSquare.rank() + 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   // backward "L"s:
   destinationSquare = ChessSquare(startingSquare.file() + 1, startingSquare.rank() - 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(startingSquare.file() - 1, startingSquare.rank() - 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }


   // rightward "L"s
   destinationSquare = ChessSquare(startingSquare.file() + 2, startingSquare.rank() + 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(startingSquare.file() + 2, startingSquare.rank() - 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   // leftward "L"s
   destinationSquare = ChessSquare(startingSquare.file() - 2, startingSquare.rank() + 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(startingSquare.file() - 2, startingSquare.rank() - 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }
   return potentialMoves;
}

ChessPieceAffiliation Knight::affiliation() const
{
   return affiliation_;
}

std::string Knight::pieceName() const
{
   return std::string("Knight");
}

bool Knight::pieceCanJumpOtherPieces() const
{
    return true;
}


