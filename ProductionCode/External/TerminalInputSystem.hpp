//
//  TerminalInputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#pragma once

#include "I_InputSystem.hpp"

class TerminalInputSystem : public I_InputSystem
{
public:
   explicit TerminalInputSystem();
   virtual ~TerminalInputSystem();

   std::string getNextInput() override;
};
