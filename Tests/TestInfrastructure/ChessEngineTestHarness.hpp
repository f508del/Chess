//
//  ChessEngineTestHarness.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-28.
//
//

#pragma once

#include "ScopedPointer.hpp"
#include "ChessPieceType.hpp"
#include "ChessMoveValidity.hpp"
#include <list>
#include <string>

class ChessEngine;
class ChessMoveRequest;
class FakeInputSystem;
class FakeOutputSystem;

class ChessEngineTestHarness
{
public:
    ChessEngineTestHarness();
    virtual ~ChessEngineTestHarness();

    FakeInputSystem& fakeInput();
    FakeOutputSystem& fakeOutput();

    ChessEngine& chessEngine();

    // Convenience interfaces
    void setInputSequenceWithinANewGame(const std::list<std::string>& inputSequence);
    bool lastMoveDisplayedMatches(const ChessMoveRequest& move);
    Chess::PieceType lastKindOfPieceMoved();
    Chess::MoveValidity lastMoveRejectionReason();

private:
   ScopedPointer<FakeInputSystem> inputSystem_;
   ScopedPointer<FakeOutputSystem> outputSystem_;

   ScopedPointer<ChessEngine> engine_;
};
