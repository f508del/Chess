//
//  FakeOutputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "FakeOutputSystem.hpp"

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

std::string FakeOutputSystem::mostRecentOutput() const
{
   return mostRecentOutput_;
}

bool FakeOutputSystem::contains(const std::string& outputEntry) const
{
   for (std::list<std::string>::const_iterator it = capturedOutput_.begin(); it != capturedOutput_.end(); it++)
      {
         if (*it == outputEntry)
         {
            return true;
         }
      }

   return false;
}
