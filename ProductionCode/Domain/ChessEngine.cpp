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
#include "ChessMove.hpp"
#include "ChessMoveRecord.hpp"
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
    
    blackInputSystem_.registerNewGameCallback(std::bind(&ChessEngine::resetForNewGame, this));
    blackInputSystem_.registerQuitCallback(std::bind(&ChessEngine::endEventLoop, this));
    blackInputSystem_.registerMoveAttemptCallback(std::bind(&ChessEngine::attemptMove, this, std::placeholders::_1));
}

ChessEngine::~ChessEngine()
{

}

void ChessEngine::runChessEngine()
{
    outputSystem_.initializeChessUserInterface();
    
    while (!userHasQuitTheProgram_)
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

void ChessEngine::attemptMove(const ChessMove& move)
{
    InternalChessMove lastMove = moveValidator_->validateMove(move);
    if (!lastMove.isValid())
    {
        outputSystem_.rejectMoveAttempt(lastMove.validity());
    }
    else
    {
        // order here matters, as output system needs access to board state before move is applied.
        outputSystem_.displayValidMoveToUser(move, *board_);
        ChessMoveRecord moveRecord = board_->applyMove(move);
        if (lastMove.validity() == MoveValidity::VALID_EN_PASSANT_MOVE)
        {
            // This feels hacky, but is necessary because this is the only move in the game that captures a piece
            // without moving into the square in question
            ChessSquare doomedSquare(move.endingSquare().file(), move.startingSquare().rank());
            board_->removePieceAtSquare(doomedSquare);
            moveRecord.capturedPieceSquare = doomedSquare;
            moveRecord.capturedPieceType = Chess::PieceType::PAWN;
        }
        board_->togglePlayerInitiative();
        gameHistory_->recordMove(moveRecord);
        detectEndGameConditions();
    }
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
