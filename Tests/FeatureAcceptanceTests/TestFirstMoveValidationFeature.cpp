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

using namespace std;
using namespace Chess;

namespace {
void runTestWithOpeningMoveAndExpectedValidity(const char* moveString, MoveValidity validity)
{
    ChessEngineTestHarness testHarness;
    testHarness.setInputSequenceWithinANewGame({moveString});
    
    testHarness.chessEngine().runChessEngine();
    
    CHECK(testHarness.lastMoveRejectionReason() == validity);
}

   void runTestWithOpeningInvalidMoveOffOfBoard(const char* moveString)
   {
        runTestWithOpeningMoveAndExpectedValidity(moveString, MoveValidity::END_SQUARE_NOT_ON_BOARD);
   }

   void runTestWithValidOpeningMove(const char* moveString, PieceType type)
   {
       ChessEngineTestHarness testHarness;
       testHarness.setInputSequenceWithinANewGame({moveString});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.lastKindOfPieceMoved() == type);
       CHECK(testHarness.lastMoveDisplayedMatches(ChessMoveRequest(moveString)));
   }

   void runTestWithMoveThatDoesNotStartOnAnExistingPiece(const char* moveString)
   {
       runTestWithOpeningMoveAndExpectedValidity(moveString, MoveValidity::NO_PIECE_AT_STARTING_LOCATION);
   }

   void runTestWithMoveThatAttemptsToMoveOpposingPiece(const char* moveString)
   {
       runTestWithOpeningMoveAndExpectedValidity(moveString, MoveValidity::OPPOSING_PLAYERS_PIECE);
   }

   void runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMoveToThatSquare(const char* moveString)
   {
       runTestWithOpeningMoveAndExpectedValidity(moveString, MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
   }

   void runTestWithMoveDestinationThatIsBlockedByAnotherPiece(const char* moveString)
   {
       runTestWithOpeningMoveAndExpectedValidity(moveString, MoveValidity::DESTINATION_BLOCKED_BY_EXISTING_PIECE);
   }

   void runTestWithMovePathThatIsBlockedByAnotherPiece(const char* moveString)
   {
       runTestWithOpeningMoveAndExpectedValidity(moveString, MoveValidity::PATH_BLOCKED_BY_OTHER_PIECES);
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
       runTestWithMovePathThatIsBlockedByAnotherPiece("a1a3");
       runTestWithMovePathThatIsBlockedByAnotherPiece("h1a1");
   }

   SECTION("will detect a move that attempts to move a bishop")
   {
       runTestWithMovePathThatIsBlockedByAnotherPiece("c1a3");
       runTestWithMovePathThatIsBlockedByAnotherPiece("f1h3");
   }

   SECTION("will detect a move that attempts to move the queen")
   {
       runTestWithMovePathThatIsBlockedByAnotherPiece("e1e3");
   }

   SECTION("will detect a move that attempts to move the king")
   {
       runTestWithMoveDestinationThatIsBlockedByAnotherPiece("d1d2");
   }

   SECTION("will detect a move that moves a knight to an occupied square")
   {
       runTestWithMoveDestinationThatIsBlockedByAnotherPiece("b1d2");
       runTestWithMoveDestinationThatIsBlockedByAnotherPiece("g1e2");
   }

   SECTION("will detect a move that attempts to use a pawn to capture a nonexisting piece")
   {
       runTestWithMoveThatAttemptsToMoveAPieceThatCantCurrentlyMoveToThatSquare("c2d3");
   }
}

TEST_CASE("Testing the validation of the user's opening move when valid")
{
   SECTION("will echo back the requested move when opening move is valid (pawn)")
   {
      runTestWithValidOpeningMove("a2a3", PieceType::PAWN);
      runTestWithValidOpeningMove("a2a4", PieceType::PAWN);
   }

   SECTION("will echo back the requested move when opening move is valid (knight)")
   {
      runTestWithValidOpeningMove("b1a3", PieceType::KNIGHT);
      runTestWithValidOpeningMove("b1c3", PieceType::KNIGHT);

      runTestWithValidOpeningMove("g1h3", PieceType::KNIGHT);
      runTestWithValidOpeningMove("g1f3", PieceType::KNIGHT);
   }
}
