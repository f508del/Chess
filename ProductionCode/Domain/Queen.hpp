//
//  Queen.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-22.
//

#pragma once

#include "I_ChessPiece.hpp"

class Queen : public I_ChessPiece
{
public:
    Queen(Chess::PieceAffiliation affiliation);
    virtual ~Queen();
    
    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    Chess::PieceAffiliation affiliation() const override;
    Chess::PieceType pieceType() const override;
    bool pieceCanJumpOtherPieces() const override;
    
private:
    const Chess::PieceAffiliation affiliation_;
};
