//
//  I_OutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "ChessMoveValidity.hpp"

class ChessMoveRequest;
class I_ReadOnlyChessBoard;

class I_OutputSystem
{
public:
    virtual ~I_OutputSystem(){}
    virtual void initializeChessUserInterface() = 0;
    virtual void endUserInteraction() = 0;
    virtual void resetUxForNewGame() = 0;
    virtual void displayValidMoveToUser(const ChessMoveRequest& move, const I_ReadOnlyChessBoard& board) = 0;
    virtual void rejectMoveAttempt(Chess::MoveValidity validity) = 0;
    virtual void declareCheck() = 0;
};
