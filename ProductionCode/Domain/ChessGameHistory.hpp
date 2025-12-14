//
//  ChessGameHistory.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-23.
//

#include "ChessPieceType.hpp"
#include <list>

class ChessSquare;
class InternalChessMove;

class ChessGameHistory
{
public:
    ChessGameHistory();
    ~ChessGameHistory();
    
    void recordMove(const InternalChessMove& move);
    
    ChessSquare mostRecentMoveStartingSquare() const;
    ChessSquare mostRecentMoveEndingSquare() const;
    Chess::PieceType mostRecentMovedPiece() const;
    
private:
    std::list<InternalChessMove> internalMoveHistory_;
};
