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


#include <ChessEngine.hpp>
#include <TerminalOutputSystem.hpp>
#include <TerminalInputSystem.hpp>

int main(int /*argc*/, char** /*argv*/)
{
	TerminalOutputSystem outputSystem;
	TerminalInputSystem inputSystem;

	ChessEngine engine(inputSystem, outputSystem);

	engine.runChessEngine();
	
	return 0;
}



