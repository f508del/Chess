//
//  I_InputSystem.h
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

#include <string>
#include <functional>

class I_InputSystem
{
public:
    virtual ~I_InputSystem(){}
    virtual std::string getNextInput() = 0;
    
    virtual void registerNewGameCallback(std::function<void()> callback) = 0;
};

