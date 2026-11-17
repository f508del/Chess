//
//  Pawn.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#pragma once

#include "I_ChessPiece.hpp"
#include <map>

class Pawn : public I_ChessPiece
{
public:
    Pawn(Chess::PieceAffiliation affiliation);
    virtual ~Pawn();

    ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    ExtendedSet<ChessSquare> potentialEmptyOrCaptureMovesFrom(const ChessSquare& startingSquare) const override;
    
    Chess::PieceAffiliation affiliation() const override;
    Chess::PieceType pieceType() const override;
    bool pieceCanJumpOtherPieces() const override;

private:
    int movementDirectionForCurrentAffiliation() const;

private:
    const Chess::PieceAffiliation affiliation_;
    std::map<ChessSquare, ExtendedSet<ChessSquare> > emptyBoardMoves_;
    std::map<ChessSquare, ExtendedSet<ChessSquare> > captureMoves_;
};

