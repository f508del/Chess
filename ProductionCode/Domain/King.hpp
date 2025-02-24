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
    
    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const;
    ExtendedSet<ChessSquare> potentialCaptureMovesFrom(const ChessSquare& startingSquare) const;
    Chess::PieceAffiliation affiliation() const;
    Chess::PieceType pieceType() const;
    bool pieceCanJumpOtherPieces() const;
    
private:
    const Chess::PieceAffiliation affiliation_;
};
