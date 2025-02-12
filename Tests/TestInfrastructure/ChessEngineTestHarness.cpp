//
//  ChessEngineTestHarness.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-28.
//
//

#include "ChessEngineTestHarness.hpp"

#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"
#include "ChessEngine.hpp"
#include "CommandDefines.hpp"

using namespace std;
using namespace Chess;

ChessEngineTestHarness::ChessEngineTestHarness()
: inputSystem_(new FakeInputSystem())
, outputSystem_(new FakeOutputSystem())
, engine_(new ChessEngine(*inputSystem_, *outputSystem_))
{

}

ChessEngineTestHarness::~ChessEngineTestHarness()
{
   
}

FakeInputSystem& ChessEngineTestHarness::fakeInput()
{
   return *inputSystem_;
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

    fakeInput().setInputSequence(finalInputSequence);
}

bool ChessEngineTestHarness::lastMoveDisplayedMatches(const ChessMove &move)
{
    return (fakeOutput().lastMoveDisplayedToUser() == move);
}

PieceType ChessEngineTestHarness::lastKindOfPieceMoved()
{
    return (fakeOutput().lastPieceMoved());
}

Chess::MoveValidity ChessEngineTestHarness::lastMoveRejectionReason() { 
    return (fakeOutput().lastRejectedMoveReason());
}


