//
//  ChessMove.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

#include <string>

struct ChessMove
{
public:
   ChessMove();
   bool isOnTheBoard() const;
   std::string toString() const;
   bool populateFromString(const std::string& moveString);

   char startingFile;
   unsigned int startingRank;

   char endingFile;
   unsigned int endingRank;

private:
   bool isValidFile(char file) const;
   bool isValidRank(unsigned int rank) const;
   void resetState();
};
