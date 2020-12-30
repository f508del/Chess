//
//  ChessEngineTestHarness.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-28.
//
//

#pragma once

#include "ScopedPointer.hpp"

class ChessEngine;
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

private:
   ScopedPointer<FakeInputSystem> inputSystem_;
   ScopedPointer<FakeOutputSystem> outputSystem_;

   ScopedPointer<ChessEngine> engine_;
};
