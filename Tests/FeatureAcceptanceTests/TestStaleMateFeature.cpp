//
//  TestStaleMateFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-05-05.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "FakeOutputSystem.hpp"

TEST_CASE("Testing the logic around detecting Stalemate situations")
{
    SECTION("Will declare stalemate when it occurs: 10 move stalemate")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "a7a5", "d1h5", "a8a6", "h5a5", "h7h5", "a5c7", "a6h6", "h2h4", "f7f6", "c7d7",
        "e8f7", "d7b7", "d8d3", "b7b8", "d3h7", "b8c8", "f7g6", "c8e6"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().stalemateHasBeenDeclared());
    }
}
