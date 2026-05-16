//
//  StringBasedOutputSystem.h
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#pragma once

class ChessMoveDescriber;
class I_StringOutputDestination;

#include "I_OutputSystem.hpp"
#include "ScopedPointer.hpp"

class StringBasedOutputSystem : public I_OutputSystem
{
public:
   explicit StringBasedOutputSystem(I_StringOutputDestination& wrapper);
   virtual ~StringBasedOutputSystem();

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
    I_StringOutputDestination& stringDestination_;
};
