//
//  FakeChessBoard.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-12-20.
//

#include "FakeChessBoard.hpp"
#include "Bishop.hpp"
#include "ChessSquare.hpp"

using namespace Chess;

FakeChessBoard::FakeChessBoard()
: whiteBishopCapabilities_(new Bishop(PieceAffiliation::WHITE_PIECE))
{
    
}

FakeChessBoard::~FakeChessBoard()
{
    
}

bool FakeChessBoard::anyPieceExistsAt(const ChessSquare& square) const
{
    return (boardState_.find(square) != boardState_.end());
}

const I_ChessPiece* FakeChessBoard::pieceAt(const ChessSquare& square) const
{
    if (boardState_.find(square) != boardState_.end())
    {
        return boardState_.at(square);
    }
    return nullptr;
}

void FakeChessBoard::placeBishopAtSquare(const ChessSquare& square)
{
    boardState_[square] = whiteBishopCapabilities_.data();
}
