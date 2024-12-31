//
//  TestNewGameFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-29.
//
//

#include "Catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"

using namespace std;

TEST_CASE("Testing the 'new game' feature")
{
   SECTION("can start a new game at startup")
   {
   ChessEngineTestHarness testHarness;
   testHarness.setInputSequenceAppendingQuit({CommandDefines::NEW_GAME_COMMAND});

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().contains("New game requested..."));
   }

   SECTION("will inform user what color piece they play as")
   {
   ChessEngineTestHarness testHarness;
   testHarness.setInputSequenceAppendingQuit({CommandDefines::NEW_GAME_COMMAND});

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().contains("you are playing as white..."));
   }

   SECTION("will accept upper case version of new game command")
   {
   ChessEngineTestHarness testHarness;
   testHarness.setInputSequenceAppendingQuit({"N"});

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().contains("New game requested..."));
   }
}

