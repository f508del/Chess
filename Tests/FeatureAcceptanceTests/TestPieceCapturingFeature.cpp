//
//  TestPieceCapturingFeature.h
//  Chess
//
//  Created by Trevor Phillips on 2025-02-17.
//

#include "Catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessMove.hpp"

using namespace Chess;

TEST_CASE("Testing the logic around capturing pieces")
{
    SECTION("Will allow white bishops to move into a square occupied by a black bishop")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"d2d4", "e7e5", "c1g5", "f8e7", "g5e7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::VALID_MOVE);
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::BISHOP);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("g5e7")));
    }
}
