//
//  TestCastlingDisplay.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-05-17.
//

#include "Catch.hpp"
#include "FakeTerminalWrapper.hpp"
#include "StringBasedOutputSystem.hpp"
#include "ChessMoveElement.hpp"

using namespace Chess;

TEST_CASE("Testing the external system that castling moves are displayed as intended")
{
    SECTION("Will ensure that castling is described to user when it occurs")
    {
        FakeTerminalWrapper terminalWrapper;
        StringBasedOutputSystem outputSystem(terminalWrapper);
        
        std::list<MoveElement> elements;
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('e',1), PieceAffiliation::WHITE_PIECE, PieceType::KING));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('g',1), PieceAffiliation::WHITE_PIECE, PieceType::KING));
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('h',1), PieceAffiliation::WHITE_PIECE, PieceType::ROOK));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('f',1), PieceAffiliation::WHITE_PIECE, PieceType::ROOK));
        
        outputSystem.displayValidMoveToUser(elements);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving King e1g1, which also moves the rook h1f1"));
    }
}
