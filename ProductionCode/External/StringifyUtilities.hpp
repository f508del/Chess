//
//  StringifyUtilities.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-21.
//

#include "ChessPieceType.hpp"

class ChessSquare;

namespace Chess
{
    std::string toString(Chess::PieceType type);
    std::string toString(const ChessSquare& square);
}
