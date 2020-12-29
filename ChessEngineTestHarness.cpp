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

ChessEngineTestHarness::ChessEngineTestHarness()
: inputSystem_(new FakeInputSystem())
, outputSystem_(new FakeOutputSystem())
, engine_(new ChessEngine(*inputSystem_, *outputSystem_))
{

}

ChessEngineTestHarness::~ChessEngineTestHarness()
{
   delete engine_;
   delete outputSystem_;
   delete inputSystem_;
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
