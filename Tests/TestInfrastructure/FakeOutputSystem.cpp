//
//  FakeOutputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "FakeOutputSystem.hpp"

using namespace std;

FakeOutputSystem::FakeOutputSystem()
{

}

FakeOutputSystem::~FakeOutputSystem()
{

}

void FakeOutputSystem::showTextToUser(const char* displayString)
{
   mostRecentOutput_ = displayString;
   capturedOutput_.push_back(displayString);
}

size_t FakeOutputSystem::size() const
{
   return capturedOutput_.size();
}

string FakeOutputSystem::mostRecentOutput() const
{
   return mostRecentOutput_;
}

string FakeOutputSystem::secondLastOutput() const
{
   if (size() < 2)
      {
      return "";
      }
   list<string>::const_iterator it = capturedOutput_.end();
   it--;
   it--;
   return *it;
}

bool FakeOutputSystem::contains(const string& outputEntry) const
{
   for (list<string>::const_iterator it = capturedOutput_.begin(); it != capturedOutput_.end(); it++)
      {
         if (*it == outputEntry)
         {
            return true;
         }
      }

   return false;
}

void FakeOutputSystem::initializeChessUserInterface()
{ 
    return;
}

void FakeOutputSystem::endUserInteraction()
{
    showTextToUser("quitting chess...");
}

void FakeOutputSystem::resetUxForNewGame()
{
    showTextToUser("New game requested...");
    showTextToUser("you are playing as white...");
    showTextToUser("please enter a move in fully specified notation...");
}

void FakeOutputSystem::displayMoveToUser(const ChessMove &/*move*/, const I_ReadOnlyChessBoard &/*board*/)
{
    
}


