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
#include "ChessMoveDescriber.hpp"
#include "ChessMoveValidator.hpp"
#include "CommandDefines.hpp"
#include "I_InputSystem.hpp"
#include "I_OutputSystem.hpp"

using namespace CommandDefines;
using namespace std;

ChessEngine::ChessEngine(I_InputSystem& inputSystem,
                         I_OutputSystem& outputSystem)
: inputSystem_(inputSystem)
, outputSystem_(outputSystem)
, board_(new ChessBoard())
, moveValidator_(new ChessMoveValidator(*board_))
, moveDescriber_(new ChessMoveDescriber())
{

}

ChessEngine::~ChessEngine()
{

}

void ChessEngine::runChessEngine()
{
    outputSystem_.initializeChessUserInterface();
    
    string userInput;
    while (true)
    {
       userInput = inputSystem_.readNextUserEntry();
       if (userInput == QUIT_COMMAND)
       {
           break;
       }
       else if (userInput == NEW_GAME_COMMAND)
       {
           if (ChessPieceAffiliation::BLACK_PIECE == board_->playerToMakeNextMove() )
           {
               board_->togglePlayerInitiative();
           }
           board_->resetBoard();
           outputSystem_.resetUxForNewGame();
       }
       else
       {
           // attempt to read in the input as a move...
           ChessMove move;
           move.populateFromString(userInput);
           if (!moveValidator_->isLegalMove(move))
           {
               outputSystem_.showTextToUser(moveValidator_->reasonLastMoveWasIllegal().c_str());
           }
           else
           {
               // order here matters, as describer needs access to board state before move is applied.
               string moveDescription = moveDescriber_->describeMove(move,*board_);
               outputSystem_.displayMoveToUser(move, *board_);
               board_->applyMove(move);
               board_->togglePlayerInitiative();
               outputSystem_.showTextToUser(moveDescription.c_str());
           }
       }
    }

    outputSystem_.endUserInteraction();
}

