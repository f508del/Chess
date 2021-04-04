//
//  Knight.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Knight.hpp"

using namespace std;

Knight::Knight()
{
}

Knight::~Knight()
{
}

set<ChessSquare> Knight::potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare)
{
   set<ChessSquare> potentialMoves;

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
