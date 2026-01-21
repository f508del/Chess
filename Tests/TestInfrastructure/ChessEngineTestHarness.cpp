//
//  ChessEngineTestHarness.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-28.
//
//

#include "ChessEngineTestHarness.hpp"

#include "StringBasedInputSystem.hpp"
#include "FakeOutputSystem.hpp"
#include "ChessEngine.hpp"
#include "CommandDefines.hpp"
#include "InMemoryStringInputSource.hpp"

using namespace std;
using namespace Chess;

ChessEngineTestHarness::ChessEngineTestHarness()
: fakeInputSource_(new InMemoryStringInputSource())
, inputSystem_(new StringBasedInputSystem(*fakeInputSource_))
, outputSystem_(new FakeOutputSystem())
, engine_(new ChessEngine(*inputSystem_, *inputSystem_, *outputSystem_))
{

}

ChessEngineTestHarness::~ChessEngineTestHarness()
{
   
}

FakeOutputSystem& ChessEngineTestHarness::fakeOutput()
{
   return *outputSystem_;
}

ChessEngine& ChessEngineTestHarness::chessEngine()
{
   return *engine_;
}

void ChessEngineTestHarness::setInputSequenceWithinANewGame(const std::list<std::string>& inputSequence)
{
    list<string> finalInputSequence = inputSequence;
    finalInputSequence.push_back(CommandDefines::QUIT_COMMAND);
    finalInputSequence.push_front(CommandDefines::NEW_GAME_COMMAND);

    fakeInputSource_->setInputSequence(finalInputSequence);
}

void ChessEngineTestHarness::setSimpleInputSequence(const std::list<std::string>& inputSequence)
{
    fakeInputSource_->setInputSequence(inputSequence);
}

bool ChessEngineTestHarness::lastMoveDisplayedMatches(const ChessSquare& startingSquare, const ChessSquare& endingSquare)
{
    return (fakeOutput().lastMoveStartingSquare() == startingSquare && fakeOutput().lastMoveEndingSquare() == endingSquare);
}

PieceType ChessEngineTestHarness::lastKindOfPieceMoved()
{
    return (fakeOutput().lastPieceMoved());
}

PieceType ChessEngineTestHarness::lastKindOfPiecePlaced()
{
    return fakeOutput().lastPiecePlaced();
}

MoveValidity ChessEngineTestHarness::lastMoveRejectionReason()
{
    return (fakeOutput().lastRejectedMoveReason());
}

bool ChessEngineTestHarness::promotionPromptHasBeenRequested()
{
    return fakeOutput().promotionPromptHasBeenRequested();
}
