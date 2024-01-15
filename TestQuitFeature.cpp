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

   list<string> inputSequence;
   inputSequence.push_back(CommandDefines::QUIT_COMMAND);
   testHarness.fakeInput().setInputSequence(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().mostRecentOutput() == "quitting chess...");
   }

   SECTION("can quit with upper case version of command")
   {
   ChessEngineTestHarness testHarness;

   list<string> inputSequence;
   inputSequence.push_back("Q");
   testHarness.fakeInput().setInputSequence(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().mostRecentOutput() == "quitting chess...");
   }

   SECTION("can quit after having started a new game and made a move")
   {
   ChessEngineTestHarness testHarness;

   list<string> inputSequence;
   inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
   inputSequence.push_back("a2a3");
   inputSequence.push_back(CommandDefines::QUIT_COMMAND);
   testHarness.fakeInput().setInputSequence(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().mostRecentOutput() == "quitting chess...");
   }
}
