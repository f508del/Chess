//
//  FakeInputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "FakeInputSystem.hpp"

FakeInputSystem::FakeInputSystem()
: inputBuffer_()
{

}

FakeInputSystem::~FakeInputSystem()
{

}

std::string FakeInputSystem::readNextUserEntry()
{
   if (!inputBuffer_.empty())
      {
      std::string nextInput = inputBuffer_.front();
      inputBuffer_.pop_front();
      return nextInput;
      }
   return std::string();
}

void FakeInputSystem::setInputSequence(std::list<std::string> &inputSequence)
{
   inputBuffer_ = inputSequence;
}

void FakeInputSystem::clearInputSequence()
{
   inputBuffer_.clear();
}
