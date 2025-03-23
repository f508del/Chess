//
//  TestEnPassantFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-22.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "ChessMove.hpp"

using namespace Chess;

TEST_CASE("Testing the logic around detecting en Passant")
{
    SECTION("Will allow an en passant capture on the move immediately following a 2 step pawn move")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "b7b5", "a4a5", "b5b4", "c2c4", "b4c3"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::VALID_MOVE);
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::PAWN);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("b4c3")));
    }
    
    // TODO: Piece captured by en passant no longer exists on the board
    // TODO: en passant not permitted if not done immedately after the 2 step move.
    // TODO: en passant not permitted if attempted by a pawn not adjacent to the last moved pawn.
}

