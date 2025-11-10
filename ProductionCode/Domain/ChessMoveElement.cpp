//
//  ChessMoveElement.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-11-10.
//

#include "ChessMoveElement.hpp"

using namespace Chess;

MoveElement::MoveElement()
: action_(MoveElementAction::NO_ACTION)
, square_()
, affiliation_(PieceAffiliation::WHITE_PIECE)
, type_(PieceType::NONE)
{
    
}

MoveElement::MoveElement(const MoveElementAction& action, const ChessSquare& square, const PieceAffiliation& affiliation, const PieceType& type)
: action_(action)
, square_(square)
, affiliation_(affiliation)
, type_(type)
{
    
}
