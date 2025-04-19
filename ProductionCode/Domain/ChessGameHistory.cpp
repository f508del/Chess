//
//  ChessGameHistory.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-23.
//

#include "ChessGameHistory.hpp"
#include "ChessMove.hpp"
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

ChessMove ChessGameHistory::mostRecentMove() const
{
    if (!moveHistory_.empty())
    {
        return ChessMove(moveHistory_.back().movingPieceStartingSquare, moveHistory_.back().movingPieceEndingSquare);
    }
    return ChessMove();
}

PieceType ChessGameHistory::mostRecentMovedPiece() const
{ 
    if (!moveHistory_.empty())
    {
        return moveHistory_.back().movingPieceType;
    }
    return PieceType::NONE;
}

