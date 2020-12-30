//
//  ChessMoveValidator.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#pragma once

class ChessMove;

class ChessMoveValidator
{
public:
   ChessMoveValidator();
   virtual ~ChessMoveValidator();

   bool isLegalMove(const ChessMove& currentMove);
};
