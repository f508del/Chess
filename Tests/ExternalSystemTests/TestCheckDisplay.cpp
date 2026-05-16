//
//  TestCheckDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-03-16.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "StringBasedOutputSystem.hpp"

TEST_CASE("Test that if check occurs, the interaction systems behaves as expected")
{
    SECTION("A check event will display the correct string")
    {
        FakeTerminalWrapper terminalWrapper;
        StringBasedOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.declareCheck();
        
        CHECK(terminalWrapper.lastOutputMatches("Check!"));
    }
}

