//
//  FakeOutputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "FakeOutputSystem.hpp"
#include "ChessMoveElement.hpp"
#include "I_ChessPiece.hpp"
#include "I_ReadOnlyChessBoard.hpp"

using namespace std;
using namespace Chess;

FakeOutputSystem::FakeOutputSystem()
: lastPieceMoved_(PieceType::NONE)
, lastPiecePlaced_(PieceType::NONE)
, lastRejectedMoveReason_(Chess::MoveValidity::VALID_MOVE)
, lastMoveStartingSquare_()
, lastMoveEndingSquare_()
, userInteractionEndRequested_(false)
, resetUxForNewGameHasBeenCalled_(false)
, checkHasBeenDeclared_(false)
, promotionPromptHasBeenRequested_(false)
, lastNotifiedPromotion_(Chess::PieceType::NONE)
{

}

FakeOutputSystem::~FakeOutputSystem()
{

}

void FakeOutputSystem::initializeChessUserInterface()
{ 
    return;
}

void FakeOutputSystem::endUserInteraction()
{
    userInteractionEndRequested_ = true;
}

void FakeOutputSystem::resetUxForNewGame()
{
    resetUxForNewGameHasBeenCalled_ = true;
}

void FakeOutputSystem::displayValidMoveToUser(const std::list<Chess::MoveElement>& moveElements)
{
    if (moveElements.empty())
    {
        lastPieceMoved_ = PieceType::NONE;
        lastMoveStartingSquare_ = ChessSquare();
        lastMoveEndingSquare_ = ChessSquare();
    }
    else
    {
        lastPieceMoved_ = moveElements.front().type_;
        lastMoveStartingSquare_ = moveElements.front().square_;
        lastMoveEndingSquare_ = destinationSquareOfInstigatingPiece(moveElements);
    }
    
    for (auto iterator = moveElements.begin(); iterator != moveElements.end(); iterator++)
    {
        if (iterator->action_ == Chess::MoveElementAction::PLACE_PIECE)
        {
            lastPiecePlaced_ = iterator->type_;
        }
    }
    
    lastRejectedMoveReason_ = MoveValidity::VALID_MOVE;
}

ChessSquare FakeOutputSystem::lastMoveStartingSquare() const
{
    return lastMoveStartingSquare_;
}

ChessSquare FakeOutputSystem::lastMoveEndingSquare() const
{
    return lastMoveEndingSquare_;
}

PieceType FakeOutputSystem::lastPieceMoved() const
{
    return lastPieceMoved_;
}

PieceType FakeOutputSystem::lastPiecePlaced() const
{
    return lastPiecePlaced_;
}

void FakeOutputSystem::rejectMoveAttempt(Chess::MoveValidity validity) {
    lastRejectedMoveReason_ = validity;
}

void FakeOutputSystem::declareCheck()
{
    checkHasBeenDeclared_ = true;
}

void FakeOutputSystem::requestPromotionDecision()
{
    promotionPromptHasBeenRequested_ = true;
}

Chess::MoveValidity FakeOutputSystem::lastRejectedMoveReason() const{
    return lastRejectedMoveReason_;
}

bool FakeOutputSystem::userInteractionEndHasBeenRequested() const{
    return userInteractionEndRequested_;
}

bool FakeOutputSystem::resetUxForNewGameHasBeenCalled() const
{
    return resetUxForNewGameHasBeenCalled_;
}

bool FakeOutputSystem::checkHasBeenDeclared() const
{
    return checkHasBeenDeclared_;
}

bool FakeOutputSystem::promotionPromptHasBeenRequested() const
{
    return promotionPromptHasBeenRequested_;
}

void FakeOutputSystem::notifyUserOfPromotionTo(Chess::PieceType type)
{
    lastNotifiedPromotion_ = type;
}

Chess::PieceType FakeOutputSystem::lastNotifiedPromotion() const
{
    return lastNotifiedPromotion_;
}
