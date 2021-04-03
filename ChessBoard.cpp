//
//  ChessBoard.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#include "ChessBoard.hpp"
#include "ChessSquare.hpp"

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
