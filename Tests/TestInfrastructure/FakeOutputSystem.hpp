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
    void declareCheckmate() override;
    void declareStalemate() override;
    void requestPromotionDecision() override;
    void notifyUserOfPromotionTo(Chess::PieceType type) override;
    
    void gameEndedDueToTenConsecutiveInvalidMoveAttempts() override;
    
    // helpers
    ChessSquare lastMoveStartingSquare() const;
    ChessSquare lastMoveEndingSquare() const;
    Chess::PieceType lastPieceMoved() const;
    Chess::PieceType lastPiecePlaced() const;
    Chess::MoveValidity lastRejectedMoveReason() const;
    bool userInteractionEndHasBeenRequested() const;
    bool resetUxForNewGameHasBeenCalled() const;
    bool checkHasBeenDeclared() const;
    bool checkmateHasBeenDeclared() const;
    bool stalemateHasBeenDeclared() const;
    bool promotionPromptHasBeenRequested() const;
    Chess::PieceType lastNotifiedPromotion() const;
    
private:
    Chess::PieceType lastPieceMoved_;
    Chess::PieceType lastPiecePlaced_;
    Chess::MoveValidity lastRejectedMoveReason_;
    ChessSquare lastMoveStartingSquare_;
    ChessSquare lastMoveEndingSquare_;
    Chess::PieceType lastNotifiedPromotion_;
    bool userInteractionEndRequested_;
    bool resetUxForNewGameHasBeenCalled_;
    bool checkHasBeenDeclared_;
    bool checkmateHasBeenDeclared_;
    bool stalemateHasBeenDeclared_;
    bool promotionPromptHasBeenRequested_;
};
