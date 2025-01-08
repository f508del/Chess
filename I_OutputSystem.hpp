//
//  I_OutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

class I_OutputSystem
{
public:
    virtual ~I_OutputSystem(){}
    virtual void showTextToUser(const char* displayString) = 0;
    virtual void initializeChessUserInterface() = 0;

};
