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
        std::vector<File> allFilesToMove = allFiles();
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
    
    // Capture moves
    for (unsigned int rank = 2; rank <= 7; rank++)
    {
        ExtendedSet<ChessSquare> moves;
        moves.insert(ChessSquare(File::B, rank + movementDirectionForCurrentAffiliation()));
        captureMoves_[ChessSquare(File::A, rank)] = moves;
        
        moves.clear();
        moves.insert(ChessSquare(File::A, rank + movementDirectionForCurrentAffiliation()));
        moves.insert(ChessSquare(File::C, rank + movementDirectionForCurrentAffiliation()));
        captureMoves_[ChessSquare(File::B, rank)] = moves;
        
        moves.clear();
        moves.insert(ChessSquare(File::B, rank + movementDirectionForCurrentAffiliation()));
        moves.insert(ChessSquare(File::D, rank + movementDirectionForCurrentAffiliation()));
        captureMoves_[ChessSquare(File::C, rank)] = moves;
        
        moves.clear();
        moves.insert(ChessSquare(File::C, rank + movementDirectionForCurrentAffiliation()));
        moves.insert(ChessSquare(File::E, rank + movementDirectionForCurrentAffiliation()));
        captureMoves_[ChessSquare(File::D, rank)] = moves;
        
        moves.clear();
        moves.insert(ChessSquare(File::D, rank + movementDirectionForCurrentAffiliation()));
        moves.insert(ChessSquare(File::F, rank + movementDirectionForCurrentAffiliation()));
        captureMoves_[ChessSquare(File::E, rank)] = moves;
        
        moves.clear();
        moves.insert(ChessSquare(File::E, rank + movementDirectionForCurrentAffiliation()));
        moves.insert(ChessSquare(File::G, rank + movementDirectionForCurrentAffiliation()));
        captureMoves_[ChessSquare(File::F, rank)] = moves;
        
        moves.clear();
        moves.insert(ChessSquare(File::F, rank + movementDirectionForCurrentAffiliation()));
        moves.insert(ChessSquare(File::H, rank + movementDirectionForCurrentAffiliation()));
        captureMoves_[ChessSquare(File::G, rank)] = moves;
        
        moves.clear();
        moves.insert(ChessSquare(File::G, rank + movementDirectionForCurrentAffiliation()));
        captureMoves_[ChessSquare(File::H, rank)] = moves;
    }
}

Pawn::~Pawn()
{
}

ExtendedSet<ChessSquare> Pawn::potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const
{
    if (emptyBoardMoves_.find(startingSquare) != emptyBoardMoves_.end())
    {
        return emptyBoardMoves_.at(startingSquare);
    }
    return ExtendedSet<ChessSquare>();
}

ExtendedSet<ChessSquare> Pawn::potentialCaptureMovesFrom(const ChessSquare& startingSquare) const
{
    if (captureMoves_.find(startingSquare) != captureMoves_.end())
    {
        return captureMoves_.at(startingSquare);
    }
    return ExtendedSet<ChessSquare>();
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

bool Pawn::pieceCanJumpOtherPieces() const
{
    return false;
}
