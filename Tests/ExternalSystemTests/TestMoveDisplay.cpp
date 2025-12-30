//
//  TestMoveDisplayLogic.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include "Catch.hpp"
#include "ChessMoveElement.hpp"
#include "ChessMoveElementAction.hpp"
#include "ChessPieceAffiliation.hpp"
#include "ChessPieceType.hpp"
#include "FakeTerminalWrapper.hpp"
#include "TerminalOutputSystem.hpp"
#include "TerminalInputSystem.hpp"
#include "ChessMoveRequest.hpp"

using namespace Chess;

TEST_CASE("Testing the external system that chess moves are displayed as intended")
{
    SECTION("Pawn moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        std::list<MoveElement> elements;
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('a',2), PieceAffiliation::WHITE_PIECE, PieceType::PAWN));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('a',3), PieceAffiliation::WHITE_PIECE, PieceType::PAWN));
        
        outputSystem.displayValidMoveToUser(elements);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Pawn a2a3"));
    }
    
    SECTION("Knight moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        std::list<MoveElement> elements;
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('b',1), PieceAffiliation::WHITE_PIECE, PieceType::KNIGHT));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('a',3), PieceAffiliation::WHITE_PIECE, PieceType::KNIGHT));
        
        outputSystem.displayValidMoveToUser(elements);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Knight b1a3"));
    }
    
    SECTION("Bishop moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        std::list<MoveElement> elements;
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('c',1), PieceAffiliation::WHITE_PIECE, PieceType::BISHOP));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('b',2), PieceAffiliation::WHITE_PIECE, PieceType::BISHOP));
        
        outputSystem.displayValidMoveToUser(elements);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Bishop c1b2"));
    }
    
    SECTION("Rook moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        std::list<MoveElement> elements;
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('a',1), PieceAffiliation::WHITE_PIECE, PieceType::ROOK));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('a',2), PieceAffiliation::WHITE_PIECE, PieceType::ROOK));
        
        outputSystem.displayValidMoveToUser(elements);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Rook a1a2"));
    }
    
    SECTION("Queen moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        std::list<MoveElement> elements;
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('d',1), PieceAffiliation::WHITE_PIECE, PieceType::QUEEN));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('d',3), PieceAffiliation::WHITE_PIECE, PieceType::QUEEN));
        
        outputSystem.displayValidMoveToUser(elements);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving Queen d1d3"));
    }
    
    SECTION("King moves are described correctly")
    {
        FakeTerminalWrapper terminalWrapper;
        TerminalOutputSystem outputSystem(terminalWrapper);
        std::list<MoveElement> elements;
        elements.push_back(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('e',1), PieceAffiliation::WHITE_PIECE, PieceType::KING));
        elements.push_back(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('e',2), PieceAffiliation::WHITE_PIECE, PieceType::KING));
        
        outputSystem.displayValidMoveToUser(elements);
        
        CHECK(terminalWrapper.lastOutputMatches("Moving King e1e2"));
    }
    
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
}

