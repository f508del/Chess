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
   Pawn(ChessPieceAffiliation affiliation);
   virtual ~Pawn();

   ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) override;
   ChessPieceAffiliation affiliation() const override;
   std::string pieceName() const override;

private:
   const ChessPieceAffiliation affiliation_;
};

