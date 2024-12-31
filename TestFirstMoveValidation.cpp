//
//  TestFirstMoveValidation.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#include "Catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"
#include "OutputErrorDefines.hpp"

using namespace std;
using namespace OutputErrorDefines;

namespace {
   void runTestWithOpeningMoveAndDisplayedResponse(const char* moveString, string response)
   {
   ChessEngineTestHarness testHarness;
   testHarness.setInputSequenceWithinANewGame({moveString});

   testHarness.chessEngine().runChessEngine();

   CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(response));
   }

   void runTestWithOpeningInvalidMoveOffOfBoard(const char* moveString)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                 MOVE_NOT_ON_BOARD_ERROR);
   }

   void runTestWithValidOpeningMove(const char* moveString, const char* moveResponse)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                 moveResponse);
   }

   void runTestWithMoveThatDoesNotStartOnAnExistingPiece(const char* moveString)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                NO_PIECE_AT_COORDINATES_ERROR);
   }

   void runTestWithMoveThatAttemptsToMoveOpposingPiece(const char* moveString)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                OPPOSING_PLAYERS_PIECE_ERROR);
   }

   void runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove(const char* moveString)
   {
      runTestWithOpeningMoveAndDisplayedResponse(moveString,
                                                 PIECE_CANNOT_CURRENTLY_MOVE_ERROR);
   }
}

TEST_CASE("Testing the validation of the user's opening move when invalid")
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

   SECTION("will detect a move that attempts to move a rook")
   {
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("a1a3");
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("h1a4");
   }

   SECTION("will detect a move that attempts to move a bishop")
   {
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("c1a3");
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("f1h3");
   }

   SECTION("will detect a move that attempts to move the queen")
   {
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("d1d3");
   }

   SECTION("will detect a move that attempts to move the king")
   {
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("e1d2");
   }

   SECTION("will detect a move that moves a knight to an occupied square")
   {
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("b1d2");
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("g1e2");
   }

   SECTION("will detect a move that attempts to use a pawn to capture a nonexisting piece")
   {
      runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMove("c2d3");
   }
}

TEST_CASE("Testing the validation of the user's opening move when valid")
{
   SECTION("will echo back the requested move when opening move is valid (pawn)")
   {
      runTestWithValidOpeningMove("a2a3", "Moving Pawn a2a3");
      runTestWithValidOpeningMove("a2a4", "Moving Pawn a2a4");
   }

   SECTION("will echo back the requested move when opening move is valid (knight)")
   {
      runTestWithValidOpeningMove("b1a3", "Moving Knight b1a3");
      runTestWithValidOpeningMove("b1c3", "Moving Knight b1c3");

      runTestWithValidOpeningMove("g1h3", "Moving Knight g1h3");
      runTestWithValidOpeningMove("g1f3", "Moving Knight g1f3");
   }
}
