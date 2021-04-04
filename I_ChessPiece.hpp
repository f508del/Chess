//
//  I_ChessPiece.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#pragma once

#include <set>
#include "ChessSquare.hpp"

class I_ChessPiece
{
public:
   virtual ~I_ChessPiece();

   virtual std::set<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) = 0;
};
