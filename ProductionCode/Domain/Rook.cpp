//
//  Rook.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-16.
//

#include "Rook.hpp"

using namespace Chess;

Rook::Rook(PieceAffiliation affiliation)
: affiliation_(affiliation)
{
    
}

Rook::~Rook()
{
    
}

PieceType Rook::pieceType() const
{
    return PieceType::ROOK;
}

bool Rook::pieceCanJumpOtherPieces() const
{
    return false;
}

Chess::PieceAffiliation Rook::affiliation() const
{ 
    return affiliation_;
}

ExtendedSet<ChessSquare> Rook::potentialEmptyBoardMovesFrom(const ChessSquare &startingSquare) const
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
        ChessSquare increasingFileDestination(startingSquare.file() + i, startingSquare.rank());
        if (increasingFileDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(increasingFileDestination);
        }
        
        ChessSquare decreasingFileDestination(startingSquare.file() - i, startingSquare.rank());
        if (decreasingFileDestination.isSquareOnTheBoard())
        {
            potentialMoves.insert(decreasingFileDestination);
        }
    }
    
    return potentialMoves;
}

ExtendedSet<ChessSquare> Rook::potentialCaptureMovesFrom(const ChessSquare& startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}
