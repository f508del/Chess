//
//  ChessEngine.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

#include "ScopedPointer.hpp"

class ChessBoard;
class ChessGameHistory;
class ChessMoveRequest;
class ChessMoveValidator;
class I_InputSystem;
class I_OutputSystem;

class ChessEngine
{
public:
    explicit ChessEngine(I_InputSystem& whiteInputSystem,
                         I_InputSystem& blackInputSystem,
                         I_OutputSystem& outputSystem);

    virtual ~ChessEngine();

    void runChessEngine();
    
private:
    void resetForNewGame();
    void endEventLoop();
    void attemptMove(const ChessMoveRequest& move);
    void detectEndGameConditions();

private:
    I_InputSystem& whiteInputSystem_;
    I_InputSystem& blackInputSystem_;
    I_OutputSystem& outputSystem_;
    ScopedPointer<ChessBoard> board_;
    ScopedPointer<ChessGameHistory> gameHistory_;
    ScopedPointer<ChessMoveValidator> moveValidator_;
    bool userHasQuitTheProgram_;
};
