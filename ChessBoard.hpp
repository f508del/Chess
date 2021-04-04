//
//  ChessBoard.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#pragma once

class ChessSquare;
class I_ChessPiece;

class ChessBoard
{
public:
   explicit ChessBoard();
   virtual ~ChessBoard();

   bool anyPieceExistsAt(const ChessSquare& square) const;
   bool whitePieceExistsAt(const ChessSquare& square) const;
   bool blackPieceExistsAt(const ChessSquare& square) const;

   I_ChessPiece* pieceAt(const ChessSquare& square) const;
};
