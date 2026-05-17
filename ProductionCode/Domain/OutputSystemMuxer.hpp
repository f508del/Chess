//
//  OutputSystemMuxer.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-05-08.
//

#include "I_OutputSystem.hpp"
#include <list>

class OutputSystemMuxer : public I_OutputSystem
{
public:
    OutputSystemMuxer(const std::list<I_OutputSystem*>& muxedSystems);
    
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
    
private:
    std::list<I_OutputSystem*> muxedOutputSystems_;
};
