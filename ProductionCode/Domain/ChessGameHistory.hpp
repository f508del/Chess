//
//  ChessGameHistory.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-23.
//

#include "ChessPieceType.hpp"
#include <list>

class ChessSquare;
class ChessMoveRecord;

class ChessGameHistory
{
public:
    ChessGameHistory();
    ~ChessGameHistory();
    
    void recordMove(const ChessMoveRecord& moveRecord);
    
    ChessSquare mostRecentMoveStartingSquare() const;
    ChessSquare mostRecentMoveEndingSquare() const;
    Chess::PieceType mostRecentMovedPiece() const;
    
private:
    std::list<ChessMoveRecord> moveHistory_;
};
