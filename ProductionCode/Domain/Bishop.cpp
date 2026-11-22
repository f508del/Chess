//
//  Bishop.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-01.
//

#include "Bishop.hpp"

using namespace Chess;
using namespace std;

Bishop::Bishop(PieceAffiliation affiliation)
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

Bishop::~Bishop()
{
    
}

ExtendedSet<ChessSquare> Bishop::potentialEmptyBoardMovesFrom(const ChessSquare &startingSquare) const
{
    if (emptyBoardMoves_.find(startingSquare) != emptyBoardMoves_.end())
    {
        return emptyBoardMoves_.at(startingSquare);
    }
    return ExtendedSet<ChessSquare>();
}

ExtendedSet<ChessSquare> Bishop::potentialCaptureMovesFrom(const ChessSquare& startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

ExtendedSet<ChessSquare> Bishop::potentialEmptyOrCaptureMovesFrom(const ChessSquare &startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
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

void Bishop::populateEmptyBoardMovesFromStartLocation(File startingFile, Rank startingRank)
{
    vector<Rank> ranksAboveStartingRank = allRanksIncreasingGreaterThan(startingRank);
    vector<Rank> ranksBelowStartingRank = allRanksDecreasingLessThan(startingRank);
    vector<File> filesAboveStartingFile = allFilesIncreasingGreaterThan(startingFile);
    vector<File> filesBelowStartingFile = allFilesDecreasingLessThan(startingFile);
    
    ExtendedSet<ChessSquare> possibleMoves;
    
    // increasing rank and file path:
    auto destinationRankIterator = ranksAboveStartingRank.begin();
    for (auto destinationFileIterator = filesAboveStartingFile.begin(); destinationFileIterator != filesAboveStartingFile.end(); ++destinationFileIterator)
    {
        if (destinationRankIterator == ranksAboveStartingRank.end())
        {
            break;
        }
        possibleMoves.insert(ChessSquare(*destinationFileIterator, *destinationRankIterator));
        destinationRankIterator++;
    }
    
    // increasing rank, and decreasing file path:
    destinationRankIterator = ranksAboveStartingRank.begin();
    for (auto destinationFileIterator = filesBelowStartingFile.begin(); destinationFileIterator != filesBelowStartingFile.end(); ++destinationFileIterator)
    {
        if (destinationRankIterator == ranksAboveStartingRank.end())
        {
            break;
        }
        possibleMoves.insert(ChessSquare(*destinationFileIterator, *destinationRankIterator));
        destinationRankIterator++;
    }
    
    // decreasing rank, and decreasing file path:
    destinationRankIterator = ranksBelowStartingRank.begin();
    for (auto destinationFileIterator = filesBelowStartingFile.begin(); destinationFileIterator != filesBelowStartingFile.end(); ++destinationFileIterator)
    {
        if (destinationRankIterator == ranksBelowStartingRank.end())
        {
            break;
        }
        possibleMoves.insert(ChessSquare(*destinationFileIterator, *destinationRankIterator));
        destinationRankIterator++;
    }
    
    // decreasing rank and increasing file path:
    destinationRankIterator = ranksBelowStartingRank.begin();
    for (auto destinationFileIterator = filesAboveStartingFile.begin(); destinationFileIterator != filesAboveStartingFile.end(); ++destinationFileIterator)
    {
        if (destinationRankIterator == ranksBelowStartingRank.end())
        {
            break;
        }
        possibleMoves.insert(ChessSquare(*destinationFileIterator, *destinationRankIterator));
        destinationRankIterator++;
    }
    
    emptyBoardMoves_[ChessSquare(startingFile, startingRank)] = possibleMoves;
}
