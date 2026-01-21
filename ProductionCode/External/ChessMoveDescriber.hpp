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

class ChessMoveDescriber
{
public:
    ChessMoveDescriber();
    virtual ~ChessMoveDescriber();
    
    std::string describeValidMove(const std::list<Chess::MoveElement>& moveElements);
};
