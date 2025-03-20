//
//  ChessPieceAffiliation.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-17.
//

#include "ChessPieceAffiliation.hpp"

#include <cstdlib>

namespace Chess
{
PieceAffiliation randomPieceAffiliation()
{
    int randomInteger = rand();
    
    if (randomInteger % 2)
    {
        return PieceAffiliation::BLACK_PIECE;
    }
    else
    {
        return PieceAffiliation::WHITE_PIECE;
    }
}

PieceAffiliation oppositePieceAffiliation(const PieceAffiliation affiliation)
{
    return (affiliation == PieceAffiliation::WHITE_PIECE ? PieceAffiliation::BLACK_PIECE : PieceAffiliation::WHITE_PIECE);
}
}
