//
//  Knight.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Knight.hpp"

using namespace Chess;

Knight::Knight(PieceAffiliation affiliation)
: affiliation_(affiliation)
{
    ExtendedSet<ChessSquare> moves;
    moves.insert(ChessSquare(File::B, 3));
    moves.insert(ChessSquare(File::C, 2));
    emptyBoardMoves_[ChessSquare(File::A, 1)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::B, 4));
    moves.insert(ChessSquare(File::C, 3));
    moves.insert(ChessSquare(File::C, 1));
    emptyBoardMoves_[ChessSquare(File::A, 2)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::B, 5));
    moves.insert(ChessSquare(File::C, 4));
    moves.insert(ChessSquare(File::C, 2));
    moves.insert(ChessSquare(File::B, 1));
    emptyBoardMoves_[ChessSquare(File::A, 3)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::B, 6));
    moves.insert(ChessSquare(File::C, 5));
    moves.insert(ChessSquare(File::C, 3));
    moves.insert(ChessSquare(File::B, 2));
    emptyBoardMoves_[ChessSquare(File::A, 4)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::B, 7));
    moves.insert(ChessSquare(File::C, 6));
    moves.insert(ChessSquare(File::C, 4));
    moves.insert(ChessSquare(File::B, 3));
    emptyBoardMoves_[ChessSquare(File::A, 5)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::B, 8));
    moves.insert(ChessSquare(File::C, 7));
    moves.insert(ChessSquare(File::C, 5));
    moves.insert(ChessSquare(File::B, 4));
    emptyBoardMoves_[ChessSquare(File::A, 6)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::C, 8));
    moves.insert(ChessSquare(File::C, 6));
    moves.insert(ChessSquare(File::B, 5));
    emptyBoardMoves_[ChessSquare(File::A, 7)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::C, 7));
    moves.insert(ChessSquare(File::B, 6));
    emptyBoardMoves_[ChessSquare(File::A, 8)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::C, 3));
    moves.insert(ChessSquare(File::D, 2));
    moves.insert(ChessSquare(File::A, 3));
    emptyBoardMoves_[ChessSquare(File::B, 1)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::C, 4));
    moves.insert(ChessSquare(File::D, 3));
    moves.insert(ChessSquare(File::D, 1));
    moves.insert(ChessSquare(File::A, 4));
    emptyBoardMoves_[ChessSquare(File::B, 2)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::C, 5));
    moves.insert(ChessSquare(File::D, 4));
    moves.insert(ChessSquare(File::D, 2));
    moves.insert(ChessSquare(File::C, 1));
    moves.insert(ChessSquare(File::A, 1));
    moves.insert(ChessSquare(File::A, 5));
    emptyBoardMoves_[ChessSquare(File::B, 3)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::C, 6));
    moves.insert(ChessSquare(File::D, 5));
    moves.insert(ChessSquare(File::D, 3));
    moves.insert(ChessSquare(File::C, 2));
    moves.insert(ChessSquare(File::A, 2));
    moves.insert(ChessSquare(File::A, 6));
    emptyBoardMoves_[ChessSquare(File::B, 4)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::C, 7));
    moves.insert(ChessSquare(File::D, 6));
    moves.insert(ChessSquare(File::D, 4));
    moves.insert(ChessSquare(File::C, 3));
    moves.insert(ChessSquare(File::A, 3));
    moves.insert(ChessSquare(File::A, 7));
    emptyBoardMoves_[ChessSquare(File::B, 5)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::C, 8));
    moves.insert(ChessSquare(File::D, 7));
    moves.insert(ChessSquare(File::D, 5));
    moves.insert(ChessSquare(File::C, 4));
    moves.insert(ChessSquare(File::A, 4));
    moves.insert(ChessSquare(File::A, 8));
    emptyBoardMoves_[ChessSquare(File::B, 6)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::D, 8));
    moves.insert(ChessSquare(File::D, 6));
    moves.insert(ChessSquare(File::C, 5));
    moves.insert(ChessSquare(File::A, 5));
    emptyBoardMoves_[ChessSquare(File::B, 7)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::D, 7));
    moves.insert(ChessSquare(File::C, 6));
    moves.insert(ChessSquare(File::A, 6));
    emptyBoardMoves_[ChessSquare(File::B, 8)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::D, 3));
    moves.insert(ChessSquare(File::E, 2));
    moves.insert(ChessSquare(File::B, 3));
    moves.insert(ChessSquare(File::A, 2));
    emptyBoardMoves_[ChessSquare(File::C, 1)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::D, 4));
    moves.insert(ChessSquare(File::E, 3));
    moves.insert(ChessSquare(File::E, 1));
    moves.insert(ChessSquare(File::B, 4));
    moves.insert(ChessSquare(File::A, 3));
    moves.insert(ChessSquare(File::A, 1));
    emptyBoardMoves_[ChessSquare(File::C, 2)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::D, 5));
    moves.insert(ChessSquare(File::E, 4));
    moves.insert(ChessSquare(File::E, 2));
    moves.insert(ChessSquare(File::D, 1));
    moves.insert(ChessSquare(File::B, 1));
    moves.insert(ChessSquare(File::B, 5));
    moves.insert(ChessSquare(File::A, 4));
    moves.insert(ChessSquare(File::A, 2));
    emptyBoardMoves_[ChessSquare(File::C, 3)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::D, 6));
    moves.insert(ChessSquare(File::E, 5));
    moves.insert(ChessSquare(File::E, 3));
    moves.insert(ChessSquare(File::D, 2));
    moves.insert(ChessSquare(File::B, 2));
    moves.insert(ChessSquare(File::B, 6));
    moves.insert(ChessSquare(File::A, 5));
    moves.insert(ChessSquare(File::A, 3));
    emptyBoardMoves_[ChessSquare(File::C, 4)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::D, 7));
    moves.insert(ChessSquare(File::E, 6));
    moves.insert(ChessSquare(File::E, 4));
    moves.insert(ChessSquare(File::D, 3));
    moves.insert(ChessSquare(File::B, 3));
    moves.insert(ChessSquare(File::B, 7));
    moves.insert(ChessSquare(File::A, 6));
    moves.insert(ChessSquare(File::A, 4));
    emptyBoardMoves_[ChessSquare(File::C, 5)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::D, 8));
    moves.insert(ChessSquare(File::E, 7));
    moves.insert(ChessSquare(File::E, 5));
    moves.insert(ChessSquare(File::D, 4));
    moves.insert(ChessSquare(File::B, 4));
    moves.insert(ChessSquare(File::B, 8));
    moves.insert(ChessSquare(File::A, 7));
    moves.insert(ChessSquare(File::A, 5));
    emptyBoardMoves_[ChessSquare(File::C, 6)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::E, 8));
    moves.insert(ChessSquare(File::E, 6));
    moves.insert(ChessSquare(File::D, 5));
    moves.insert(ChessSquare(File::B, 5));
    moves.insert(ChessSquare(File::A, 8));
    moves.insert(ChessSquare(File::A, 6));
    emptyBoardMoves_[ChessSquare(File::C, 7)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::E, 7));
    moves.insert(ChessSquare(File::D, 6));
    moves.insert(ChessSquare(File::B, 6));
    moves.insert(ChessSquare(File::A, 7));
    emptyBoardMoves_[ChessSquare(File::C, 8)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::E, 3));
    moves.insert(ChessSquare(File::F, 2));
    moves.insert(ChessSquare(File::C, 3));
    moves.insert(ChessSquare(File::B, 2));
    emptyBoardMoves_[ChessSquare(File::D, 1)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::E, 4));
    moves.insert(ChessSquare(File::F, 3));
    moves.insert(ChessSquare(File::F, 1));
    moves.insert(ChessSquare(File::C, 4));
    moves.insert(ChessSquare(File::B, 3));
    moves.insert(ChessSquare(File::B, 1));
    emptyBoardMoves_[ChessSquare(File::D, 2)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::E, 5));
    moves.insert(ChessSquare(File::F, 4));
    moves.insert(ChessSquare(File::F, 2));
    moves.insert(ChessSquare(File::E, 1));
    moves.insert(ChessSquare(File::C, 1));
    moves.insert(ChessSquare(File::C, 5));
    moves.insert(ChessSquare(File::B, 4));
    moves.insert(ChessSquare(File::B, 2));
    emptyBoardMoves_[ChessSquare(File::D, 3)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::E, 6));
    moves.insert(ChessSquare(File::F, 5));
    moves.insert(ChessSquare(File::F, 3));
    moves.insert(ChessSquare(File::E, 2));
    moves.insert(ChessSquare(File::C, 2));
    moves.insert(ChessSquare(File::C, 6));
    moves.insert(ChessSquare(File::B, 5));
    moves.insert(ChessSquare(File::B, 3));
    emptyBoardMoves_[ChessSquare(File::D, 4)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::E, 7));
    moves.insert(ChessSquare(File::F, 6));
    moves.insert(ChessSquare(File::F, 4));
    moves.insert(ChessSquare(File::E, 3));
    moves.insert(ChessSquare(File::C, 3));
    moves.insert(ChessSquare(File::C, 7));
    moves.insert(ChessSquare(File::B, 6));
    moves.insert(ChessSquare(File::B, 4));
    emptyBoardMoves_[ChessSquare(File::D, 5)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::E, 8));
    moves.insert(ChessSquare(File::F, 7));
    moves.insert(ChessSquare(File::F, 5));
    moves.insert(ChessSquare(File::E, 4));
    moves.insert(ChessSquare(File::C, 4));
    moves.insert(ChessSquare(File::C, 8));
    moves.insert(ChessSquare(File::B, 7));
    moves.insert(ChessSquare(File::B, 5));
    emptyBoardMoves_[ChessSquare(File::D, 6)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::F, 8));
    moves.insert(ChessSquare(File::F, 6));
    moves.insert(ChessSquare(File::E, 5));
    moves.insert(ChessSquare(File::C, 5));
    moves.insert(ChessSquare(File::B, 8));
    moves.insert(ChessSquare(File::B, 6));
    emptyBoardMoves_[ChessSquare(File::D, 7)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::F, 7));
    moves.insert(ChessSquare(File::E, 6));
    moves.insert(ChessSquare(File::C, 6));
    moves.insert(ChessSquare(File::B, 7));
    emptyBoardMoves_[ChessSquare(File::D, 8)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::F, 3));
    moves.insert(ChessSquare(File::G, 2));
    moves.insert(ChessSquare(File::D, 3));
    moves.insert(ChessSquare(File::C, 2));
    emptyBoardMoves_[ChessSquare(File::E, 1)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::F, 4));
    moves.insert(ChessSquare(File::G, 3));
    moves.insert(ChessSquare(File::G, 1));
    moves.insert(ChessSquare(File::D, 4));
    moves.insert(ChessSquare(File::C, 3));
    moves.insert(ChessSquare(File::C, 1));
    emptyBoardMoves_[ChessSquare(File::E, 2)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::F, 5));
    moves.insert(ChessSquare(File::G, 4));
    moves.insert(ChessSquare(File::G, 2));
    moves.insert(ChessSquare(File::F, 1));
    moves.insert(ChessSquare(File::D, 1));
    moves.insert(ChessSquare(File::D, 5));
    moves.insert(ChessSquare(File::C, 4));
    moves.insert(ChessSquare(File::C, 2));
    emptyBoardMoves_[ChessSquare(File::E, 3)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::F, 6));
    moves.insert(ChessSquare(File::G, 5));
    moves.insert(ChessSquare(File::G, 3));
    moves.insert(ChessSquare(File::F, 2));
    moves.insert(ChessSquare(File::D, 2));
    moves.insert(ChessSquare(File::D, 6));
    moves.insert(ChessSquare(File::C, 5));
    moves.insert(ChessSquare(File::C, 3));
    emptyBoardMoves_[ChessSquare(File::E, 4)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::F, 7));
    moves.insert(ChessSquare(File::G, 6));
    moves.insert(ChessSquare(File::G, 4));
    moves.insert(ChessSquare(File::F, 3));
    moves.insert(ChessSquare(File::D, 3));
    moves.insert(ChessSquare(File::D, 7));
    moves.insert(ChessSquare(File::C, 6));
    moves.insert(ChessSquare(File::C, 4));
    emptyBoardMoves_[ChessSquare(File::E, 5)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::F, 8));
    moves.insert(ChessSquare(File::G, 7));
    moves.insert(ChessSquare(File::G, 5));
    moves.insert(ChessSquare(File::F, 4));
    moves.insert(ChessSquare(File::D, 4));
    moves.insert(ChessSquare(File::D, 8));
    moves.insert(ChessSquare(File::C, 7));
    moves.insert(ChessSquare(File::C, 5));
    emptyBoardMoves_[ChessSquare(File::E, 6)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::G, 8));
    moves.insert(ChessSquare(File::G, 6));
    moves.insert(ChessSquare(File::F, 5));
    moves.insert(ChessSquare(File::D, 5));
    moves.insert(ChessSquare(File::C, 8));
    moves.insert(ChessSquare(File::C, 6));
    emptyBoardMoves_[ChessSquare(File::E, 7)] = moves;
    
    moves.clear();
    moves.insert(ChessSquare(File::G, 7));
    moves.insert(ChessSquare(File::F, 6));
    moves.insert(ChessSquare(File::D, 6));
    moves.insert(ChessSquare(File::C, 7));
    emptyBoardMoves_[ChessSquare(File::E, 8)] = moves;
    
    /*---------*/
}

