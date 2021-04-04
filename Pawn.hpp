//
//  Pawn.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#pragma once

#include "I_ChessPiece.hpp"

class Pawn : public I_ChessPiece
{
public:
   Pawn();
   virtual ~Pawn();

   std::set<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) override;
};

