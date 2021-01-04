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

class ChessMoveValidator
{
public:
   ChessMoveValidator();
   virtual ~ChessMoveValidator();

   bool isLegalMove(const ChessMove& currentMove);

   std::string commentOnLastMove() const;

private:
   bool isTouchingWhitePiece(const ChessMove& currentMove) const;
   bool isTouchingBlackPiece(const ChessMove& currentMove) const;

private:
   std::string commentOnLastMove_;
};
