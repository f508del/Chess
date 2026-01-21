//
//  StringifyUtilities.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-21.
//

#include "StringifyUtilities.hpp"
#include "ChessSquare.hpp"

std::string Chess::toString(PieceType type)
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

std::string Chess::toString(const ChessSquare& square)
{
    std::string stringSquare;
    char resultString[3];
    snprintf(resultString, 3, "%c%u", square.file(), square.rank());
    resultString[2] = '\0';
    stringSquare = resultString;
    return stringSquare;
}
