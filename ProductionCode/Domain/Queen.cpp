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
        ChessSquare increasingRankDestination(startingSquare.dep_File(), startingSquare.dep_Rank() + i);
        if (increasingRankDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(increasingRankDestination);
        }
        
        // decreasing ranks
        ChessSquare decreasingRankDestination(startingSquare.dep_File(), startingSquare.dep_Rank() - i);
        if (decreasingRankDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(decreasingRankDestination);
        }
        
        // increasing files
        ChessSquare increasingFileDestination(char(startingSquare.dep_File() + i), startingSquare.dep_Rank());
        if (increasingFileDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(increasingFileDestination);
        }
        
        ChessSquare decreasingFileDestination(char(startingSquare.dep_File() - i), startingSquare.dep_Rank());
        if (decreasingFileDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(decreasingFileDestination);
        }
        
        // top right array of squares
        ChessSquare topRightDestination(char(startingSquare.dep_File() + i), startingSquare.dep_Rank() + i);
        if (topRightDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(topRightDestination);
        }
        
        // Bottom right array of squares
        ChessSquare bottomRightDestination(char(startingSquare.dep_File() + i), startingSquare.dep_Rank() - i);
        if (bottomRightDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(bottomRightDestination);
        }
        
        // Bottom Left array of squares
        ChessSquare bottomLeftDestination(char(startingSquare.dep_File() - i), startingSquare.dep_Rank() - i);
        if (bottomLeftDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(bottomLeftDestination);
        }
        
        // top left array of squares
        ChessSquare topLeftDestination(char(startingSquare.dep_File() - i), startingSquare.dep_Rank() + i);
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

ExtendedSet<ChessSquare> Queen::potentialEmptyOrCaptureMovesFrom(const ChessSquare &startingSquare) const
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



