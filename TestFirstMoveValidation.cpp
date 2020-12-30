//
//  TestFirstMoveValidation.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#include "catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"

namespace {
   void runTestWithOpeningMoveAndDisplayedResponse(const char* moveString, std::string response)
   {
   ChessEngineTestHarness testHarness;

   std::list<std::string> inputSequence;
   inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
   inputSequence.push_back(moveString);
   inputSequence.push_back(CommandDefines::QUIT_COMMAND);
   testHarness.fakeInput().setInputSequence(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.fakeOutput().contains(response));
   }

   void runTestWithOpeningInvalidMoveOffOfBoard(const char* moveString)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                 "Move is not validly on the board");
   }

   void runTestWithValidOpeningMove(const char* moveString)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                 moveString);
   }

   void runTestWithMoveThatDoesNotStartOnAnExistingPiece(const char* moveString)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                "No piece exists at these coordinates");

   }
}

TEST_CASE("Testing the validation of the user's opening move")
{
   SECTION("will detect when the first coordinate file is not on the board")
   {
      runTestWithOpeningInvalidMoveOffOfBoard("z2a3");
   }

   SECTION("will detect when the first coordinate rank is below the board")
   {
      runTestWithOpeningInvalidMoveOffOfBoard("a0a3");
   }

   SECTION("will detect when the first coordinate rank is above the board")
   {
      runTestWithOpeningInvalidMoveOffOfBoard("a9a3");
   }

   SECTION("will detect when the second coordinate file is not on the board")
   {
      runTestWithOpeningInvalidMoveOffOfBoard("a2z3");
   }

   SECTION("will detect when the second coordinate rank is below the board")
   {
      runTestWithOpeningInvalidMoveOffOfBoard("a2a0");
   }

   SECTION("will detect when the second coordinate rank is above the board")
   {
      runTestWithOpeningInvalidMoveOffOfBoard("a2a9");
   }

   SECTION("will detect a move that does not start on an existing piece")
   {
      runTestWithMoveThatDoesNotStartOnAnExistingPiece("a5a6");
   }

   SECTION("will echo back the requested move when opening move is valid")
   {
      runTestWithValidOpeningMove("a2a3");
   }
}
