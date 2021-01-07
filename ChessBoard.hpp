//
//  ChessBoard.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#pragma once

class ChessBoard
{
public:
   explicit ChessBoard();
   virtual ~ChessBoard();

   bool anyPieceExistsAt(char file, unsigned int rank) const;
   bool whitePieceExistsAt(char file, unsigned int rank) const;
   bool blackPieceExistsAt(char file, unsigned int rank) const;
};
