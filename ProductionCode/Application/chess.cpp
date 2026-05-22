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
#include "StringBasedOutputSystem.hpp"
#include "StringBasedInputSystem.hpp"
#include "TerminalWrapper.hpp"
#include "RandomAi.hpp"
#include "OutputSystemMuxer.hpp"

int main(int /*argc*/, char** /*argv*/)
{
    RandomAi aiPlayer(Chess::PieceAffiliation::WHITE_PIECE);
    TerminalWrapper wrapper;
    StringBasedOutputSystem outputSystem(wrapper);
	StringBasedInputSystem inputSystem(wrapper);

    OutputSystemMuxer outputMuxer({&aiPlayer, &outputSystem});
    
	ChessEngine engine(aiPlayer, inputSystem, outputMuxer);

	engine.runChessEngine();
	
	return 0;
}



