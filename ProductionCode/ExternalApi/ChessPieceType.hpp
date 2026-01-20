//
//  ChessPieceType.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//
#pragma once

#include <string>

namespace Chess
{
enum class PieceType
{
    NONE = 0,
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
};

PieceType pieceTypeFromString(const std::string& input);
}
