//
//  TestPromotionRequestDisplay.h
//  Chess
//
//  Created by Trevor Phillips on 2026-01-19.
//


#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"

TEST_CASE("Test that if promotion trigger occurs, the user is asked to choose what to promote to, and told when it completes.")
{
    SECTION("A promotion event will display the correct string")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.requestPromotionDecision();
        
        CHECK(terminalWrapper.lastOutputMatches("Choose a promotion: 1: knight 2: bishop 3: rook 4: queen"));
    }
    
    SECTION("Once a valid promotion to queen occurs, the user is told what it was promoted to")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.notifyUserOfPromotionTo(Chess::PieceType::QUEEN);
        
        CHECK(terminalWrapper.lastOutputMatches("Pawn was promoted to a Queen."));
    }
    
    SECTION("Once a valid promotion to rook occurs, the user is told what it was promoted to")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.notifyUserOfPromotionTo(Chess::PieceType::ROOK);
        
        CHECK(terminalWrapper.lastOutputMatches("Pawn was promoted to a Rook."));
    }
}
