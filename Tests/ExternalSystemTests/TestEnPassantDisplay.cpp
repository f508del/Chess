//
//  TestEnPassantDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-19.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "StringBasedOutputSystem.hpp"
#include "ChessMoveElement.hpp"

using namespace Chess;

TEST_CASE("Testing the external system that en passant moves are displayed as intended")
{
    SECTION("Will indicate to user when en passant has ocurred")
    {
        FakeTerminalWrapper terminalWrapper;
        StringBasedOutputSystem outputSystem(terminalWrapper);
        
        std::list<MoveElement> elements;
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('b',4), PieceAffiliation::BLACK_PIECE, PieceType::PAWN));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('a',3), PieceAffiliation::BLACK_PIECE, PieceType::PAWN));
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('a',4), PieceAffiliation::WHITE_PIECE, PieceType::PAWN));
        
        outputSystem.displayValidMoveToUser(elements);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Pawn b4a3, which removes Pawn at a4 by en passant"));
    }
}
