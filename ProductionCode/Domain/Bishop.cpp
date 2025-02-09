//
//  Bishop.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-01.
//

#include "Bishop.hpp"

using namespace Chess;

Bishop::Bishop(PieceAffiliation affiliation)
: affiliation_(affiliation)
{
    
}

Bishop::~Bishop()
{
    
}

ExtendedSet<ChessSquare> Bishop::potentialEmptyBoardMovesFrom(const ChessSquare &startingSquare) const
{
    ExtendedSet<ChessSquare> potentialMoves;
    
    for (int i = 1; i < 7; i++)
    {
        // top right array of squares
        ChessSquare topRightDestination(startingSquare.file() + i, startingSquare.rank() + i);
        if (topRightDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(topRightDestination);
        }
        
        // Bottom right array of squares
        ChessSquare bottomRightDestination(startingSquare.file() + i, startingSquare.rank() - i);
        if (bottomRightDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(bottomRightDestination);
        }
        
        // Bottom Left array of squares
        ChessSquare bottomLeftDestination(startingSquare.file() - i, startingSquare.rank() - i);
        if (bottomLeftDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(bottomLeftDestination);
        }
        
        // top left array of squares
        ChessSquare topLeftDestination(startingSquare.file() - i, startingSquare.rank() + i);
        if (topLeftDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(topLeftDestination);
        }
    }
    return potentialMoves;
}

PieceAffiliation Bishop::affiliation() const
{
    return affiliation_;
}

PieceType Bishop::pieceType() const
{
    return PieceType::BISHOP;
}

bool Bishop::pieceCanJumpOtherPieces() const
{
    return false;
}
