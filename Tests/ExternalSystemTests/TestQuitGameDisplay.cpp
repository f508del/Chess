//
//  TestQuitGameDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-15.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"
#include "StringBasedInputSystem.hpp"

TEST_CASE("Test that if quit is requested, the interaction systems behaves as expected")
{
    SECTION("a quit event will display the correct string")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.endUserInteraction();
        
        CHECK(terminalWrapper.lastOutputMatches("quitting chess..."));
    }
    
    SECTION("A quit input will trigger the quit logic")
    {
        FakeTerminalWrapper terminalWrapper;
        StringBasedInputSystem inputSystem(terminalWrapper);
        bool quitLogicHasBeenTriggered = false;
        std::function<void()> quitLogic([&](){quitLogicHasBeenTriggered = true;});
        inputSystem.registerQuitCallback(quitLogic);
        terminalWrapper.enqueueInput({"q"});
        
        inputSystem.getNextInput();
        
        CHECK(quitLogicHasBeenTriggered);
    }
}

