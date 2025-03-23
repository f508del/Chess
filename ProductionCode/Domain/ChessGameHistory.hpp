//
//  ChessGameHistory.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-23.
//

#include "ChessPieceType.hpp"
#include <list>

class ChessMove;

class ChessGameHistory
{
public:
    ChessGameHistory();
    ~ChessGameHistory();
    
    void recordMove(const ChessMove& move, Chess::PieceType pieceType);
    
    ChessMove mostRecentMove() const;
    Chess::PieceType mostRecentMovedPiece() const;
    
private:
    std::list<ChessMove> moveList_;
    std::list<Chess::PieceType> movePieceList_;
};
