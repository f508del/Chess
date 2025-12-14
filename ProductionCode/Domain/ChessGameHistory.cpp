//
//  ChessGameHistory.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-23.
//

#include "ChessGameHistory.hpp"
#include "InternalChessMove.hpp"

using namespace Chess;

ChessGameHistory::ChessGameHistory()
{
    
}

ChessGameHistory::~ChessGameHistory()
{
    
}

void ChessGameHistory::recordMove(const InternalChessMove& move)
{
    internalMoveHistory_.push_back(move);
}

PieceType ChessGameHistory::mostRecentMovedPiece() const
{ 
    if (!internalMoveHistory_.empty())
    {
        return internalMoveHistory_.back().moveElements().front().type_;
    }
    return PieceType::NONE;
}

ChessSquare ChessGameHistory::mostRecentMoveStartingSquare() const
{ 
    if (!internalMoveHistory_.empty())
    {
        return internalMoveHistory_.back().moveElements().front().square_;
    }
    return ChessSquare();
}

ChessSquare ChessGameHistory::mostRecentMoveEndingSquare() const
{ 
    if (!internalMoveHistory_.empty())
    {
        return internalMoveHistory_.back().moveElements().back().square_;
    }
    return ChessSquare();
}

