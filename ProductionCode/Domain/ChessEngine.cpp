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

namespace {
const unsigned int MAX_ALLOWABLE_CONSECUTIVE_INVALID_MOVE_ATTEMPTS = 10;
}


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
, consecutiveInvalidMoveAttemptCounter_(0)
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
    consecutiveInvalidMoveAttemptCounter_ = 0;
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
        consecutiveInvalidMoveAttemptCounter_++;
        if (consecutiveInvalidMoveAttemptCounter_ >= MAX_ALLOWABLE_CONSECUTIVE_INVALID_MOVE_ATTEMPTS)
        {
            outputSystem_.gameEndedDueToTenConsecutiveInvalidMoveAttempts();
            resetForNewGame();
        }
    }
    else
    {
        consecutiveInvalidMoveAttemptCounter_ = 0;
        // order here matters, as output system needs access to board state before move is applied.
        outputSystem_.displayValidMoveToUser(validatedMove.moveElements());
        board_->applyMove(validatedMove);
        gameHistory_->recordMove(validatedMove);
        if (board_->hasAnyPawnReachedFinalRank())
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
    
    if (moveValidator_->isSquareThreatenedByColor(kingSquareThatMayBeInCheck, playerThatMadeLastMove))
    {
        if (pieceThreateningTheKingCanBeCapturedWithoutLeavingKingInThreat(kingSquareThatMayBeInCheck, playerThatMadeLastMove))
        {
            outputSystem_.declareCheck();
        }
        else if (pieceThreateningKingCanBeBlockedWithoutLeavingKingInThreat(kingSquareThatMayBeInCheck, playerThatMadeLastMove))
        {
            outputSystem_.declareCheck();
        }
        else if (kingCanMoveOutOfThreat(kingSquareThatMayBeInCheck))
        {
            outputSystem_.declareCheck();
        }
        else
        {
            outputSystem_.declareCheckmate();
        }
    }
    else
    {
        if (playerHasNoLegalMove(board_->playerToMakeNextMove()))
        {
            outputSystem_.declareStalemate();
        }
    }
    
    return;
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

bool ChessEngine::pieceThreateningTheKingCanBeCapturedWithoutLeavingKingInThreat(const ChessSquare& kingSquareInThreat, Chess::PieceAffiliation attackingColor)
{
    PieceAffiliation defendingColor = oppositePieceAffiliation(attackingColor);
    ChessSquare locationOfAttackingPiece = moveValidator_->findSquareOfPieceThatCouldCapture(kingSquareInThreat, attackingColor, *board_);
    ChessSquare sourceSquareOfPotentialCounterMove = moveValidator_->findSquareOfPieceThatCouldCapture(locationOfAttackingPiece, defendingColor, *board_);
    
    if (!sourceSquareOfPotentialCounterMove.isSquareOnTheBoard())
    {
        return false;
    }
    
    InternalChessMove proposedCounterMove;
    proposedCounterMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE, sourceSquareOfPotentialCounterMove,
                                                        defendingColor, board_->pieceAt(sourceSquareOfPotentialCounterMove)->pieceType()));
    proposedCounterMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE, locationOfAttackingPiece,
                                                               attackingColor, board_->pieceAt(locationOfAttackingPiece)->pieceType()));
    proposedCounterMove.addValidMoveElement(MoveElement(MoveElementAction::PLACE_PIECE, locationOfAttackingPiece,
                                                        defendingColor, board_->pieceAt(sourceSquareOfPotentialCounterMove)->pieceType()));
    
    if (!moveValidator_->movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(proposedCounterMove))
    {
        return true;
    }
    
    return false;
}

bool ChessEngine::pieceThreateningKingCanBeBlockedWithoutLeavingKingInThreat(const ChessSquare& kingSquareInThreat, Chess::PieceAffiliation attackingColor)
{
    PieceAffiliation defendingColor = oppositePieceAffiliation(attackingColor);
    ChessSquare locationOfAttackingPiece = moveValidator_->findSquareOfPieceThatCouldCapture(kingSquareInThreat, attackingColor, *board_);
    
    // If attacking piece can jump other pieces, no block is possible.
    if (board_->pieceAt(locationOfAttackingPiece)->pieceCanJumpOtherPieces())
    {
        return false;
    }
    
    // Find the squares between the location of attacker and kingsquare, and see if it can be blocked.
    list<ChessSquare> squaresBetweenEndPoints = board_->listOfSquaresBetweenEndPoints(kingSquareInThreat, locationOfAttackingPiece);
    
    for (auto it = squaresBetweenEndPoints.begin(); it != squaresBetweenEndPoints.end(); it++)
    {
        ChessSquare potentialBlockerSource = moveValidator_->findSquareOfPieceThatCouldMoveTo(*it, defendingColor);
        
        if (potentialBlockerSource.isSquareOnTheBoard())
        {
            InternalChessMove proposedCounterMove;
            PieceType blockingPieceType = board_->pieceAt(potentialBlockerSource)->pieceType();
            proposedCounterMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE, potentialBlockerSource,
                                                                defendingColor, blockingPieceType));
            proposedCounterMove.addValidMoveElement(MoveElement(MoveElementAction::PLACE_PIECE, *it,
                                                                defendingColor, blockingPieceType));
            
            if (!moveValidator_->movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(proposedCounterMove))
            {
                return true;
            }
        }
    }
    
    return false;
}

bool ChessEngine::kingCanMoveOutOfThreat(const ChessSquare& kingSquareInThreat)
{
    for (char file = kingSquareInThreat.file() - 1; file <= kingSquareInThreat.file() + 1; file++)
    {
        for (unsigned int rank = kingSquareInThreat.rank() - 1; rank <= kingSquareInThreat.rank() + 1; rank++)
        {
            ChessSquare potentialEscapeSquare(file, rank);
            InternalChessMove proposedCounterMove;
            proposedCounterMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE, kingSquareInThreat,
                                                                board_->playerToMakeNextMove(),
                                                                PieceType::KING));
            proposedCounterMove.addValidMoveElement(MoveElement(MoveElementAction::PLACE_PIECE, potentialEscapeSquare,
                                                                board_->playerToMakeNextMove(), PieceType::KING));
            bool escapeSquareCanBeMovedTo = board_->playerToMakeNextMove() == PieceAffiliation::WHITE_PIECE ?
            !board_->whitePieceExistsAt(potentialEscapeSquare) : !board_->blackPieceExistsAt(potentialEscapeSquare);
            escapeSquareCanBeMovedTo = escapeSquareCanBeMovedTo && potentialEscapeSquare.isSquareOnTheBoard();
            if (escapeSquareCanBeMovedTo &&
                !moveValidator_->movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(proposedCounterMove))
            {
                return true;
            }
        }
    }
    
    return false;
}

bool ChessEngine::playerHasNoLegalMove(Chess::PieceAffiliation playerColor)
{
    list<InternalChessMove> potentialMoves = moveValidator_->findAllPotentialMovesFor(playerColor);
    
    for (auto it = potentialMoves.begin(); it != potentialMoves.end(); it++)
    {
        if (!moveValidator_->movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(*it))
        {
            return false;
        }
    }
    return true;
}

