//
//  ChessMove.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "ChessMove.hpp"

ChessMove::ChessMove()
{
   resetState();
}

std::string ChessMove::toString() const
{
   if (!isOnTheBoard())
      {
         return "Move is not validly on the board";
      }

   char resultString[5];
   resultString[0] = startingFile;
   sprintf(resultString, "%c%u%c%u", startingFile, startingRank, endingFile, endingRank);
   resultString[4] = '\0';
   return resultString;
}

bool ChessMove::populateFromString(const std::string& moveString)
{
   resetState();
   if (moveString.length() != 4)
      return false;
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
