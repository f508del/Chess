//
//  ChessBoard.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#pragma once

#include "ScopedPointer.hpp"
#include <map>

class ChessSquare;
class I_ChessPiece;
class Knight;
class Pawn;


class ChessBoard
{
public:
   explicit ChessBoard();
   virtual ~ChessBoard();

   bool anyPieceExistsAt(const ChessSquare& square) const;
   bool whitePieceExistsAt(const ChessSquare& square) const;
   bool blackPieceExistsAt(const ChessSquare& square) const;

   I_ChessPiece* pieceAt(const ChessSquare& square) const;

   void resetBoard();

private:
   ScopedPointer<Pawn> whitePawnCapabilities_;
   ScopedPointer<Pawn> blackPawnCapabilities_;
   ScopedPointer<Knight> whiteKnightCapabilities_;
   ScopedPointer<Knight> blackKnightCapabilities_;

   std::map<ChessSquare, I_ChessPiece*> boardState_;
};
