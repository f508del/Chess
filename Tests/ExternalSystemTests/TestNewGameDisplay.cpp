//
//  TestNewGameDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-15.
//


#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"
#include "TerminalInputSystem.hpp"

TEST_CASE("Test that if new game is requsted, the output system displays the expected strings")
{
    SECTION("a new game event will display the correct strings")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.initializeChessUserInterface();
        
        CHECK(terminalWrapper.outputContains("===============Main menu ================"));
        CHECK(terminalWrapper.outputContains("Press 'q' to quit."));
        CHECK(terminalWrapper.outputContains("Press 'n' for a new game."));
    }
    
    SECTION("Will trigger new game logic when new game command received")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalInputSystem inputSystem(terminalWrapper);
        bool newGameLogicHasBeenTriggered = false;
        std::function<void()> newGameLogic([&](){newGameLogicHasBeenTriggered = true;});
        inputSystem.registerNewGameCallback(newGameLogic);
        terminalWrapper.enqueueInput({"n"});
        
        inputSystem.getNextInput();
        
        CHECK(newGameLogicHasBeenTriggered);
    }
}
