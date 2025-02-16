//
//  TestQuitGameDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-15.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"

TEST_CASE("Test that if quit is requsted, the output system displays the expected string")
{
    SECTION("a quit command will display the correct string")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.endUserInteraction();
        
        CHECK(terminalWrapper->lastOutputMatches("quitting chess..."));
    }
}

