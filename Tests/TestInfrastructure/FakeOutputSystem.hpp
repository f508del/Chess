//
//  FakeOutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "ChessPieceType.hpp"
#include "ChessSquare.hpp"
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
    void displayValidMoveToUser(const std::list<Chess::MoveElement>& moveElements) override;
    void rejectMoveAttempt(Chess::MoveValidity validity) override;
    void declareCheck() override;
    void requestPromotionDecision() override;
    
    // helpers
    ChessSquare lastMoveStartingSquare() const;
    ChessSquare lastMoveEndingSquare() const;
    Chess::PieceType lastPieceMoved() const;
    Chess::MoveValidity lastRejectedMoveReason() const;
    bool userInteractionEndHasBeenRequested() const;
    bool resetUxForNewGameHasBeenCalled() const;
    bool checkHasBeenDeclared() const;
    bool promotionPromptHasBeenRequested() const;
    
private:
    Chess::PieceType lastPieceMoved_;
    Chess::MoveValidity lastRejectedMoveReason_;
    ChessSquare lastMoveStartingSquare_;
    ChessSquare lastMoveEndingSquare_;
    bool userInteractionEndRequested_;
    bool resetUxForNewGameHasBeenCalled_;
    bool checkHasBeenDeclared_;
    bool promotionPromptHasBeenRequested_;
};
