//
//  InternalChessMove.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-11-10.
//

#include "InternalChessMove.hpp"

using namespace Chess;

InternalChessMove::InternalChessMove()
: validity_(Chess::MoveValidity::NO_MOVE_ELEMENTS_CHOSEN)
, moveElements_()
{
    
}

InternalChessMove::InternalChessMove(const Chess::MoveValidity validity)
: validity_(validity)
, moveElements_()
{
    
}

Chess::MoveValidity InternalChessMove::validity() const
{
    return validity_;
}

bool InternalChessMove::isValid() const
{
    return ((validity_ == MoveValidity::VALID_MOVE) || (validity_ == MoveValidity::VALID_EN_PASSANT_MOVE));
}

void InternalChessMove::setInvalidState(const Chess::MoveValidity validity)
{
    validity_  = validity;
    moveElements_.clear();
}

void InternalChessMove::addValidMoveElement(const Chess::MoveElement &element)
{
    validity_ = Chess::MoveValidity::VALID_MOVE;
    moveElements_.push_back(element);
}

const std::list<Chess::MoveElement>& InternalChessMove::moveElements() const
{ 
    return moveElements_;
}




