//
//  TestPromotionFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-19.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "ChessSquare.hpp"
#include "FakeOutputSystem.hpp"

TEST_CASE("Testing that when a pawn reaches the opposite rank on the board, promotion is handled correctly")
{
    SECTION("White pawn promotions will not trigger when reaching 7th rank.")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f6", "a4a5", "f6f5", "a5a6", "e7e6", "a6b7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(!testHarness.promotionPromptHasBeenRequested());
    }
    
    SECTION("White pawn promotions will trigger when reaching 8th rank.")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f6", "a4a5", "f6f5", "a5a6", "e7e6", "a6b7", "e6e5", "b7a8"});

        CHECK(!testHarness.promotionPromptHasBeenRequested());
        
        testHarness.chessEngine().runChessEngine();

        CHECK(testHarness.promotionPromptHasBeenRequested());
    }
    
    SECTION("Black pawn promotions will not trigger when reaching 2nd rank.")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"f2f3", "a7a5", "f3f4", "a5a4", "f4f5", "a4a3", "e2e3", "a3b2"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(!testHarness.promotionPromptHasBeenRequested());
    }
    
    SECTION("Black pawn promotions will trigger when reaching 1st rank.")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"f2f3", "a7a5", "f3f4", "a5a4", "f4f5", "a4a3", "e2e3", "a3b2", "e3e4", "b2a1"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.promotionPromptHasBeenRequested());
    }
    
    SECTION("Can promote a pawn to a knight")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f6", "a4a5", "f6f5", "a5a6", "e7e6", "a6b7", "e6e5", "b7a8", "knight"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().lastNotifiedPromotion() == Chess::PieceType::KNIGHT);
    }
    
    SECTION("Can promote a pawn to a bishop")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f6", "a4a5", "f6f5", "a5a6", "e7e6", "a6b7", "e6e5", "b7a8", "bishop"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().lastNotifiedPromotion() == Chess::PieceType::BISHOP);
    }
    
    SECTION("Can promote a pawn to a rook")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f6", "a4a5", "f6f5", "a5a6", "e7e6", "a6b7", "e6e5", "b7a8", "rook"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().lastNotifiedPromotion() == Chess::PieceType::ROOK);
    }
    
    SECTION("Can promote a pawn to a queen")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f6", "a4a5", "f6f5", "a5a6", "e7e6", "a6b7", "e6e5", "b7a8", "queen"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().lastNotifiedPromotion() == Chess::PieceType::QUEEN);
    }
    
    SECTION("Can't promote a pawn to a pawn")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f6", "a4a5", "f6f5", "a5a6", "e7e6", "a6b7", "e6e5", "b7a8", "pawn"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().lastNotifiedPromotion() == Chess::PieceType::NONE);
    }
    
    SECTION("Can't promote a pawn to a king")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f6", "a4a5", "f6f5", "a5a6", "e7e6", "a6b7", "e6e5", "b7a8", "king"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.fakeOutput().lastNotifiedPromotion() == Chess::PieceType::NONE);
    }
    
    SECTION("Will reject attempt to promote a piece other than a pawn")
    {
        
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"b1a3", "queen"});
            
        testHarness.chessEngine().runChessEngine();
            
        CHECK(testHarness.fakeOutput().lastNotifiedPromotion() == Chess::PieceType::NONE);
        CHECK(testHarness.lastMoveRejectionReason() == Chess::MoveValidity::PROMOTION_NOT_LEGAL);
        
    }
}
