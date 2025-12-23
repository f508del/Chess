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

class ChessMoveRequest;
class I_ReadOnlyChessBoard;

class ChessMoveDescriber
{
public:
   ChessMoveDescriber();
   virtual ~ChessMoveDescriber();

   std::string describeValidMove(const ChessMoveRequest& move, const I_ReadOnlyChessBoard& board) const;
    
private:
    std::string chessPieceTypeName(Chess::PieceType type) const;
};
