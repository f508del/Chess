//
//  Knight.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#pragma once

#include "I_ChessPiece.hpp"
#include <map>

class Knight : public I_ChessPiece
{
public:
    Knight(Chess::PieceAffiliation affiliation);
    virtual ~Knight();

    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialEmptyOrCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    
    Chess::PieceAffiliation affiliation() const override;
    Chess::PieceType pieceType() const override;
    bool pieceCanJumpOtherPieces() const override;

private:
    std::map<ChessSquare, ExtendedSet<ChessSquare> > emptyBoardMoves_;
    const Chess::PieceAffiliation affiliation_;
};
