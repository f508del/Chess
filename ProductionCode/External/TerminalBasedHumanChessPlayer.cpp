//
//  TerminalBasedHumanChessPlayer.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-10-28.
//

#include "TerminalBasedHumanChessPlayer.hpp"
#include "TerminalWrapper.hpp"
#include "StringBasedOutputSystem.hpp"
#include "StringBasedInputSystem.hpp"

using namespace std;

TerminalBasedHumanChessPlayer::TerminalBasedHumanChessPlayer()
: terminalWrapper_(new TerminalWrapper())
, outputSystem_(new StringBasedOutputSystem(*terminalWrapper_))
, inputSystem_(new StringBasedInputSystem(*terminalWrapper_))
{
    
}

void TerminalBasedHumanChessPlayer::getNextInput()
{
    inputSystem_->getNextInput();
}

void TerminalBasedHumanChessPlayer::registerNewGameCallback(std::function<void ()> callback)
{
    inputSystem_->registerNewGameCallback(callback);
}

void TerminalBasedHumanChessPlayer::registerQuitCallback(std::function<void ()> callback)
{
    inputSystem_->registerQuitCallback(callback);
}

void TerminalBasedHumanChessPlayer::registerMoveAttemptCallback(std::function<void (const ChessMoveRequest &)> callback)
{
    inputSystem_->registerMoveAttemptCallback(callback);
}

void TerminalBasedHumanChessPlayer::registerPromotionSelectionCallback(std::function<void (Chess::PieceType)> callback)
{
    inputSystem_->registerPromotionSelectionCallback(callback);
}

void TerminalBasedHumanChessPlayer::initializeChessUserInterface()
{
    outputSystem_->initializeChessUserInterface();
}

void TerminalBasedHumanChessPlayer::endUserInteraction()
{
    outputSystem_->endUserInteraction();
}

void TerminalBasedHumanChessPlayer::resetUxForNewGame()
{
    outputSystem_->resetUxForNewGame();
}

void TerminalBasedHumanChessPlayer::displayValidMoveToUser(const std::list<Chess::MoveElement> &moveElements)
{
    outputSystem_->displayValidMoveToUser(moveElements);
}

void TerminalBasedHumanChessPlayer::rejectMoveAttempt(Chess::MoveValidity validity)
{
    outputSystem_->rejectMoveAttempt(validity);
}

void TerminalBasedHumanChessPlayer::declareCheck()
{
    outputSystem_->declareCheck();
}

void TerminalBasedHumanChessPlayer::declareCheckmate()
{
    outputSystem_->declareCheckmate();
}

void TerminalBasedHumanChessPlayer::declareStalemate()
{
    outputSystem_->declareStalemate();
}

void TerminalBasedHumanChessPlayer::requestPromotionDecision()
{
    outputSystem_->requestPromotionDecision();
}

void TerminalBasedHumanChessPlayer::notifyUserOfPromotionTo(Chess::PieceType type)
{
    outputSystem_->notifyUserOfPromotionTo(type);
}

void TerminalBasedHumanChessPlayer::gameEndedDueToTooManyConsecutiveInvalidMoveAttempts()
{
    outputSystem_->gameEndedDueToTooManyConsecutiveInvalidMoveAttempts();
}

string TerminalBasedHumanChessPlayer::playerIdentifier() const
{
    return string("human player");
}

