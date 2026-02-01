//
//  TestCheckFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-16.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "ChessMoveValidity.hpp"
#include "FakeOutputSystem.hpp"

TEST_CASE("Testing the logic around detecting Check situations")
{
    SECTION("Will detect check when a white queen gets aggressive early")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "a7a6", "d1h5", "a6a5", "h5f7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().checkHasBeenDeclared());
    }
    
    SECTION("Will detect check when a white pawn threatens the king")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"g2g4", "a7a6", "g4g5", "a6a5", "g5g6", "a5a4", "g6f7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().checkHasBeenDeclared());
    }
    
    SECTION("Will detect check when a white knight threatens the king")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"g1f3", "a7a6", "f3g5", "a6a5", "g5e6", "a5a4", "e6g7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().checkHasBeenDeclared());
    }
    
    SECTION("Will detect check when a black rook attacks a king")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a3", "h7h5", "a3a4", "h8h6", "a4a5", "h6e6", "a5a6", "e6e2"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().checkHasBeenDeclared());
    }
    
    SECTION("Will prevent moves that don't protect the king while in check")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a3", "h7h5", "a3a4", "h8h6", "a4a5", "h6e6", "a5a6", "e6e2", "b2b3"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == Chess::MoveValidity::CANNOT_LEAVE_KING_IN_DANGER);
    }
    
    SECTION("Will allow moves that do protect the king while in check")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a3", "h7h5", "a3a4", "h8h6", "a4a5", "h6e6", "a5a6", "e6e2", "e1e2"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == Chess::MoveValidity::VALID_MOVE);
    }
}

