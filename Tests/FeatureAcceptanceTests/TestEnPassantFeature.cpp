//
//  TestEnPassantFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-22.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "ChessMoveRequest.hpp"

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
        CHECK(testHarness.lastMoveDisplayedMatches(ChessSquare('b',4), ChessSquare('c',3)));
    }
    
    SECTION("Will not allow en passant if not done immediately after the 2 step pawn move")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "b7b5", "a4a5", "b5b4", "c2c4", "f7f6", "a5a6", "b4c3"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
    }
    
    SECTION("en passant not permitted if attempted by a pawn not adjacent to the last moved pawn.")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "f7f5", "a4a5", "f5f4", "c2c4", "f4e3"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
    }
    
    SECTION("piece captured by en passant no longer exists on the board")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a4", "b7b5", "a4a5", "b5b4", "c2c4", "b4c3", "c4c5"});
            
        testHarness.chessEngine().runChessEngine();
            
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::NO_PIECE_AT_STARTING_LOCATION);
    }
}

