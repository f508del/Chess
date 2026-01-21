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
class ChessSquare;
class StringBasedInputSystem;
class FakeOutputSystem;
class InMemoryStringInputSource;

class ChessEngineTestHarness
{
public:
    ChessEngineTestHarness();
    virtual ~ChessEngineTestHarness();

    FakeOutputSystem& fakeOutput();

    ChessEngine& chessEngine();

    // Convenience interfaces
    void setInputSequenceWithinANewGame(const std::list<std::string>& inputSequence);
    void setSimpleInputSequence(const std::list<std::string>& inputSequence);
    bool lastMoveDisplayedMatches(const ChessSquare& startingSquare, const ChessSquare& endingSquare);
    Chess::PieceType lastKindOfPieceMoved();
    Chess::PieceType lastKindOfPiecePlaced();
    Chess::MoveValidity lastMoveRejectionReason();
    bool promotionPromptHasBeenRequested();

private:
    ScopedPointer<InMemoryStringInputSource> fakeInputSource_;
    ScopedPointer<StringBasedInputSystem> inputSystem_;
    ScopedPointer<FakeOutputSystem> outputSystem_;

    ScopedPointer<ChessEngine> engine_;
};
