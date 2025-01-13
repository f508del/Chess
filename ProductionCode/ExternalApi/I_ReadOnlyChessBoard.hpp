//
//  I_ReadOnlyChessBoard.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-12.
//

#pragma once

class ChessSquare;
class I_ChessPiece;

class I_ReadOnlyChessBoard
{
public:
    virtual bool anyPieceExistsAt(const ChessSquare& square) const = 0;
    virtual const I_ChessPiece* pieceAt(const ChessSquare& square) const = 0;
};
