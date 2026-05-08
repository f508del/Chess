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
#include "RandomAi.hpp"
#include "OutputSystemMuxer.hpp"

int main(int /*argc*/, char** /*argv*/)
{
    RandomAi aiPlayer;
    TerminalWrapper wrapper;
    TerminalOutputSystem outputSystem(wrapper);
	StringBasedInputSystem inputSystem(wrapper);

    std::list<I_OutputSystem*> outputList;
    outputList.push_back(&aiPlayer);
    outputList.push_back(&outputSystem);
    OutputSystemMuxer outputMuxer(outputList);
    
	ChessEngine engine(inputSystem, aiPlayer, outputMuxer);

	engine.runChessEngine();
	
	return 0;
}



