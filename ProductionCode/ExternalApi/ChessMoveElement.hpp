//
//  ChessMoveElement.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-11-10.
//

#pragma once

#include <list>
#include "ChessMoveElementAction.hpp"
#include "ChessPieceAffiliation.hpp"
#include "ChessPieceType.hpp"
#include "ChessSquare.hpp"

namespace Chess
{
struct MoveElement
{
public:
    MoveElement();
    MoveElement(const MoveElementAction& action, const ChessSquare& square, const PieceAffiliation& affiliation, const PieceType& type);
   
    MoveElementAction action_;
    ChessSquare square_;
    PieceAffiliation affiliation_;
    PieceType type_;
};

ChessSquare destinationSquareOfInstigatingPiece(const std::list<Chess::MoveElement>& moveElements);
}
