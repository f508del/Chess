//
//  InternalChessMove.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-11-10.
//

#include "ChessMoveElement.hpp"
#include "ChessMoveValidity.hpp"
#include <list>

class InternalChessMove
{
public:
    InternalChessMove();
    
    Chess::MoveValidity validity() const;
    
    void setInvalidState(const Chess::MoveValidity validity);
    
    void addValidMoveElement(const Chess::MoveElement& element);
    
    const std::list<Chess::MoveElement>& moveElements() const;
    
private:
    Chess::MoveValidity validity_;
    std::list<Chess::MoveElement> moveElements_;
};
