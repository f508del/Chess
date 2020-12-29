//
//  ChessEngine.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "ChessEngine.hpp"
#include "ChessMove.hpp"
#include "CommandDefines.hpp"
#include "I_InputSystem.hpp"
#include "I_OutputSystem.hpp"

using namespace CommandDefines;

ChessEngine::ChessEngine(I_InputSystem& inputSystem,
                         I_OutputSystem& outputSystem)
: inputSystem_(inputSystem)
, outputSystem_(outputSystem)
{

}

ChessEngine::~ChessEngine()
{

}

void ChessEngine::runChessEngine()
{
   displayMainMenu();
   
   std::string userInput;
   while (true)
      {
      userInput = inputSystem_.readNextUserEntry();
      std::transform(userInput.begin(), userInput.end(), userInput.begin(),
                     [](unsigned char c){return std::tolower(c);});
      if (userInput == QUIT_COMMAND)
         {
         break;
         }
      else if (NEW_GAME_COMMAND == userInput)
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
         outputSystem_.showTextToUser(move.toString().c_str());
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
