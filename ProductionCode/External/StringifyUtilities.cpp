//
//  StringifyUtilities.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-21.
//

#include "StringifyUtilities.hpp"

std::string Chess::chessPieceTypeName(PieceType type)
{
    switch (type)
    {
        case PieceType::PAWN:
        {
            return "Pawn";
        }
        case PieceType::BISHOP:
        {
            return "Bishop";
        }
        case PieceType::KNIGHT:
        {
            return "Knight";
        }
        case PieceType::ROOK:
        {
            return "Rook";
        }
        case PieceType::QUEEN:
        {
            return "Queen";
        }
        case PieceType::KING:
        {
            return "King";
        }
        default:
        {
            break;
        }
    }
    return "Invalid Piece Type";
}
