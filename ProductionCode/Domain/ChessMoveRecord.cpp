//
//  ChessMoveRecord.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-04-13.
//

#include "ChessMoveRecord.hpp"

ChessMoveRecord::ChessMoveRecord()
: movingPieceAffiliation(Chess::PieceAffiliation::WHITE_PIECE)
, movingPieceType(Chess::PieceType::NONE)
, movingPieceStartingSquare()
, movingPieceEndingSquare()
, capturedPieceType(Chess::PieceType::NONE)
, capturedPieceSquare()
{
}
