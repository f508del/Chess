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
}

std::string FakeOutputSystem::mostRecentOutput()
{
   return mostRecentOutput_;
}
