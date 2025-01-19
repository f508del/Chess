//
//  Bishop.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-01.
//

#include "Bishop.hpp"

Bishop::Bishop(ChessPieceAffiliation affiliation)
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

ChessPieceAffiliation Bishop::affiliation() const
{
    return affiliation_;
}

Chess::PieceType Bishop::pieceType() const
{
    return Chess::PieceType::BISHOP;
}

bool Bishop::pieceCanJumpOtherPieces() const
{
    return false;
}
