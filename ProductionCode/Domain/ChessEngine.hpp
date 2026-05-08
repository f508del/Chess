//
//  ChessEngine.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

#include "ScopedPointer.hpp"
#include "ChessPieceType.hpp"
#include "ChessPieceAffiliation.hpp"

class ChessBoard;
class ChessGameHistory;
class ChessMoveRequest;
class ChessMoveValidator;
class ChessSquare;
class I_InputSystem;
class I_OutputSystem;
class InternalChessMove;

class ChessEngine
{
public:
    explicit ChessEngine(I_InputSystem& whiteInputSystem,
                         I_InputSystem& blackInputSystem,
                         I_OutputSystem& outputSystem);

    virtual ~ChessEngine();

    void runChessEngine();
    
private:
    // callback functions for input systems:
    void resetForNewGame();
    void endEventLoop();
    void attemptMove(const ChessMoveRequest& move);
    void applyPromotion(Chess::PieceType type);
    
    // Other helpers:
    void detectEndGameConditions();
    void getNextInput();
    bool pieceThreateningTheKingCanBeCapturedWithoutLeavingKingInThreat(const ChessSquare& kingSquareInThreat, Chess::PieceAffiliation attackingColor);
    bool pieceThreateningKingCanBeBlockedWithoutLeavingKingInThreat(const ChessSquare& kingSquareInThreat, Chess::PieceAffiliation attackingColor);
    bool kingCanMoveOutOfThreat(const ChessSquare& kingSquareInThreat);
    bool playerHasNoLegalMove(Chess::PieceAffiliation playerColor);
    
private:
    I_InputSystem& whiteInputSystem_;
    I_InputSystem& blackInputSystem_;
    I_OutputSystem& outputSystem_;
    ScopedPointer<ChessBoard> board_;
    ScopedPointer<ChessGameHistory> gameHistory_;
    ScopedPointer<ChessMoveValidator> moveValidator_;
    bool userHasQuitTheProgram_;
    unsigned int invalidMoveAttemptCounter_;
};
