//
//  I_OutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "ChessMoveValidity.hpp"
#include "ChessPieceType.hpp"
#include <list>

namespace Chess
{
struct MoveElement;
}


class I_OutputSystem
{
public:
    virtual ~I_OutputSystem(){}
    virtual void initializeChessUserInterface() = 0;
    virtual void endUserInteraction() = 0;
    virtual void resetUxForNewGame() = 0;
    virtual void displayValidMoveToUser(const std::list<Chess::MoveElement>& moveElements) = 0;
    virtual void rejectMoveAttempt(Chess::MoveValidity validity) = 0;
    virtual void declareCheck() = 0;
    virtual void declareCheckmate() = 0;
    virtual void requestPromotionDecision() = 0;
    virtual void notifyUserOfPromotionTo(Chess::PieceType type) = 0;
};
