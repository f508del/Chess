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
}

