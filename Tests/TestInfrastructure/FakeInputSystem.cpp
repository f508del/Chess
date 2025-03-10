//
//  FakeInputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#include "FakeInputSystem.hpp"
#include "CommandDefines.hpp"

using namespace std;
using namespace CommandDefines;

FakeInputSystem::FakeInputSystem()
: inputBuffer_()
, newGameCallback_([]{})
, quitCallback_([]{})
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
       if (nextInput == NEW_GAME_COMMAND)
       {
           newGameCallback_();
       }
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

void FakeInputSystem::registerNewGameCallback(std::function<void ()> callback)
{
    newGameCallback_ = callback;
}

void FakeInputSystem::registerQuitCallback(std::function<void ()> callback)
{
    quitCallback_ = callback;
}
