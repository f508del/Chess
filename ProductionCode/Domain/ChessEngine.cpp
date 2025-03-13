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
#include "CommandDefines.hpp"
#include "I_InputSystem.hpp"
#include "I_OutputSystem.hpp"

using namespace CommandDefines;
using namespace Chess;
using namespace std;

ChessEngine::ChessEngine(I_InputSystem& inputSystem,
                         I_OutputSystem& outputSystem)
: inputSystem_(inputSystem)
, outputSystem_(outputSystem)
, board_(new ChessBoard())
, moveValidator_(new ChessMoveValidator(*board_))
, userHasQuitTheProgram_(false)
{
    // TODO: some test needs to force these to exist...
    inputSystem.registerNewGameCallback(std::bind(&ChessEngine::resetForNewGame, this));
    inputSystem.registerQuitCallback(std::bind(&ChessEngine::endEventLoop, this));
    inputSystem.registerMoveAttemptCallback(std::bind(&ChessEngine::attemptMove, this, std::placeholders::_1));
}

ChessEngine::~ChessEngine()
{

}

void ChessEngine::runChessEngine()
{
    outputSystem_.initializeChessUserInterface();
    
    while (!userHasQuitTheProgram_)
    {
       inputSystem_.getNextInput();
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
    }
}
