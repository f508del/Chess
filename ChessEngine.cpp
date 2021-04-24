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
   displayMainMenu();
   
   string userInput;
   while (true)
      {
      userInput = inputSystem_.readNextUserEntry();
      transform(userInput.begin(), userInput.end(), userInput.begin(),
                     [](unsigned char c){return tolower(c);});
      if (userInput == QUIT_COMMAND)
         {
         break;
         }
      else if (userInput == NEW_GAME_COMMAND)
         {
         outputSystem_.showTextToUser("New game requested...");
         outputSystem_.showTextToUser("you are playing as white...");
         outputSystem_.showTextToUser("please enter a move in fully specified notation...");
         }
      else
         {
         // attempt to read in the input as a move...
         ChessMove move;
         move.populateFromString(userInput);
         if (!moveValidator_->isLegalMove(move))
            {
            outputSystem_.showTextToUser(moveValidator_->commentOnLastMove().c_str());
            }
         else
            {
            outputSystem_.showTextToUser(moveDescriber_->describeMove(move,*board_).c_str());
            }
         }
      }

   outputSystem_.showTextToUser("quitting chess...");
}

void ChessEngine::displayMainMenu()
{
   outputSystem_.showTextToUser("===============Main menu ================");
   outputSystem_.showTextToUser("Press 'q' to quit.");
   outputSystem_.showTextToUser("Press 'n' for a new game.");
}
