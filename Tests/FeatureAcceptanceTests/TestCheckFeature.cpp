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
        
        printf("SKIPPED TEST for detecting check!");
        //CHECK(testHarness.fakeOutput().checkHasBeenDeclared());
    }
    
}

