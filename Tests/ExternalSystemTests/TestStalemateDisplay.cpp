//
//  TestStalemateDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-03-29.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "StringBasedOutputSystem.hpp"

TEST_CASE("Test that if stalemate occurs, the interaction systems behaves as expected")
{
    SECTION("A stalemate event will display the correct string")
    {
        FakeTerminalWrapper terminalWrapper;
        StringBasedOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.declareStalemate();
        
        CHECK(terminalWrapper.lastOutputMatches("Stalemate!"));
    }
}

