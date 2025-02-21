//
//  I_ChessPiece.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#pragma once

#include "ExtendedSet.hpp"
#include "ChessSquare.hpp"
#include "ChessPieceAffiliation.hpp"
#include "ChessPieceType.hpp"
#include <string>

class I_ChessPiece
{
public:
    virtual ~I_ChessPiece();

    virtual ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const = 0;
    virtual ExtendedSet<ChessSquare> potentialCaptureMovesFrom(const ChessSquare& startingSquare) const = 0;
    virtual Chess::PieceAffiliation affiliation() const = 0;
    virtual Chess::PieceType pieceType() const = 0;
    virtual bool pieceCanJumpOtherPieces() const = 0;
};
