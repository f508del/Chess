//
//  ChessMove.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "ChessMove.hpp"
#include "OutputErrorDefines.hpp"

using namespace std;

ChessMove::ChessMove()
{
   resetState();
}

string ChessMove::toString() const
{
   if (!isOnTheBoard())
   {
      return OutputErrorDefines::MOVE_NOT_ON_BOARD_ERROR;
   }

   char resultString[5];
   sprintf(resultString, "%c%u%c%u", startingSquare_.file(),
           startingSquare_.rank(), endingSquare_.file(), endingSquare_.rank());
   resultString[4] = '\0';
   return resultString;
}

bool ChessMove::populateFromString(const string& moveString)
{
   resetState();
   if (moveString.length() != 4)
   {
      return false;
   }
   char startingFile = '\0';
   unsigned int startingRank = 0;
   char endingFile = '\0';
   unsigned int endingRank = 0;
   sscanf(moveString.c_str(), "%c%u%c%u", &startingFile, &startingRank, &endingFile, &endingRank);

   startingSquare_ = ChessSquare(startingFile, startingRank);
   endingSquare_ = ChessSquare(endingFile, endingRank);

   return isOnTheBoard();
}

const ChessSquare& ChessMove::startingSquare() const
{
   return startingSquare_;
}

const ChessSquare& ChessMove::endingSquare() const
{
   return endingSquare_;
}

bool ChessMove::isOnTheBoard() const
{
   return (startingSquare_.isSquareOnTheBoard() && endingSquare_.isSquareOnTheBoard());
}

void ChessMove::resetState()
{
   startingSquare_ = ChessSquare();
   endingSquare_ = ChessSquare();
}
