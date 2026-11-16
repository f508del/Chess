//
//  Pawn.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Pawn.hpp"

using namespace Chess;

Pawn::Pawn(PieceAffiliation affiliation)
: affiliation_(affiliation)
{
    if (Chess::PieceAffiliation::WHITE_PIECE == affiliation)
    {
        std::vector<File> allFilesToMove = Chess::allFiles();
        for (auto fileIterator = allFilesToMove.begin(); fileIterator != allFilesToMove.end(); ++fileIterator)
        {
            ExtendedSet<ChessSquare> moves;
            moves.insert(ChessSquare(*fileIterator, 3));
            moves.insert(ChessSquare(*fileIterator, 4));
            emptyBoardMoves_[ChessSquare(*fileIterator, 2)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 4));
            emptyBoardMoves_[ChessSquare(*fileIterator, 3)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 5));
            emptyBoardMoves_[ChessSquare(*fileIterator, 4)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 6));
            emptyBoardMoves_[ChessSquare(*fileIterator, 5)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 7));
            emptyBoardMoves_[ChessSquare(*fileIterator, 6)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 8));
            emptyBoardMoves_[ChessSquare(*fileIterator, 7)] = moves;
        }
    }
    else // Black pawn:
    {
        std::vector<File> allFilesToMove = Chess::allFiles();
        for (auto fileIterator = allFilesToMove.begin(); fileIterator != allFilesToMove.end(); ++fileIterator)
        {
            ExtendedSet<ChessSquare> moves;
            moves.insert(ChessSquare(*fileIterator, 5));
            moves.insert(ChessSquare(*fileIterator, 6));
            emptyBoardMoves_[ChessSquare(*fileIterator, 7)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 5));
            emptyBoardMoves_[ChessSquare(*fileIterator, 6)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 4));
            emptyBoardMoves_[ChessSquare(*fileIterator, 5)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 3));
            emptyBoardMoves_[ChessSquare(*fileIterator, 4)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 2));
            emptyBoardMoves_[ChessSquare(*fileIterator, 3)] = moves;
            
            moves.clear();
            moves.insert(ChessSquare(*fileIterator, 1));
            emptyBoardMoves_[ChessSquare(*fileIterator, 2)] = moves;
        }
    }
}

Pawn::~Pawn()
{
}

ExtendedSet<ChessSquare> Pawn::potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const
{
    if (emptyBoardMoves_.find(startingSquare) != emptyBoardMoves_.end())
    {
        ExtendedSet<ChessSquare> moves = emptyBoardMoves_.at(startingSquare);
        return emptyBoardMoves_.at(startingSquare);
    }
    return ExtendedSet<ChessSquare>();
}

ExtendedSet<ChessSquare> Pawn::potentialCaptureMovesFrom(const ChessSquare& startingSquare) const
{
    ExtendedSet<ChessSquare> potentialMoves;
    if (!isValidStartingSquare(startingSquare))
    {
        return potentialMoves;
    }
    
    // Capture moves
    ChessSquare rightwardCaptureMove(char(startingSquare.file() + 1), startingSquare.rank()
                                    + (1 * movementDirectionForCurrentAffiliation()));
    ChessSquare leftwardCaptureMove(char(startingSquare.file() - 1), startingSquare.rank()
                                    + (1 * movementDirectionForCurrentAffiliation()));
    if (rightwardCaptureMove.isSquareOnTheBoard())
    {
        potentialMoves.insert(rightwardCaptureMove);
    }
    if (leftwardCaptureMove.isSquareOnTheBoard())
    {
        potentialMoves.insert(leftwardCaptureMove);
    }
    return potentialMoves;
}

ExtendedSet<ChessSquare> Pawn::potentialEmptyOrCaptureMovesFrom(const ChessSquare &startingSquare) const
{
    ExtendedSet<ChessSquare> nonCaptureMoves = potentialEmptyBoardMovesFrom(startingSquare);
    ExtendedSet<ChessSquare> captureMoves =  potentialCaptureMovesFrom(startingSquare);
    ExtendedSet<ChessSquare> currentPiecePotentialMoves;
    std::set_union(nonCaptureMoves.begin(), nonCaptureMoves.end(), captureMoves.begin(), captureMoves.end(), std::inserter(currentPiecePotentialMoves, currentPiecePotentialMoves.begin()));
    return currentPiecePotentialMoves;
}

PieceAffiliation Pawn::affiliation() const
{
   return affiliation_;
}

PieceType Pawn::pieceType() const
{
    return PieceType::PAWN;
}

int Pawn::movementDirectionForCurrentAffiliation() const
{
   if (affiliation_ == PieceAffiliation::WHITE_PIECE)
   {
      return 1;
   }
   return -1;
}

unsigned int Pawn::startingRankForCurrentAffiliation() const
{
   if (affiliation_ == PieceAffiliation::WHITE_PIECE)
   {
      return 2u;
   }
   return 7u;
}

bool Pawn::pieceCanJumpOtherPieces() const
{
    return false;
}

bool Pawn::isValidStartingSquare(const ChessSquare& square) const noexcept
{
    return square.isSquareOnTheBoard() && square.rank() != 1 && square.rank() != 8;
}
