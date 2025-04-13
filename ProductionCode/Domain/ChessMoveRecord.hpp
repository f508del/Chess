//
//  ChessMoveRecord.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-04-13.
//

#include "ChessPieceAffiliation.hpp"
#include "ChessPieceType.hpp"
#include "ChessSquare.hpp"

struct ChessMoveRecord
{
public:
    ChessMoveRecord();
    Chess::PieceAffiliation movingPieceAffiliation;
    Chess::PieceType movingPieceType;
    ChessSquare movingPieceStartingSquare;
    ChessSquare movingPieceEndingSquare;
    
    Chess::PieceType capturedPieceType;
    ChessSquare capturedPieceSquare;
};
