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

string FakeInputSystem::getNextInput()
{
   if (!inputBuffer_.empty())
   {
      string nextInput = inputBuffer_.front();
      inputBuffer_.pop_front();
      std::transform(nextInput.begin(), nextInput.end(), nextInput.begin(),
                         [](unsigned char c){return std::tolower(c);});
      return nextInput;
   }
   return string();
}

void FakeInputSystem::setInputSequence(const list<string> &inputSequence)
{
   inputBuffer_ = inputSequence;
}

void FakeInputSystem::clearInputSequence()
{
   inputBuffer_.clear();
}
