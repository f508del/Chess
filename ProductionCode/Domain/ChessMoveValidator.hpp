//
//  ChessMoveValidator.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#pragma once
#include "string"
#include "ChessMoveValidity.hpp"

class ChessMove;
class ChessBoard;

class ChessMoveValidator
{
public:
   ChessMoveValidator(const ChessBoard& board);
   virtual ~ChessMoveValidator();

   Chess::MoveValidity validateMove(const ChessMove& currentMove);

   std::string reasonLastMoveWasIllegal() const;

private:
   std::string commentOnLastMove_;
   const ChessBoard& board_;
};
