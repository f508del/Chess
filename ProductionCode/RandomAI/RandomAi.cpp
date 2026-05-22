//
//  RandomAi.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-05-06.
//

#include "RandomAi.hpp"
#include "InternalChessMove.hpp"
#include "I_ChessPiece.hpp"
#include "ChessMoveRequest.hpp"

using namespace Chess;

RandomAi::RandomAi(PieceAffiliation affiliationToPlay)
: moveAttemptCallback_([](const ChessMoveRequest&){})
, promotionCallback_([](Chess::PieceType){})
, board_(new ChessBoard())
, gameHistory_()
, moveValidator_(*board_, gameHistory_)
, colorBeingPlayed_(affiliationToPlay)
, needToSubmitPromotionDecision_(false)
{
    srand((unsigned int)time(NULL));
}

void RandomAi::getNextInput()
{
    if (needToSubmitPromotionDecision_)
    {
        promotionCallback_(PieceType::QUEEN);
        needToSubmitPromotionDecision_ = false;
        return;
    }
    
    std::list<InternalChessMove> potentialValidMoves = moveValidator_.findAllPotentialMovesFor(colorBeingPlayed_);
    unsigned long int potentialMoveCount = potentialValidMoves.size();
    unsigned long int moveIndexToMake = rand() % (potentialMoveCount);
    auto validMoveIterator = potentialValidMoves.begin();
    while (moveIndexToMake--)
    {
        validMoveIterator++;
    }
    
    ChessMoveRequest moveRequest = convertInternalMoveToRequest(*validMoveIterator);
           
    moveAttemptCallback_(moveRequest);
    
    return;
}

void RandomAi::registerNewGameCallback(std::function<void ()> /*callback*/)
{
    // no need to track this, as this agent won't ask for a new game
    return;
}

void RandomAi::registerQuitCallback(std::function<void ()> /*callback*/)
{
    // no need to track this, as this agent won't ask to quit.
    return;
}

void RandomAi::registerMoveAttemptCallback(std::function<void (const ChessMoveRequest &)> callback)
{
    moveAttemptCallback_ = callback;
    return;
}

void RandomAi::registerPromotionSelectionCallback(std::function<void (Chess::PieceType)> callback)
{
    promotionCallback_ = callback;
    return;
}

void RandomAi::initializeChessUserInterface()
{
    return;
}

void RandomAi::endUserInteraction()
{
    return;
}

void RandomAi::resetUxForNewGame()
{
    if (PieceAffiliation::BLACK_PIECE == board_->playerToMakeNextMove() )
    {
        board_->togglePlayerInitiative();
    }
    board_->resetBoard();
    return;
}

void RandomAi::displayValidMoveToUser(const std::list<Chess::MoveElement>& moveElements)
{
    InternalChessMove convertedMove;
    for (auto iterator = moveElements.begin(); iterator != moveElements.end(); iterator++)
    {
        convertedMove.addValidMoveElement(*iterator);
    }
    board_->applyMove(convertedMove);
    gameHistory_.recordMove(convertedMove);
    board_->togglePlayerInitiative();
    return;
}

void RandomAi::rejectMoveAttempt(Chess::MoveValidity /*validity*/)
{
    return;
}

void RandomAi::declareCheck()
{ 
    return;
}

void RandomAi::declareCheckmate()
{ 
    return;
}

void RandomAi::declareStalemate()
{ 
    return;
}

void RandomAi::requestPromotionDecision()
{
    needToSubmitPromotionDecision_ = true;
    return;
}

void RandomAi::notifyUserOfPromotionTo(Chess::PieceType /*type*/)
{
    return;
}

void RandomAi::gameEndedDueToTooManyConsecutiveInvalidMoveAttempts()
{ 
    return;
}

ChessMoveRequest RandomAi::convertInternalMoveToRequest(const InternalChessMove &move)
{
    if (!move.isValid())
    {
        return ChessMoveRequest();
    }
    
    ChessSquare startSquare = move.moveElements().front().square_;
    ChessSquare endSquare = (++(move.moveElements().begin()))->square_;
    
    return ChessMoveRequest(startSquare, endSquare);
}

std::string RandomAi::playerIdentifier() const
{
    return "random";
}
