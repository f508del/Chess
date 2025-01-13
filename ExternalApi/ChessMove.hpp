//
//  ChessMove.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

#include <string>
#include "ScopedPointer.hpp"
#include "ChessSquare.hpp"

struct ChessMove
{
public:
   ChessMove();
   bool isOnTheBoard() const;
   std::string toString() const;
   bool populateFromString(const std::string& moveString);

   const ChessSquare& startingSquare() const;
   const ChessSquare& endingSquare() const;

private:
   void resetState();

private:
   ChessSquare startingSquare_;
   ChessSquare endingSquare_;
};
