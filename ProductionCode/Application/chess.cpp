/*
 ******************************************************************************
 *  
 * \file    chess.cpp
 * \project Chess
 *
 * \author  Trevor Phillips 
 * \date    2008/12/16
 *
 * Copyright 2008 ET Solutions. This software is open source, and falls under
 * the GPL. Any modification, expansion or linking to this code remains under
 * the GPL.
 *
 ******************************************************************************
 */


#include "ChessEngine.hpp"
#include "TerminalOutputSystem.hpp"
#include "StringBasedInputSystem.hpp"
#include "TerminalWrapper.hpp"

int main(int /*argc*/, char** /*argv*/)
{
    TerminalWrapper wrapper;
    TerminalOutputSystem outputSystem(wrapper);
	StringBasedInputSystem inputSystem(wrapper);

	ChessEngine engine(inputSystem, inputSystem, outputSystem);

	engine.runChessEngine();
	
	return 0;
}



