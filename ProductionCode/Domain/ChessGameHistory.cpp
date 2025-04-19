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
    moveList_.push_back(ChessMove(moveRecord.movingPieceStartingSquare, moveRecord.movingPieceEndingSquare));
    movePieceList_.push_back(moveRecord.movingPieceType);
}

ChessMove ChessGameHistory::mostRecentMove() const
{
    if (!moveList_.empty())
    {
        return moveList_.back();
    }
    return ChessMove();
}

PieceType ChessGameHistory::mostRecentMovedPiece() const { 
    if (!movePieceList_.empty())
    {
        return movePieceList_.back();
    }
    return PieceType::NONE;
}

