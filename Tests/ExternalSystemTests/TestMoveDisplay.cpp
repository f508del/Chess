//
//  TestMoveDisplayLogic.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"
#include "TerminalInputSystem.hpp"
#include "ChessBoard.hpp"
#include "ChessMove.hpp"

TEST_CASE("Testing the external system that chess moves are displayed as intended")
{
    SECTION("Pawn moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        outputSystem.displayValidMoveToUser(ChessMove("a2a3"), board);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Pawn a2a3"));
    }
    
    SECTION("Knight moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        outputSystem.displayValidMoveToUser(ChessMove("b1a3"), board);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Knight b1a3"));
    }
    
    SECTION("Bishop moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        board.applyMove(ChessMove("b2b3"));
        outputSystem.displayValidMoveToUser(ChessMove("c1b2"), board);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Bishop c1b2"));
    }
    
    SECTION("Rook moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        board.applyMove(ChessMove("a2a4"));
        outputSystem.displayValidMoveToUser(ChessMove("a1a2"), board);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Rook a1a2"));
    }
    
    SECTION("Queen moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        board.applyMove(ChessMove("e2e4"));
        outputSystem.displayValidMoveToUser(ChessMove("e1e3"), board);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Queen e1e3"));
    }
    
    SECTION("King moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        ChessBoard board;
        board.applyMove(ChessMove("d2d4"));
        outputSystem.displayValidMoveToUser(ChessMove("d1d2"), board);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving King d1d2"));
    }
    
    SECTION("Move input strings will trigger move input attempt logic")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalInputSystem inputSystem(terminalWrapper);
        bool moveLogicHasBeenTriggered = false;
        std::function<void(const ChessMove&)> moveLogic([&](const ChessMove&){moveLogicHasBeenTriggered = true;});
        inputSystem.registerMoveAttemptCallback(moveLogic);
        terminalWrapper.enqueueInput({"a2a3"});
        
        inputSystem.getNextInput();
        
        CHECK(moveLogicHasBeenTriggered);
    }
}

