//
//  TestNewGameFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-29.
//
//

#include "catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"

TEST_CASE("Testing the 'new game' feature")
{
   SECTION("can start a new game at any time")
   {
   ChessEngineTestHarness testHarness;

   std::list<std::string> inputSequence;
   inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
   inputSequence.push_back(CommandDefines::QUIT_COMMAND);
   testHarness.fakeInput().setInputSequence(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().contains("New game requested..."));
   }

   SECTION("will inform user what color piece they play as")
   {
   ChessEngineTestHarness testHarness;

   std::list<std::string> inputSequence;
   inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
   inputSequence.push_back(CommandDefines::QUIT_COMMAND);
   testHarness.fakeInput().setInputSequence(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().contains("you are playing as white..."));

   }
}

