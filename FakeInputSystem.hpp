//
//  FakeInputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "I_InputSystem.hpp"
#include <list>

class FakeInputSystem : public I_InputSystem
{
public:
   explicit FakeInputSystem();
   virtual ~FakeInputSystem();

   // from I_InputSystem:
   std::string readNextUserEntry() override;

   // Helpers
   void setInputSequence(const std::list<std::string>& inputSequence);
   void clearInputSequence();

private:
   std::list<std::string> inputBuffer_;
};
