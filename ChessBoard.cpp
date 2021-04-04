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
{

}

ChessBoard::~ChessBoard()
{

}

bool ChessBoard::anyPieceExistsAt(const ChessSquare& square) const
{
   // initial board state
   return whitePieceExistsAt(square) || blackPieceExistsAt(square);
}

bool ChessBoard::whitePieceExistsAt(const ChessSquare& square) const
{
   // initial board state
   return (square.rank() <= 2);
}

bool ChessBoard::blackPieceExistsAt(const ChessSquare& square) const
{
   // initial board state
   return (square.rank() >= 7);
}

I_ChessPiece* ChessBoard::pieceAt(const ChessSquare& square) const
{
   static Pawn pawn;
   static Knight knight;

   if (square.rank() == 1 && (square.file() == 'b' || square.file() == 'g'))
   {
      return &knight;
   }
   else if(square.rank() <= 2)
   {
      return &pawn;
   }
   return nullptr;
}
