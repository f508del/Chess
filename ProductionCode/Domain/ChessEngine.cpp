//
//  ChessEngine.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "ChessBoard.hpp"
#include "ChessEngine.hpp"
#include "ChessGameHistory.hpp"
#include "ChessMoveRequest.hpp"
#include "ChessMoveValidator.hpp"
#include "I_ChessPiece.hpp"
#include "I_InputSystem.hpp"
#include "I_OutputSystem.hpp"
#include "InternalChessMove.hpp"

using namespace Chess;
using namespace std;

ChessEngine::ChessEngine(I_InputSystem& whiteInputSystem,
                         I_InputSystem& blackInputSystem,
                         I_OutputSystem& outputSystem)
: whiteInputSystem_(whiteInputSystem)
, blackInputSystem_(blackInputSystem)
, outputSystem_(outputSystem)
, board_(new ChessBoard())
, gameHistory_(new ChessGameHistory())
, moveValidator_(new ChessMoveValidator(*board_, *gameHistory_))
, userHasQuitTheProgram_(false)
{
    whiteInputSystem_.registerNewGameCallback(std::bind(&ChessEngine::resetForNewGame, this));
    whiteInputSystem_.registerQuitCallback(std::bind(&ChessEngine::endEventLoop, this));
    whiteInputSystem_.registerMoveAttemptCallback(std::bind(&ChessEngine::attemptMove, this, std::placeholders::_1));
    whiteInputSystem_.registerPromotionSelectionCallback(std::bind(&ChessEngine::applyPromotion, this, std::placeholders::_1));
    
    blackInputSystem_.registerNewGameCallback(std::bind(&ChessEngine::resetForNewGame, this));
    blackInputSystem_.registerQuitCallback(std::bind(&ChessEngine::endEventLoop, this));
    blackInputSystem_.registerMoveAttemptCallback(std::bind(&ChessEngine::attemptMove, this, std::placeholders::_1));
    blackInputSystem_.registerPromotionSelectionCallback(std::bind(&ChessEngine::applyPromotion, this, std::placeholders::_1));
}

ChessEngine::~ChessEngine()
{

}

void ChessEngine::runChessEngine()
{
    outputSystem_.initializeChessUserInterface();
    
    while (!userHasQuitTheProgram_)
    {
        getNextInput();
    }

    outputSystem_.endUserInteraction();
}

void ChessEngine::resetForNewGame()
{
    if (PieceAffiliation::BLACK_PIECE == board_->playerToMakeNextMove() )
    {
        board_->togglePlayerInitiative();
    }
    board_->resetBoard();
    outputSystem_.resetUxForNewGame();
}

void ChessEngine::endEventLoop()
{
    userHasQuitTheProgram_ = true;
}

void ChessEngine::attemptMove(const ChessMoveRequest& move)
{
    InternalChessMove validatedMove = moveValidator_->validateMove(move);
    if (!validatedMove.isValid())
    {
        outputSystem_.rejectMoveAttempt(validatedMove.validity());
    }
    else
    {
        // order here matters, as output system needs access to board state before move is applied.
        outputSystem_.displayValidMoveToUser(validatedMove.moveElements());
        board_->applyMove(validatedMove);
        gameHistory_->recordMove(validatedMove);
        if (pawnHasReachedFinalRank(validatedMove))
        {
            outputSystem_.requestPromotionDecision();
            getNextInput();
        }
        board_->togglePlayerInitiative();
        
        detectEndGameConditions();
    }
}

void ChessEngine::applyPromotion(Chess::PieceType type)
{
    InternalChessMove promotionMove;
    ChessSquare destinationOfMostRecentMove = gameHistory_->mostRecentMoveEndingSquare();
    
    if (gameHistory_->mostRecentMovedPiece() != PieceType::PAWN)
    {
        outputSystem_.rejectMoveAttempt(MoveValidity::PROMOTION_NOT_LEGAL);
        return;
    }
    
    if (gameHistory_->mostRecentMoveEndingSquare().rank() != 8 && gameHistory_->mostRecentMoveEndingSquare().rank() != 1)
    {
        outputSystem_.rejectMoveAttempt(MoveValidity::PROMOTION_NOT_LEGAL);
        return;
    }
    
    // Start by "picking up" the pawn at the square of the last move
    promotionMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE,
                                                  destinationOfMostRecentMove,
                                                  board_->playerToMakeNextMove(),
                                                  PieceType::PAWN));
    
    // Now place the promoted piece at the same square
    promotionMove.addValidMoveElement(MoveElement(MoveElementAction::PLACE_PIECE,
                                                  destinationOfMostRecentMove,
                                                  board_->playerToMakeNextMove(),
                                                  type));
    
    outputSystem_.notifyUserOfPromotionTo(type);
    board_->applyMove(promotionMove);
    gameHistory_->recordMove(promotionMove);
}

void ChessEngine::detectEndGameConditions()
{
    // Grab location of the king that DIDN'T move last, noting that the board has already been told to toggle player initiative
    ChessSquare kingSquareThatMayBeInCheck = board_->currentKingSquare(board_->playerToMakeNextMove());
    PieceAffiliation playerThatMadeLastMove = oppositePieceAffiliation(board_->playerToMakeNextMove());
    
    if (moveValidator_->isSquareThreatenedByColor(*board_, kingSquareThatMayBeInCheck, playerThatMadeLastMove))
    {
        outputSystem_.declareCheck();
    }
    
    return;
}

bool ChessEngine::pawnHasReachedFinalRank(const InternalChessMove& validatedMove) const
{
    if (!validatedMove.isValid())
    {
        return false;
    }
    if (validatedMove.moveElements().front().type_ != PieceType::PAWN)
    {
        return false;
    }
    unsigned int pawnStartingRank = validatedMove.moveElements().front().square_.rank();
    Chess::PieceAffiliation pawnAffiliation = validatedMove.moveElements().front().affiliation_;
    if ((pawnStartingRank == 7 && pawnAffiliation == Chess::PieceAffiliation::WHITE_PIECE) ||
       (pawnStartingRank == 2 && pawnAffiliation == Chess::PieceAffiliation::BLACK_PIECE))
    {
        // If a pawn move is both valid and starts one step from promotion... it gets promoted!
        return true;
    }
    return false;
}

void ChessEngine::getNextInput()
{
    if (PieceAffiliation::WHITE_PIECE == board_->playerToMakeNextMove())
    {
        whiteInputSystem_.getNextInput();
    }
    else
    {
        blackInputSystem_.getNextInput();
    }
}
