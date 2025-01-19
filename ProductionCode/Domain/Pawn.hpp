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

    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const override;
    ChessPieceAffiliation affiliation() const override;
    Chess::PieceType pieceType() const override;
    bool pieceCanJumpOtherPieces() const override;

private:
    int movementDirectionForCurrentAffiliation() const;
    unsigned int startingRankForCurrentAffiliation() const;

private:
    const ChessPieceAffiliation affiliation_;
};

