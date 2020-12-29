//
//  ChessEngineTestHarness.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-28.
//
//

#pragma once

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
   FakeInputSystem* inputSystem_;
   FakeOutputSystem* outputSystem_;

   ChessEngine* engine_;
};
