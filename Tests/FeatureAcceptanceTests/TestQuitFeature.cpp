//
//  TestQuitFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "Catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"

using namespace std;

TEST_CASE("Testing the quit feature")
{
   SECTION("can quit from the main menu")
   {
       ChessEngineTestHarness testHarness;
       testHarness.fakeInput().setInputSequence({CommandDefines::QUIT_COMMAND});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.fakeOutput().userInteractionEndHasBeenRequested());
   }

   SECTION("can quit with upper case version of command")
   {
       ChessEngineTestHarness testHarness;
       testHarness.fakeInput().setInputSequence({"Q"});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.fakeOutput().userInteractionEndHasBeenRequested());
   }

   SECTION("can quit after having started a new game and made a move")
   {
       ChessEngineTestHarness testHarness;
       testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3", CommandDefines::QUIT_COMMAND });

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.fakeOutput().userInteractionEndHasBeenRequested());
   }
}
