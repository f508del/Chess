//
//  King.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-23.
//

#pragma once

#include "I_ChessPiece.hpp"

class King : public I_ChessPiece
{
public:
    King(Chess::PieceAffiliation affiliation);
    virtual ~King();
    
    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialEmptyOrCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    
    Chess::PieceAffiliation affiliation() const override;
    Chess::PieceType pieceType() const override;
    bool pieceCanJumpOtherPieces() const override;
    
private:
    const Chess::PieceAffiliation affiliation_;
};
