//
//  TestPieceCapturingFeature.h
//  Chess
//
//  Created by Trevor Phillips on 2025-02-17.
//

#include "Catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessMoveRequest.hpp"

using namespace Chess;

TEST_CASE("Testing the logic around capturing pieces")
{
    SECTION("Will allow white bishops to move into a square occupied by a black bishop")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"d2d4", "e7e5", "c1g5", "f8e7", "g5e7"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::VALID_MOVE);
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::BISHOP);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessSquare('g',5), ChessSquare('e',7)));
    }
    
    SECTION("Will not allow captured pieces to move. Once captured they are not available to owner")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"d2d4", "e7e5", "c1g5", "f8e7", "g5e7", "e7f6"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::OPPOSING_PLAYERS_PIECE);
    }
    
    SECTION("Will not allow pieces to capture friendly pieces")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"c1b2"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::DESTINATION_BLOCKED_BY_EXISTING_PIECE);
    }
    
    SECTION("Pawns can capture diagonally")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"d2d4", "c7c5", "d4c5"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::VALID_MOVE);
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::PAWN);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessSquare('d',4), ChessSquare('c',5)));
    }
    
    SECTION("Pawns cannot capture vertically")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"d2d4", "d7d5", "d4d5"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
    }
}
