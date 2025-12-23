//
//  ChessMove.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "ChessMoveRequest.hpp"

using namespace std;

ChessMoveRequest::ChessMoveRequest()
{
   resetState();
}

ChessMoveRequest::ChessMoveRequest(const std::string& moveString)
{
    if (!populateFromString(moveString))
    {
        resetState();
    }
}

ChessMoveRequest::ChessMoveRequest(const ChessSquare& startingSquare, const ChessSquare& endingSquare)
: startingSquare_(startingSquare)
, endingSquare_(endingSquare)
{
    
}

bool ChessMoveRequest::populateFromString(const string& moveString)
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

const ChessSquare& ChessMoveRequest::startingSquare() const
{
   return startingSquare_;
}

const ChessSquare& ChessMoveRequest::endingSquare() const
{
   return endingSquare_;
}

bool ChessMoveRequest::isOnTheBoard() const
{
   return (startingSquare_.isSquareOnTheBoard() && endingSquare_.isSquareOnTheBoard());
}

void ChessMoveRequest::resetState()
{
   startingSquare_ = ChessSquare();
   endingSquare_ = ChessSquare();
}

bool ChessMoveRequest::operator==(const ChessMoveRequest& move) const
{
    return ((startingSquare_ == move.startingSquare_) && (endingSquare_ == move.endingSquare_));
}
