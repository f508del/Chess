//
//  TestNewGameFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-29.
//
//

#include "Catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "FakeInputSystem.hpp"
#include "FakeOutputSystem.hpp"

using namespace std;
using namespace Chess;

TEST_CASE("Testing the 'new game' feature")
{
   SECTION("can start a new game at startup")
   {
       ChessEngineTestHarness testHarness;
       testHarness.setInputSequenceWithinANewGame({});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.fakeOutput().resetUxForNewGameHasBeenCalled());
   }
    
    SECTION("Will revert initiative to white when new game is invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3", CommandDefines::NEW_GAME_COMMAND, "b2b4", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::PAWN);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("b2b4")));
    }
    
    SECTION("Will move white pawns back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3", CommandDefines::NEW_GAME_COMMAND, "a2a4", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::PAWN);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("a2a4")));
    }
    
    SECTION("Will move white knights back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "b1a3", CommandDefines::NEW_GAME_COMMAND, "b1a3", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::KNIGHT);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("b1a3")));
    }
    
    SECTION("Will move black pawns back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3","a7a6", CommandDefines::NEW_GAME_COMMAND, "a2a3", "a7a6", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::PAWN);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("a7a6")));
    }
    
    SECTION("Will move black knights back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "b1a3","b8a6", CommandDefines::NEW_GAME_COMMAND, "b1a3", "b8a6", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::KNIGHT);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("b8a6")));
    }
    
    SECTION("Will move white rooks back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a4","h7h6", "a1a3", CommandDefines::NEW_GAME_COMMAND, "a2a4","h7h6", "a1a3", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::ROOK);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("a1a3")));
    }
    
    SECTION("Will move black rooks back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3","h7h5", "a3a4", "h8h6", CommandDefines::NEW_GAME_COMMAND, "a2a3","h7h5", "a3a4", "h8h6", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::ROOK);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("h8h6")));
    }
    
    SECTION("Will move white queens back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "e2e4","a7a6", "e1e3", CommandDefines::NEW_GAME_COMMAND, "e2e4","a7a6", "e1e3", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::QUEEN);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("e1e3")));
    }
    
    SECTION("Will move black queens back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3","e7e5", "a3a4", "e8e6", CommandDefines::NEW_GAME_COMMAND, "a2a3","e7e5", "a3a4", "e8e6", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        CHECK(testHarness.lastKindOfPieceMoved() == PieceType::QUEEN);
        CHECK(testHarness.lastMoveDisplayedMatches(ChessMove("e8e6")));
    }
}

