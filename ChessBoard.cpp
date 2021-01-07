//
//  ChessBoard.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#include "ChessBoard.hpp"

ChessBoard::ChessBoard()
{

}

ChessBoard::~ChessBoard()
{

}

bool ChessBoard::anyPieceExistsAt(char file, unsigned int rank) const
{
   // initial board state
   return whitePieceExistsAt(file, rank) || blackPieceExistsAt(file, rank);
}

bool ChessBoard::whitePieceExistsAt(char file, unsigned int rank) const
{
   // initial board state
   return (rank <= 2);
}

bool ChessBoard::blackPieceExistsAt(char file, unsigned int rank) const
{
   // initial board state
   return (rank >= 7);
}
