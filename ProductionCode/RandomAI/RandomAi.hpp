//
//  RandomAI.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-05-06.
//

#include "I_InputSystem.hpp"
#include "I_OutputSystem.hpp"
#include "ChessBoard.hpp"
#include "ScopedPointer.hpp"
#include "ChessGameHistory.hpp"
#include "ChessMoveValidator.hpp"

class RandomAi : public I_InputSystem, public I_OutputSystem
{
public:
    RandomAi();
    
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
    
private:
    std::function<void(const ChessMoveRequest&)> moveAttemptCallback_;
    std::function<void(Chess::PieceType)> promotionCallback_;
    ChessMoveRequest convertInternalMoveToRequest(const InternalChessMove& move);
    
    ScopedPointer<ChessBoard> board_;
    ChessGameHistory gameHistory_;
    ChessMoveValidator moveValidator_;
    Chess::PieceAffiliation colorBeingPlayed_;
};

