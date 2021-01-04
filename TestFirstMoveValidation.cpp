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

using namespace std;

namespace {
   void runTestWithOpeningMoveAndDisplayedResponse(const char* moveString, string response)
   {
   ChessEngineTestHarness testHarness;

   list<string> inputSequence;
   inputSequence.push_back(CommandDefines::NEW_GAME_COMMAND);
   inputSequence.push_back(moveString);
   testHarness.setInputSequenceAppendingQuit(inputSequence);

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(response));
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

   void runTestWithMoveThatAttemptsToMoveOpposingPiece(const char* moveString)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                "Nice try, that's the other players piece!");
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

   SECTION("will detect a move that attempts to move the opposing players pieces")
   {
      runTestWithMoveThatAttemptsToMoveOpposingPiece("a7a6");
      runTestWithMoveThatAttemptsToMoveOpposingPiece("b8a6");
   }

   SECTION("will echo back the requested move when opening move is valid (pawn)")
   {
      runTestWithValidOpeningMove("a2a3");
      runTestWithValidOpeningMove("a2a4");
   }

   SECTION("will echo back the requested move when opening move is valid (knight)")
   {
      runTestWithValidOpeningMove("b1a3");
      runTestWithValidOpeningMove("b1c3");
   }
}
