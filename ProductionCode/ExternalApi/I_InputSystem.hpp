//
//  I_InputSystem.h
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

#include <string>

class I_InputSystem
{
public:
   virtual ~I_InputSystem(){}
   virtual std::string getNextInput() = 0;
};
