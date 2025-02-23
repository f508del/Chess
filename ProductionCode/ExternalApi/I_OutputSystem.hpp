//
//  I_OutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

class ChessMove;
class I_ReadOnlyChessBoard;
#include "ChessMoveValidity.hpp"

class I_OutputSystem
{
public:
    virtual ~I_OutputSystem(){}
    virtual void initializeChessUserInterface() = 0;
    virtual void endUserInteraction() = 0;
    virtual void resetUxForNewGame() = 0;
    virtual void displayValidMoveToUser(const ChessMove& move, const I_ReadOnlyChessBoard& board) = 0;
    virtual void rejectMoveAttempt(Chess::MoveValidity validity) = 0;

};
