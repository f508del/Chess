//
//  ChessGameHistory.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-23.
//

#include "ChessGameHistory.hpp"
#include "ChessMoveRecord.hpp"

using namespace Chess;

ChessGameHistory::ChessGameHistory()
{
    
}

ChessGameHistory::~ChessGameHistory()
{
    
}

void ChessGameHistory::recordMove(const ChessMoveRecord& moveRecord)
{
    moveHistory_.push_back(moveRecord);
}

PieceType ChessGameHistory::mostRecentMovedPiece() const
{ 
    if (!moveHistory_.empty())
    {
        return moveHistory_.back().movingPieceType;
    }
    return PieceType::NONE;
}

ChessSquare ChessGameHistory::mostRecentMoveStartingSquare() const
{ 
    if (!moveHistory_.empty())
    {
        return moveHistory_.back().movingPieceStartingSquare;
    }
    return ChessSquare();
}

ChessSquare ChessGameHistory::mostRecentMoveEndingSquare() const
{ 
    if (!moveHistory_.empty())
    {
        return moveHistory_.back().movingPieceEndingSquare;
    }
    return ChessSquare();
}



