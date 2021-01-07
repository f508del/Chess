//
//  ChessMoveValidator.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#pragma once
#include "string"

class ChessMove;
class ChessBoard;

class ChessMoveValidator
{
public:
   ChessMoveValidator(const ChessBoard& board);
   virtual ~ChessMoveValidator();

   bool isLegalMove(const ChessMove& currentMove);

   std::string commentOnLastMove() const;

private:
   std::string commentOnLastMove_;
   const ChessBoard& board_;
};
