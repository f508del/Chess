//
//  King.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-23.
//

#include "King.hpp"

using namespace Chess;

King::King(PieceAffiliation affiliation)
: affiliation_(affiliation)
{
    
}

King::~King()
{
    
}

ExtendedSet<ChessSquare> King::potentialEmptyBoardMovesFrom(const ChessSquare &startingSquare) const
{
    ExtendedSet<ChessSquare> potentialMoves;
    ChessSquare increasingRankDestination(startingSquare.file(), startingSquare.rank() + 1);
    if (increasingRankDestination.isSquareOnTheBoard())
    {
        potentialMoves.insert(increasingRankDestination);
    }
    
    ChessSquare decreasingRankDestination(startingSquare.file(), startingSquare.rank() - 1);
    if (decreasingRankDestination.isSquareOnTheBoard())
    {
        potentialMoves.insert(decreasingRankDestination);
    }
    
    ChessSquare increasingFileDestination(char(startingSquare.file() + 1), startingSquare.rank());
    if (increasingFileDestination.isSquareOnTheBoard())
    {
        potentialMoves.insert(increasingFileDestination);
    }
    
    ChessSquare decreasingFileDestination(char(startingSquare.file() - 1), startingSquare.rank());
    if (decreasingFileDestination.isSquareOnTheBoard())
    {
        potentialMoves.insert(decreasingFileDestination);
    }
    
    // top right array of squares
    ChessSquare topRightDestination(char(startingSquare.file() + 1), startingSquare.rank() + 1);
    if (topRightDestination.isSquareOnTheBoard())
    {
        potentialMoves.insert(topRightDestination);
    }
    
    // Bottom right array of squares
    ChessSquare bottomRightDestination(char(startingSquare.file() + 1), startingSquare.rank() - 1);
    if (bottomRightDestination.isSquareOnTheBoard())
    {
        potentialMoves.insert(bottomRightDestination);
    }
    
    // Bottom Left array of squares
    ChessSquare bottomLeftDestination(char(startingSquare.file() - 1), startingSquare.rank() - 1);
    if (bottomLeftDestination.isSquareOnTheBoard())
    {
        potentialMoves.insert(bottomLeftDestination);
    }
    
    // top left array of squares
    ChessSquare topLeftDestination(char(startingSquare.file() - 1), startingSquare.rank() + 1);
    if (topLeftDestination.isSquareOnTheBoard())
    {
        potentialMoves.insert(topLeftDestination);
    }
    return potentialMoves;
}

ExtendedSet<ChessSquare> King::potentialCaptureMovesFrom(const ChessSquare &startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

ExtendedSet<ChessSquare> King::potentialEmptyOrCaptureMovesFrom(const ChessSquare &startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

PieceAffiliation King::affiliation() const
{
    return affiliation_;
}

PieceType King::pieceType() const
{
    return PieceType::KING;
}

bool King::pieceCanJumpOtherPieces() const
{
    return false;
}

