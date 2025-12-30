//
//  FakeOutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "ChessMoveRequest.hpp"
#include "ChessPieceType.hpp"
#include "I_OutputSystem.hpp"
#include <list>
#include <string>

class FakeOutputSystem: public I_OutputSystem
{
public:
    FakeOutputSystem();
    virtual ~FakeOutputSystem();

    // inherited
    void initializeChessUserInterface() override;
    void endUserInteraction() override;
    void resetUxForNewGame() override;
    void displayValidMoveToUser(const ChessMoveRequest& move, const I_ReadOnlyChessBoard& board) override;
    void displayValidMoveToUser(const std::list<Chess::MoveElement>& moveElements) override;
    void rejectMoveAttempt(Chess::MoveValidity validity) override;
    void declareCheck() override;
    
    // helpers
    ChessMoveRequest lastMoveDisplayedToUser() const;
    ChessSquare lastMoveStartingSquare() const;
    Chess::PieceType lastPieceMoved() const;
    Chess::MoveValidity lastRejectedMoveReason() const;
    bool userInteractionEndHasBeenRequested() const;
    bool resetUxForNewGameHasBeenCalled() const;
    bool checkHasBeenDeclared() const;
    
private:
    ChessMoveRequest mostRecentMove_;
    Chess::PieceType lastPieceMoved_;
    Chess::MoveValidity lastRejectedMoveReason_;
    bool userInteractionEndRequested_;
    bool resetUxForNewGameHasBeenCalled_;
    bool checkHasBeenDeclared_;
};
