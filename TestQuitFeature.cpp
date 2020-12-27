//
//  TestQuitFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "catch.hpp"
#include "ChessEngine.hpp"
#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"

TEST_CASE("Testing the quit feature")
{
   SECTION("can quit from the main menu")
   {
   FakeInputSystem inputSystem;
   FakeOutputSystem outputSystem;
   ChessEngine engine(inputSystem, outputSystem);

   std::list<std::string> inputSequence;
   inputSequence.push_back(std::string("q"));
   inputSystem.setInputSequence(inputSequence);

   engine.runChessEngine();

   CHECK(outputSystem.mostRecentOutput() == "quitting chess...");
   }
}
