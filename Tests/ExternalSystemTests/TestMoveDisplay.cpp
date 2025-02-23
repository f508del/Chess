//
//  TestMoveDisplayLogic.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"
#include "ChessBoard.hpp"
#include "ChessMove.hpp"

TEST_CASE("Testing the external system that chess moves are displayed as intended")
{
    SECTION("Pawn moves are described correctly")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        outputSystem.displayMoveToUser(ChessMove("a2a3"), board);
        
        CHECK(terminalWrapper->lastOutputMatches("Moving Pawn a2a3"));
    }
    
    SECTION("Knight moves are described correctly")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        outputSystem.displayMoveToUser(ChessMove("b1a3"), board);
        
        CHECK(terminalWrapper->lastOutputMatches("Moving Knight b1a3"));
    }
    
    SECTION("Bishop moves are described correctly")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        board.applyMove(ChessMove("b2b3"));
        outputSystem.displayMoveToUser(ChessMove("c1b2"), board);
        
        CHECK(terminalWrapper->lastOutputMatches("Moving Bishop c1b2"));
    }
    
    SECTION("Rook moves are described correctly")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        board.applyMove(ChessMove("a2a4"));
        outputSystem.displayMoveToUser(ChessMove("a1a2"), board);
        
        CHECK(terminalWrapper->lastOutputMatches("Moving Rook a1a2"));
    }
    
    SECTION("Queen moves are described correctly")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        board.applyMove(ChessMove("e2e4"));
        outputSystem.displayMoveToUser(ChessMove("e1e3"), board);
        
        CHECK(terminalWrapper->lastOutputMatches("Moving Queen e1e3"));
    }
}

