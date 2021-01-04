//
//  FakeInputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "FakeInputSystem.hpp"

using namespace std;

FakeInputSystem::FakeInputSystem()
: inputBuffer_()
{

}

FakeInputSystem::~FakeInputSystem()
{

}

string FakeInputSystem::readNextUserEntry()
{
   if (!inputBuffer_.empty())
      {
      string nextInput = inputBuffer_.front();
      inputBuffer_.pop_front();
      return nextInput;
      }
   return string();
}

void FakeInputSystem::setInputSequence(list<string> &inputSequence)
{
   inputBuffer_ = inputSequence;
}

void FakeInputSystem::clearInputSequence()
{
   inputBuffer_.clear();
}
