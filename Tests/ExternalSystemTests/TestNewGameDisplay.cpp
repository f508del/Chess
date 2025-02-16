//
//  TestNewGameDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-15.
//


#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"

TEST_CASE("Test that if new game is requsted, the output system displays the expected strings")
{
    SECTION("a new game command will display the correct strings")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.initializeChessUserInterface();
        
        // TODO: add tests for the other strings that show up in new game...
        CHECK(terminalWrapper->lastOutputMatches("Press 'n' for a new game."));
    }
}
