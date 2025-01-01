//
//  Bishop.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-01.
//

#pragma once

#include "I_ChessPiece.hpp"

class Bishop : public I_ChessPiece
{
public:
    Bishop(ChessPieceAffiliation affiliation);
    virtual ~Bishop();
    
    virtual ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) override;
    
    virtual ChessPieceAffiliation affiliation() const override;
    
    virtual std::string pieceName() const override;
    
private:
   const ChessPieceAffiliation affiliation_;
};
