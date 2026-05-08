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

RandomAi::RandomAi()
: moveAttemptCallback_([](const ChessMoveRequest&){})
, promotionCallback_([](Chess::PieceType){})
, board_(new ChessBoard())
{
    
}

void RandomAi::getNextInput()
{
    std::list<ChessSquare> potentialStartingSquares = board_->allSquaresOccupiedByColor(PieceAffiliation::BLACK_PIECE);
    
    const I_ChessPiece* pieceToMove = board_->pieceAt(*potentialStartingSquares.begin());
    
    ExtendedSet<ChessSquare> destinationSquares = pieceToMove->potentialEmptyBoardMovesFrom(*potentialStartingSquares.begin());
    
    ChessMoveRequest request(*potentialStartingSquares.begin(), *destinationSquares.begin());
    
    moveAttemptCallback_(request);
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
    return;
}

void RandomAi::notifyUserOfPromotionTo(Chess::PieceType /*type*/)
{
    return;
}

void RandomAi::gameEndedDueToTenConsecutiveInvalidMoveAttempts()
{ 
    return;
}

