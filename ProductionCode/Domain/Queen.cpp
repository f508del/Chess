//
//  Queen.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-22.
//

#include "Queen.hpp"

using namespace Chess;

Queen::Queen(PieceAffiliation affiliation)
: affiliation_(affiliation)
{
    
}

Queen::~Queen()
{
    
}

ExtendedSet<ChessSquare> Queen::potentialEmptyBoardMovesFrom(const ChessSquare &startingSquare) const
{
    ExtendedSet<ChessSquare> potentialMoves;
    
    for (int i = 1; i < 8; i++)
    {
        // increasing ranks:
        ChessSquare increasingRankDestination(startingSquare.file(), startingSquare.rank() + i);
        if (increasingRankDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(increasingRankDestination);
        }
        
        // decreasing ranks
        ChessSquare decreasingRankDestination(startingSquare.file(), startingSquare.rank() - i);
        if (decreasingRankDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(decreasingRankDestination);
        }
        
        // increasing files
        ChessSquare increasingFileDestination(char(startingSquare.file() + i), startingSquare.rank());
        if (increasingFileDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(increasingFileDestination);
        }
        
        ChessSquare decreasingFileDestination(char(startingSquare.file() - i), startingSquare.rank());
        if (decreasingFileDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(decreasingFileDestination);
        }
        
        // top right array of squares
        ChessSquare topRightDestination(char(startingSquare.file() + i), startingSquare.rank() + i);
        if (topRightDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(topRightDestination);
        }
        
        // Bottom right array of squares
        ChessSquare bottomRightDestination(char(startingSquare.file() + i), startingSquare.rank() - i);
        if (bottomRightDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(bottomRightDestination);
        }
        
        // Bottom Left array of squares
        ChessSquare bottomLeftDestination(char(startingSquare.file() - i), startingSquare.rank() - i);
        if (bottomLeftDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(bottomLeftDestination);
        }
        
        // top left array of squares
        ChessSquare topLeftDestination(char(startingSquare.file() - i), startingSquare.rank() + i);
        if (topLeftDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(topLeftDestination);
        }
    }
    return potentialMoves;
}

ExtendedSet<ChessSquare> Queen::potentialCaptureMovesFrom(const ChessSquare &startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

PieceAffiliation Queen::affiliation() const
{
    return affiliation_;
}

PieceType Queen::pieceType() const
{
    return PieceType::QUEEN;
}

bool Queen::pieceCanJumpOtherPieces() const
{
    return false;
}
