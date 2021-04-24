//
//  ChessMoveDescriber.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-24.
//
//

#include "ChessMoveDescriber.hpp"
#include "ChessMove.hpp"
#include "ChessBoard.hpp"
#include "I_ChessPiece.hpp"


ChessMoveDescriber::ChessMoveDescriber()
{
}

ChessMoveDescriber::~ChessMoveDescriber()
{
}

std::string ChessMoveDescriber::describeMove(const ChessMove& move, const ChessBoard& board) const
{
   std::string description("Moving ");
   if (board.anyPieceExistsAt(move.startingSquare()))
   {
      description.append(board.pieceAt(move.startingSquare())->pieceName());
   }

   return description.append(" ").append(move.toString());
}
