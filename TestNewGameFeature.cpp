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

TEST_CASE("Testing the 'new game' feature")
{
   SECTION("can start a new game at startup")
   {
       ChessEngineTestHarness testHarness;
       testHarness.setInputSequenceWithinANewGame({});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.fakeOutput().contains("New game requested..."));
   }

   SECTION("will inform user what color piece they play as")
   {
       ChessEngineTestHarness testHarness;
       testHarness.setInputSequenceWithinANewGame({});

       testHarness.chessEngine().runChessEngine();

       CHECK(testHarness.fakeOutput().contains("you are playing as white..."));
   }
    
    SECTION("Will revert initiative to white when new game is invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3", CommandDefines::NEW_GAME_COMMAND, "b2b4", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Pawn b2b4"));
    }
    
    SECTION("Will move white pawns back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3", CommandDefines::NEW_GAME_COMMAND, "a2a4", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Pawn a2a4"));
    }
    
    SECTION("Will move white knights back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "b1a3", CommandDefines::NEW_GAME_COMMAND, "b1a3", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Knight b1a3"));
    }
    
    SECTION("Will move black pawns back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "a2a3","a7a6", CommandDefines::NEW_GAME_COMMAND, "a2a3", "a7a6", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Pawn a7a6"));
    }
    
    SECTION("Will move black knights back to starting position if invoked mid game")
    {
        ChessEngineTestHarness testHarness;
        testHarness.fakeInput().setInputSequence({CommandDefines::NEW_GAME_COMMAND, "b1a3","b8a6", CommandDefines::NEW_GAME_COMMAND, "b1a3", "b8a6", CommandDefines::QUIT_COMMAND});
        
        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Knight b8a6"));
    }
}

