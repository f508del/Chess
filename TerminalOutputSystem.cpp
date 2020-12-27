//
//  TerminalOutputSystem.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#include "TerminalOutputSystem.hpp"
#include <cstdio>

TerminalOutputSystem::TerminalOutputSystem()
{

}

TerminalOutputSystem::~TerminalOutputSystem()
{

}

void TerminalOutputSystem::showTextToUser(const char* displayString)
{
   fprintf(stdout, "%s\n", displayString);
}
