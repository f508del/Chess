//
//  Knight.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#pragma once

#include "I_ChessPiece.hpp"

class Knight : public I_ChessPiece
{
public:
   Knight();
   virtual ~Knight();

   ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) override;
};
