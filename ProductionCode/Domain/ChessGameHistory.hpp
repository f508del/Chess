//
//  ChessGameHistory.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-23.
//

#include "ChessPieceType.hpp"
#include <list>

class ChessMove;
class ChessMoveRecord;

class ChessGameHistory
{
public:
    ChessGameHistory();
    ~ChessGameHistory();
    
    void recordMove(const ChessMoveRecord& moveRecord);
    
    ChessMove mostRecentMove() const;
    Chess::PieceType mostRecentMovedPiece() const;
    
private:
    std::list<ChessMoveRecord> moveHistory_;
};
