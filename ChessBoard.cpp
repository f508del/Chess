//
//  ChessBoard.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#include "ChessBoard.hpp"
#include "ChessSquare.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"

ChessBoard::ChessBoard()
: pawnCapabilities_(new Pawn(WHITE_PIECE))
, knightCapabilities_(new Knight(WHITE_PIECE))
{
   resetBoard();
}

ChessBoard::~ChessBoard()
{

}

bool ChessBoard::anyPieceExistsAt(const ChessSquare& square) const
{
   return (boardState_.find(square) != boardState_.end());
}

bool ChessBoard::whitePieceExistsAt(const ChessSquare& square) const
{
   if (anyPieceExistsAt(square))
   {
      return (pieceAt(square)->affiliation() == WHITE_PIECE);
   }
   return false;
}

bool ChessBoard::blackPieceExistsAt(const ChessSquare& square) const
{
   // TODO: initial board state
   return (square.rank() >= 7);
}

I_ChessPiece* ChessBoard::pieceAt(const ChessSquare& square) const
{
   if (anyPieceExistsAt(square))
   {
       return boardState_.at(square);
   }
   return nullptr;
}

void ChessBoard::resetBoard()
{
   boardState_.clear();
   for (char file = 'a'; file <= 'h'; file++)
   {
      boardState_[ChessSquare(file, 2)] = pawnCapabilities_.data();
      boardState_[ChessSquare(file, 7)] = pawnCapabilities_.data();
   }

   // make back rows pawns for now, until all pieces are implemented.
   for (char file = 'a'; file <= 'h'; file++)
   {
      boardState_[ChessSquare(file, 1)] = pawnCapabilities_.data();
      boardState_[ChessSquare(file, 8)] = pawnCapabilities_.data();
   }

   boardState_[ChessSquare('b', 1)] = knightCapabilities_.data();
   boardState_[ChessSquare('g', 1)] = knightCapabilities_.data();
   boardState_[ChessSquare('b', 8)] = knightCapabilities_.data();
   boardState_[ChessSquare('g', 8)] = knightCapabilities_.data();
}
