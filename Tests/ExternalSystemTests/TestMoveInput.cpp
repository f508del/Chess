//
//  TestMoveInput.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-19.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalInputSystem.hpp"
#include "ChessPieceType.hpp"

TEST_CASE("Testing the external system that chess move inputs trigger input logic")
{
    
    SECTION("Move input strings will trigger move input attempt logic")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalInputSystem inputSystem(terminalWrapper);
        bool moveLogicHasBeenTriggered = false;
        std::function<void(const ChessMoveRequest&)> moveLogic([&](const ChessMoveRequest&){moveLogicHasBeenTriggered = true;});
        inputSystem.registerMoveAttemptCallback(moveLogic);
        terminalWrapper.enqueueInput({"a2a3"});
        
        inputSystem.getNextInput();
        
        CHECK(moveLogicHasBeenTriggered);
    }
    
    SECTION("Pawn promotion to a knight will trigger promotion selection logic")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalInputSystem inputSystem(terminalWrapper);
        bool promotionLogicHasBeenTriggered = false;
        std::function<void(Chess::PieceType type)> promotionLogic([&](Chess::PieceType){promotionLogicHasBeenTriggered = true;});
        inputSystem.registerPromotionSelectionCallback(promotionLogic);
        terminalWrapper.enqueueInput({"knight"});
        
        inputSystem.getNextInput();
        
        CHECK(promotionLogicHasBeenTriggered);
    }
    
    SECTION("Pawn promotion to a bishop will trigger promotion selection logic")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalInputSystem inputSystem(terminalWrapper);
        bool promotionLogicHasBeenTriggered = false;
        std::function<void(Chess::PieceType type)> promotionLogic([&](Chess::PieceType){promotionLogicHasBeenTriggered = true;});
        inputSystem.registerPromotionSelectionCallback(promotionLogic);
        terminalWrapper.enqueueInput({"bishop"});
        
        inputSystem.getNextInput();
        
        CHECK(promotionLogicHasBeenTriggered);
    }
    
    SECTION("Pawn promotion to a rook will trigger promotion selection logic")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalInputSystem inputSystem(terminalWrapper);
        bool promotionLogicHasBeenTriggered = false;
        std::function<void(Chess::PieceType type)> promotionLogic([&](Chess::PieceType){promotionLogicHasBeenTriggered = true;});
        inputSystem.registerPromotionSelectionCallback(promotionLogic);
        terminalWrapper.enqueueInput({"rook"});
        
        inputSystem.getNextInput();
        
        CHECK(promotionLogicHasBeenTriggered);
    }
    
    SECTION("Pawn promotion to a queen will trigger promotion selection logic")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalInputSystem inputSystem(terminalWrapper);
        bool promotionLogicHasBeenTriggered = false;
        std::function<void(Chess::PieceType type)> promotionLogic([&](Chess::PieceType){promotionLogicHasBeenTriggered = true;});
        inputSystem.registerPromotionSelectionCallback(promotionLogic);
        terminalWrapper.enqueueInput({"queen"});
        
        inputSystem.getNextInput();
        
        CHECK(promotionLogicHasBeenTriggered);
    }
}
