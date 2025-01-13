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
#include <string>

class I_ChessPiece
{
public:
    virtual ~I_ChessPiece();

    virtual ExtendedSet<ChessSquare> potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const = 0;
    virtual ChessPieceAffiliation affiliation() const = 0;
    virtual std::string pieceName() const = 0;
    virtual bool pieceCanJumpOtherPieces() const = 0;
};
