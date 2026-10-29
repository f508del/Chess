//
//  TerminalBasedHumanChessPlayer.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-10-28.
//

#pragma once

#include "I_ChessPlayer.hpp"
#include "ScopedPointer.hpp"

class TerminalWrapper;
class StringBasedOutputSystem;
class StringBasedInputSystem;

class TerminalBasedHumanChessPlayer : public I_ChessPlayer
{
public:
    TerminalBasedHumanChessPlayer();
    
    // I_InputSystem implementations:
    void getNextInput() override;
    void registerNewGameCallback(std::function<void()> callback) override;
    void registerQuitCallback(std::function<void()> callback) override;
    void registerMoveAttemptCallback(std::function<void(const ChessMoveRequest&)> callback) override;
    void registerPromotionSelectionCallback(std::function<void(Chess::PieceType)> callback) override;
    
    // I_OutputSystem implementation:
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
    void gameEndedDueToTooManyConsecutiveInvalidMoveAttempts() override;
    
    // I_ChessPlayer implementation:
    std::string playerIdentifier() const override;
    
private:
    ScopedPointer<TerminalWrapper> terminalWrapper_;
    ScopedPointer<StringBasedOutputSystem> outputSystem_;
    ScopedPointer<StringBasedInputSystem> inputSystem_;
};
