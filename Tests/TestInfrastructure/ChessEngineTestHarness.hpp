//
//  ChessEngineTestHarness.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-28.
//
//

#pragma once

#include "ChessPieceType.hpp"
#include "ChessMoveValidity.hpp"
#include <memory>
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
    std::unique_ptr<InMemoryStringInputSource> fakeInputSource_;
    std::unique_ptr<StringBasedInputSystem> inputSystem_;
    std::unique_ptr<FakeOutputSystem> outputSystem_;

    std::unique_ptr<ChessEngine> engine_;
};
