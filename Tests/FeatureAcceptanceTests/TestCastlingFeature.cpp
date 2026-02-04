//
//  TestCastlingFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-28.
//

#include "Catch.hpp"
#include "ChessEngineTestHarness.hpp"
#include "ChessEngine.hpp"
#include "ChessMoveValidity.hpp"
#include "ChessSquare.hpp"

using namespace Chess;

TEST_CASE("Testing the logic around castling")
{
    SECTION("Will accept a request to castle king side, happy path")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "h7h6", "f1d3", "h8h7", "g1f3", "h7h8", "e1g1"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastKindOfPieceMoved() == Chess::PieceType::KING);
        CHECK(testHarness.lastKindOfPiecePlaced() == Chess::PieceType::ROOK);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessSquare('e',1), ChessSquare('g',1)));
    }
    
    SECTION("Will accept a request to castle queen side, happy path")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"d2d3", "h7h6", "c1e3", "h8h7", "b1c3", "h7h8", "d1d2", "h8h7", "e1c1"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastKindOfPieceMoved() == Chess::PieceType::KING);
        CHECK(testHarness.lastKindOfPiecePlaced() == Chess::PieceType::ROOK);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessSquare('e',1), ChessSquare('c',1)));
    }
    
    SECTION("Verify that rook was actually automoved when castle request comes in.")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "h7h6", "f1d3", "h8h7", "g1f3", "h7h8", "e1g1", "h8h7", "f1e1"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastKindOfPieceMoved() == Chess::PieceType::ROOK);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessSquare('f',1), ChessSquare('e',1)));
    }
    
    SECTION("Checking that we cannot castle if it is not the kings first move")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "h7h6", "f1d3", "h8h7", "g1f3", "h7h8", "e1f1", "h8h7", "f1e1", "h7h8", "e1g1"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
    }
    
    SECTION("Checking that cannot castle if it is not the rooks first move")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "h7h6", "f1d3", "h8h7", "g1f3", "h7h8", "h1g1", "h8h7", "g1h1", "h7h8", "e1g1"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
    }
    
    SECTION("Cannot castle if the path is blocked by friendly pieces")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "h7h6", "f1d3", "h8h7", "e1g1"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
    }
    
    SECTION("Cannot castle to move a king out of check")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"e2e3", "h7h5", "f1d3", "h8h6", "g1f3", "h6e6", "a2a3", "e6e3", "e1g1"});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastMoveRejectionReason() == MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
    }
    
    // TODO: Cannot, by castling, move the king through a threatened square
    // TODO: Cannot leave the king in threat at the end of a castle move.
}
