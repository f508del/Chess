//
//  TestCheckFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-16.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "FakeOutputSystem.hpp"

TEST_CASE("Testing the logic around detecting Check situations")
{
    SECTION("Will detect check when a queen gets aggressive early")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "a7a6", "d1h5", "a6a5", "h5f7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().checkHasBeenDeclared());
    }
    
    SECTION("Will detect check when a pawn threatens the king")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"g2g4", "a7a6", "g4g5", "a6a5", "g5g6", "a5a4", "g6f7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().checkHasBeenDeclared());
    }
    
    SECTION("Will detect check when a knight threatens the king")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"g1f3", "a7a6", "f3g5", "a6a5", "g5e6", "a5a4", "e6g7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().checkHasBeenDeclared());
    }
    
}

