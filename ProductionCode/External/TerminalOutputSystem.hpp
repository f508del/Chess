//
//  TerminalOutputSystem.h
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#pragma once

class ChessMoveDescriber;
class TerminalWrapper;

#include "I_OutputSystem.hpp"
#include "ScopedPointer.hpp"

class TerminalOutputSystem : public I_OutputSystem
{
public:
   explicit TerminalOutputSystem(TerminalWrapper& wrapper);
   virtual ~TerminalOutputSystem();

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
    
private: // helper functions
    void showTextToUser(const char* displayString);
    
private:
    ScopedPointer<ChessMoveDescriber> moveDescriber_;
    TerminalWrapper& terminalWrapper_;
};
