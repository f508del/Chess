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
    
    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) override;
    
    ChessPieceAffiliation affiliation() const override;
    
    std::string pieceName() const override;
    
    bool pieceCanJumpOtherPieces() const override;
    
private:
   const ChessPieceAffiliation affiliation_;
};
