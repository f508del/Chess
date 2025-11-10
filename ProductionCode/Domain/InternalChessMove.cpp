//
//  InternalChessMove.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-11-10.
//

#include "InternalChessMove.hpp"

InternalChessMove::InternalChessMove()
: validity_(Chess::MoveValidity::NO_MOVE_ELEMENTS_CHOSEN)
, moveElements_()
{
    
}

Chess::MoveValidity InternalChessMove::validity() const
{
    return validity_;
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




