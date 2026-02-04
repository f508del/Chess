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
        
        CHECK(testHarness.fakeOutput().checkmateHasBeenDeclared());
    }
}
