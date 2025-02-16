//
//  FakeOutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "ChessMove.hpp"
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
    void displayMoveToUser(const ChessMove& move, const I_ReadOnlyChessBoard& board) override;
    void rejectMoveAttempt(Chess::MoveValidity validity) override;
    
    // helpers
    ChessMove lastMoveDisplayedToUser() const;
    Chess::PieceType lastPieceMoved() const;
    Chess::MoveValidity lastRejectedMoveReason() const;
    bool userInteractionEndHasBeenRequested() const;
    bool resetUxForNewGameHasBeenCalled() const;
    
private:
    ChessMove mostRecentMove_;
    Chess::PieceType lastPieceMoved_;
    Chess::MoveValidity lastRejectedMoveReason_;
    bool userInteractionEndRequested_;
    bool resetUxForNewGameHasBeenCalled_;
};
