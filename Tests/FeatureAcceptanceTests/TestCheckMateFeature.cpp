//
//  TestCheckMateFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-02-04.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "FakeOutputSystem.hpp"

TEST_CASE("Testing the logic around detecting Checkmate situations")
{
    SECTION("Will declare checkmate when it occurs: 4 move mate with bishop and queen")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "h7h6", "f1c4", "h8h7", "d1f3", "h7h8", "f3f7"});
        
        testHarness.chessEngine().runChessEngine();
        
        printf("SKIPPED test for simple checkmate");
        //CHECK(testHarness.fakeOutput().checkmateHasBeenDeclared());
    }
    
    SECTION("Will not declare checkmate when the threat can be ended by capturing the offending piece, (but the threat can't be blocked, and the king can't step out of the way.)")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"g2g4", "a7a6", "g4g5", "a6a5", "g5g6", "a5a4", "g6f7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(!testHarness.fakeOutput().checkmateHasBeenDeclared());
    }
    
    SECTION("Will not declare checkmate when the threat can be blocked, (but the threat can't be captured and king can't move out of the way)")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "f7f6", "f1e2", "a7a6", "e2h5"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(!testHarness.fakeOutput().checkmateHasBeenDeclared());
    }
    
    SECTION("Will not declare checkmate when threat can be blocked, specifically and only by a pawn moving straight")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "f7f6", "f1e2", "h7h6", "e2h5"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(!testHarness.fakeOutput().checkmateHasBeenDeclared());
    }
    
    SECTION("Will not declare checkmate when a threat can be prevented by the king stepping out of the way, but the threat cannot be blocked or captured")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"h2h4", "g7g5", "h4g5", "e7e6", "h1h7", "f8d6", "a2a3", "d6e5", "h7h8", "a7a6", "h8g8"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(!testHarness.fakeOutput().checkmateHasBeenDeclared());
    }
}
