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
#include "ChessMove.hpp"
#include "CommandDefines.hpp"
#include "OutputErrorDefines.hpp"

using namespace std;
using namespace OutputErrorDefines;
using namespace Chess;

TEST_CASE("Testing the enforcement of alternating move order")
{
   SECTION("will accept an opening move from white")
   {
       ChessEngineTestHarness testHarness;
       testHarness.setInputSequenceWithinANewGame({"c2c3"});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.lastKindOfPieceMoved() == PieceType::PAWN);
       CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("c2c3")));
   }

   SECTION("will reject an attempt to move a black piece first")
   {
      ChessEngineTestHarness testHarness;
      testHarness.setInputSequenceWithinANewGame({"c7c6"});

      testHarness.chessEngine().runChessEngine();

      CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(OPPOSING_PLAYERS_PIECE_ERROR));
   }

   SECTION("will accept the second move of the game to come from black")
   {
       ChessEngineTestHarness testHarness;
       testHarness.setInputSequenceWithinANewGame({"c2c3", "c7c6"});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.lastKindOfPieceMoved() == PieceType::PAWN);
       CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("c7c6")));
   }

   SECTION("will reject a second move of the game to come from white")
   {
      ChessEngineTestHarness testHarness;
      testHarness.setInputSequenceWithinANewGame({"c2c3", "d2d4"});

      testHarness.chessEngine().runChessEngine();

      CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(OPPOSING_PLAYERS_PIECE_ERROR));
   }

   SECTION("will accept the third move of the game to come from white")
   {
       ChessEngineTestHarness testHarness;
       testHarness.setInputSequenceWithinANewGame({"c2c3", "c7c6", "d2d4"});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.lastKindOfPieceMoved() == PieceType::PAWN);
       CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("d2d4")));
   }

   SECTION("will reject the third move of the game to come from black")
   {
       ChessEngineTestHarness testHarness;
       testHarness.setInputSequenceWithinANewGame({"c2c3", "c7c6", "d7d6"});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(OPPOSING_PLAYERS_PIECE_ERROR));
   }
}
