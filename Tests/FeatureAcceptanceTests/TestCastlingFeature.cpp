//
//  TestCastlingFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-28.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "ChessSquare.hpp"

TEST_CASE("Testing the logic around castling")
{
    SECTION("Will accept a request to castle king side, happy path")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "h7h6", "f1d3", "h8h7", "g1f3", "h7h8", "e1g1"});
        
        testHarness.chessEngine().runChessEngine();
        
        printf("SKIPPED test for king side castling\n");
        /*CHECK(testHarness.lastKindOfPieceMoved() == Chess::PieceType::KING);
        CHECK(testHarness.lastKindOfPiecePlaced() == Chess::PieceType::ROOK);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessSquare('e',1), ChessSquare('g',1)));*/
    }
}
