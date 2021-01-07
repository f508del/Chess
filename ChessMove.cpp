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
   sprintf(resultString, "%c%u%c%u", startingFile, startingRank, endingFile, endingRank);
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
   sscanf(moveString.c_str(), "%c%u%c%u", &startingFile, &startingRank, &endingFile, &endingRank);

   return isOnTheBoard();
}

bool ChessMove::isOnTheBoard() const
{
   return (isValidFile(startingFile) && isValidRank(startingRank) && isValidFile(endingFile) &&
           isValidRank(endingRank));
}

bool ChessMove::isValidFile(char file) const
{
   return (file >= 'a' && file <= 'h');
}

bool ChessMove::isValidRank(unsigned int rank) const
{
   return (rank >= 1 && rank <= 8);
}

void ChessMove::resetState()
{
   startingFile = '\0';
   startingRank = 0;
   endingFile = '\0';
   endingRank = 0;
}
