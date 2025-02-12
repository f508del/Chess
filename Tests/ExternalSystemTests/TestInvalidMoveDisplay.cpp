//
//  TestInvalidMoveDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-11.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"
#include "OutputErrorDefines.hpp"

using namespace Chess;

TEST_CASE("Test that if a user makes an invalid move, the display will show the correct string")
{
    SECTION("A move with the destination square not on the board")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.rejectMoveAttempt(MoveValidity::END_SQUARE_NOT_ON_BOARD);
        
        CHECK(terminalWrapper->lastOutputMatches(OutputErrorDefines::MOVE_NOT_ON_BOARD_ERROR));
    }
    
    SECTION("A move that didn't start with an existing piece")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.rejectMoveAttempt(MoveValidity::NO_PIECE_AT_STARTING_LOCATION);
        
        CHECK(terminalWrapper->lastOutputMatches(OutputErrorDefines::NO_PIECE_AT_COORDINATES_ERROR));
    }
    
    SECTION("A move that attempts to use an opposing players piece")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.rejectMoveAttempt(MoveValidity::OPPOSING_PLAYERS_PIECE);
        
        CHECK(terminalWrapper->lastOutputMatches(OutputErrorDefines::OPPOSING_PLAYERS_PIECE_ERROR));
    }
    
    SECTION("A move that attempts to move a piece in a way that it cannot in one move")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.rejectMoveAttempt(MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE);
        
        CHECK(terminalWrapper->lastOutputMatches(OutputErrorDefines::PIECE_CANNOT_CURRENTLY_MOVE_ERROR));
    }
    
    SECTION("A move that attempts to move a piece through a path that is blocked by other pieces")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.rejectMoveAttempt(MoveValidity::PATH_BLOCKED_BY_OTHER_PIECES);
        
        CHECK(terminalWrapper->lastOutputMatches(OutputErrorDefines::MOVE_IS_BLOCKED_ERROR));
    }
    
    SECTION("A move that attempts to move a piece to a destination that is blocked by other pieces")
    {
        FakeTerminalWrapper* terminalWrapper = new FakeTerminalWrapper();
        TerminalOutputSystem outputSystem(terminalWrapper);
        
        outputSystem.rejectMoveAttempt(MoveValidity::DESTINATION_BLOCKED_BY_EXISTING_PIECE);
        
        CHECK(terminalWrapper->lastOutputMatches(OutputErrorDefines::MOVE_IS_BLOCKED_ERROR));
    }
}
