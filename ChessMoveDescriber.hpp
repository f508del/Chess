//
//  ChessMoveDescriber.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-24.
//
//

#pragma once

#include <string>

class ChessMove;
class ChessBoard;

class ChessMoveDescriber
{
public:
   ChessMoveDescriber();
   virtual ~ChessMoveDescriber();

   std::string describeMove(const ChessMove& move, const ChessBoard& board) const;
};
