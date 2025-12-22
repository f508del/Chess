//
//  FakeChessBoard.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-12-20.
//

#include "FakeChessBoard.hpp"
#include "Bishop.hpp"
#include "ChessSquare.hpp"
#include "King.hpp"
#include "Knight.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"

using namespace Chess;

FakeChessBoard::FakeChessBoard()
: whiteBishopCapabilities_(new Bishop(PieceAffiliation::WHITE_PIECE))
, whiteKingCapabilities_(new King(PieceAffiliation::WHITE_PIECE))
, whiteKnightCapabilities_(new Knight(PieceAffiliation::WHITE_PIECE))
, whitePawnCapabilities_(new Pawn(PieceAffiliation::WHITE_PIECE))
, whiteQueenCapabilities_(new Queen(PieceAffiliation::WHITE_PIECE))
, whiteRookCapabilities_(new Rook(PieceAffiliation::WHITE_PIECE))
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

void FakeChessBoard::placeKingAtSquare(const ChessSquare& square)
{
    boardState_[square] = whiteKingCapabilities_.data();
}

void FakeChessBoard::placeKnightAtSquare(const ChessSquare &square)
{
    boardState_[square] = whiteKnightCapabilities_.data();
}

void FakeChessBoard::placePawnAtSquare(const ChessSquare& square)
{
    boardState_[square] = whitePawnCapabilities_.data();
}

void FakeChessBoard::placeQueenAtSquare(const ChessSquare& square)
{
    boardState_[square] = whiteQueenCapabilities_.data();
}

void FakeChessBoard::placeRookAtSquare(const ChessSquare& square)
{
    boardState_[square] = whiteRookCapabilities_.data();
}
