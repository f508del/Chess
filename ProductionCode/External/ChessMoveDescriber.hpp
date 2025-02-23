//
//  ChessMoveDescriber.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-24.
//
//

#pragma once

#include <string>
#include "ChessPieceType.hpp"

class ChessMove;
class I_ReadOnlyChessBoard;

class ChessMoveDescriber
{
public:
   ChessMoveDescriber();
   virtual ~ChessMoveDescriber();

   std::string describeValidMove(const ChessMove& move, const I_ReadOnlyChessBoard& board) const;
    
private:
    std::string chessPieceTypeName(Chess::PieceType type) const;
};