Knight::~Knight()
{
}

ExtendedSet<ChessSquare> Knight::potentialEmptyBoardMovesFrom(const ChessSquare& startingSquare) const
{
    if (emptyBoardMoves_.find(startingSquare) != emptyBoardMoves_.end())
    {
        return emptyBoardMoves_.at(startingSquare);
    }
    
   ExtendedSet<ChessSquare> potentialMoves;

   // forward "L"s:
   ChessSquare destinationSquare(char(startingSquare.file() + 1), startingSquare.rank() + 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(char(startingSquare.file() - 1), startingSquare.rank() + 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   // backward "L"s:
   destinationSquare = ChessSquare(char(startingSquare.file() + 1), startingSquare.rank() - 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(char(startingSquare.file() - 1), startingSquare.rank() - 2);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }


   // rightward "L"s
   destinationSquare = ChessSquare(char(startingSquare.file() + 2), startingSquare.rank() + 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(char(startingSquare.file() + 2), startingSquare.rank() - 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   // leftward "L"s
   destinationSquare = ChessSquare(char(startingSquare.file() - 2), startingSquare.rank() + 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }

   destinationSquare = ChessSquare(char(startingSquare.file() - 2), startingSquare.rank() - 1);
   if (destinationSquare.isSquareOnTheBoard())
   {
      potentialMoves.insert(destinationSquare);
   }
   return potentialMoves;
}

ExtendedSet<ChessSquare> Knight::potentialCaptureMovesFrom(const ChessSquare& startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

ExtendedSet<ChessSquare> Knight::potentialEmptyOrCaptureMovesFrom(const ChessSquare &startingSquare) const
{
    return potentialEmptyBoardMovesFrom(startingSquare);
}

PieceAffiliation Knight::affiliation() const
{
   return affiliation_;
}

PieceType Knight::pieceType() const
{
    return PieceType::KNIGHT;
}

bool Knight::pieceCanJumpOtherPieces() const
{
    return true;
}


