//
//  ChessMoveDescriber.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-24.
//
//

#pragma once

#include <list>
#include <string>
#include "ChessPieceType.hpp"

namespace Chess
{
struct MoveElement;
}

class ChessMoveRequest;
class ChessSquare;
class I_ReadOnlyChessBoard;

class ChessMoveDescriber
{
public:
    ChessMoveDescriber();
    virtual ~ChessMoveDescriber();

    std::string describeValidMove(const ChessMoveRequest& move, const I_ReadOnlyChessBoard& board) const;
    
    std::string describeValidMove(const std::list<Chess::MoveElement>& moveElements);
    
private:
    std::string chessPieceTypeName(Chess::PieceType type) const;
    ChessSquare destinationSquareOfInstigatingPiece(const std::list<Chess::MoveElement>& moveElements);
};
