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
    Bishop(Chess::PieceAffiliation affiliation);
    virtual ~Bishop();
    
    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    Chess::PieceAffiliation affiliation() const override;
    
    Chess::PieceType pieceType() const override;
    
    bool pieceCanJumpOtherPieces() const override;
    
private:
   const Chess::PieceAffiliation affiliation_;
};
