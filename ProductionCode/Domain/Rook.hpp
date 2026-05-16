//
//  Rook.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-16.
//

#pragma once

#include "I_ChessPiece.hpp"

class Rook : public I_ChessPiece
{
public:
    Rook(Chess::PieceAffiliation affiliation);
    virtual ~Rook();
    
    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialEmptyOrCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    
    Chess::PieceAffiliation affiliation() const override;
    Chess::PieceType pieceType() const override;
    bool pieceCanJumpOtherPieces() const override;
    
private:
   const Chess::PieceAffiliation affiliation_;
};
