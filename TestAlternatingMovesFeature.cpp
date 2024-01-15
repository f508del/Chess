//
//  TestAlternatingMovesFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-05-15.
//
//

#include "Catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "OutputErrorDefines.hpp"

using namespace std;
using namespace OutputErrorDefines;

TEST_CASE("Testing the enforcement of alternating move order")
{
   SECTION("will accept an opening move from white")
   {
       ChessEngineTestHarness testHarness;
       list<string> inputSequence;
       inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
       inputSequence.push_back("c2c3");
       testHarness.setInputSequenceAppendingQuit(inputSequence);

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Pawn c2c3"));
   }

   SECTION("will reject an attempt to move a black piece first")
   {
      ChessEngineTestHarness testHarness;
      list<string> inputSequence;
      inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
      inputSequence.push_back("c7c6");
      testHarness.setInputSequenceAppendingQuit(inputSequence);

      testHarness.chessEngine().runChessEngine();

      CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(OPPOSING_PLAYERS_PIECE_ERROR));
   }

   SECTION("will accept the second move of the game to come from black")
   {
      ChessEngineTestHarness testHarness;
      list<string> inputSequence;
      inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
      inputSequence.push_back("c2c3");
      inputSequence.push_back("c7c6");
      testHarness.setInputSequenceAppendingQuit(inputSequence);

      testHarness.chessEngine().runChessEngine();

      CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Pawn c7c6"));
   }

   SECTION("will reject a second move of the game to come from white")
   {
      ChessEngineTestHarness testHarness;
      list<string> inputSequence;
      inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
      inputSequence.push_back("c2c3");
      inputSequence.push_back("d2d4");
      testHarness.setInputSequenceAppendingQuit(inputSequence);

      testHarness.chessEngine().runChessEngine();

      CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(OPPOSING_PLAYERS_PIECE_ERROR));
   }

   SECTION("will accept the third move of the game to come from white")
   {
      ChessEngineTestHarness testHarness;
      list<string> inputSequence;
      inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
      inputSequence.push_back("c2c3");
      inputSequence.push_back("c7c6");
      inputSequence.push_back("d2d4");
      testHarness.setInputSequenceAppendingQuit(inputSequence);

      testHarness.chessEngine().runChessEngine();

      CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Pawn d2d4"));
   }

   SECTION("will reject the third move of the game to come from black")
   {
   ChessEngineTestHarness testHarness;
   list<string> inputSequence;
   inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
   inputSequence.push_back("c2c3");
   inputSequence.push_back("c7c6");
   inputSequence.push_back("d7d6");
   testHarness.setInputSequenceAppendingQuit(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(OPPOSING_PLAYERS_PIECE_ERROR));
   }
}
