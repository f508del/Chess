//
//  TestQuitFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"

TEST_CASE("Testing the quit feature")
{
   SECTION("can quit from the main menu")
   {
   ChessEngineTestHarness testHarness;

   std::list<std::string> inputSequence;
   inputSequence.push_back(CommandDefines::QUIT_COMMAND);
   testHarness.fakeInput().setInputSequence(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().mostRecentOutput() == "quitting chess...");
   }

   SECTION("can quit with uppper case version of command")
   {
   ChessEngineTestHarness testHarness;

   std::list<std::string> inputSequence;
   inputSequence.push_back("Q");
   testHarness.fakeInput().setInputSequence(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().mostRecentOutput() == "quitting chess...");
   }
}
