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
    std::vector<File> allFilesToMove = allFiles();
    for (auto startingFileIterator = allFilesToMove.begin(); startingFileIterator != allFilesToMove.end(); ++startingFileIterator)
    {
        std::vector<Rank> allRanksToMove = allRanks();
        for (auto startingRankIterator = allRanksToMove.begin(); startingRankIterator != allRanksToMove.end(); ++startingRankIterator)
        {
            populateEmptyBoardMovesFromStartLocation(*startingFileIterator, *startingRankIterator);
        }
    }
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
    if (emptyBoardMoves_.find(startingSquare) != emptyBoardMoves_.end())
    {
        return emptyBoardMoves_.at(startingSquare);
    }
    return ExtendedSet<ChessSquare>();
}

ExtendedSet<ChessSquare> Rook::potentialCaptureMovesFrom(const ChessSquare& startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

ExtendedSet<ChessSquare> Rook::potentialEmptyOrCaptureMovesFrom(const ChessSquare &startingSquare) const
{ 
    return potentialEmptyBoardMovesFrom(startingSquare);
}

void Rook::populateEmptyBoardMovesFromStartLocation(Chess::File startingFile, Chess::Rank startingRank)
{
    // Handle the file squares
    ExtendedSet<ChessSquare> moves;
    std::vector<Rank> destinationRanks = allRanksExcept(startingRank);
    for (auto endingRankIterator = destinationRanks.begin(); endingRankIterator !=destinationRanks.end(); ++endingRankIterator)
    {
        moves.insert(ChessSquare(startingFile, *endingRankIterator));
    }
    // add rank squares
    std::vector<File> destinationFiles = allFilesExcept(startingFile);
    for (auto endingFileIterator = destinationFiles.begin(); endingFileIterator != destinationFiles.end(); ++endingFileIterator)
    {
        moves.insert(ChessSquare(*endingFileIterator, startingRank));
    }
    emptyBoardMoves_[ChessSquare(startingFile, startingRank)] = moves;
}


