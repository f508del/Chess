//
//  ChessEngine.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "ChessBoard.hpp"
#include "ChessEngine.hpp"
#include "ChessMove.hpp"
#include "ChessMoveValidator.hpp"
#include "I_InputSystem.hpp"
#include "I_OutputSystem.hpp"

using namespace Chess;
using namespace std;

ChessEngine::ChessEngine(I_InputSystem& whiteInputSystem,
                         I_InputSystem& blackInputSystem,
                         I_OutputSystem& outputSystem)
: whiteInputSystem_(whiteInputSystem)
, blackInputSystem_(blackInputSystem)
, outputSystem_(outputSystem)
, board_(new ChessBoard())
, moveValidator_(new ChessMoveValidator(*board_))
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
    MoveValidity lastMoveValidity = moveValidator_->validateMove(move);
    if (lastMoveValidity != MoveValidity::VALID_MOVE)
    {
        outputSystem_.rejectMoveAttempt(lastMoveValidity);
    }
    else
    {
        // order here matters, as output system needs access to board state before move is applied.
        outputSystem_.displayValidMoveToUser(move, *board_);
        board_->applyMove(move);
        board_->togglePlayerInitiative();
        detectEndGameConditions();
    }
}

void ChessEngine::detectEndGameConditions()
{
    // Grab location of the king that DIDN'T move last, noting that the board has already been told to toggle player initiative
    Chess::PieceAffiliation affiliationThatDidNotMoveLast = board_->playerToMakeNextMove();
    ChessSquare kingSquareThatMayBeInCheck = board_->currentKingSquare(affiliationThatDidNotMoveLast);
    Chess::PieceAffiliation playerThatMadeLastMove = (affiliationThatDidNotMoveLast == Chess::PieceAffiliation::WHITE_PIECE ? Chess::PieceAffiliation::BLACK_PIECE : Chess::PieceAffiliation::WHITE_PIECE);
    
    board_->togglePlayerInitiative();
    
    // Go through each piece of the side that did move last, see if any of their pieces could validly move into the opposing king's square (from above)
    list<ChessSquare> attackingPieces = board_->allSquaresOccupiedByColor(playerThatMadeLastMove);
    for (auto iterator = attackingPieces.begin(); iterator != attackingPieces.end(); iterator++)
    {
        if (moveValidator_->validateMove(ChessMove(*iterator, kingSquareThatMayBeInCheck)) == Chess::MoveValidity::VALID_MOVE)
        {
            outputSystem_.declareCheck();
            board_->togglePlayerInitiative();
            return;
        }
    }
    board_->togglePlayerInitiative();
    return;
}
