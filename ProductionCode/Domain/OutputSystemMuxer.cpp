//
//  OutputSystemMuxer.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-05-08.
//

#include "OutputSystemMuxer.hpp"

OutputSystemMuxer::OutputSystemMuxer(const std::list<I_OutputSystem*>& muxedSystems)
: muxedOutputSystems_(muxedSystems)
{
    
}

void OutputSystemMuxer::initializeChessUserInterface()
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->initializeChessUserInterface();
        }
    }
    return;
}

void OutputSystemMuxer::endUserInteraction()
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->endUserInteraction();
        }
    }
    return;
}

void OutputSystemMuxer::resetUxForNewGame()
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->resetUxForNewGame();
        }
    }
    return;
}

void OutputSystemMuxer::displayValidMoveToUser(const std::list<Chess::MoveElement>& moveElements)
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->displayValidMoveToUser(moveElements);
        }
    }
    return;
}

void OutputSystemMuxer::rejectMoveAttempt(Chess::MoveValidity validity)
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->rejectMoveAttempt(validity);
        }
    }
    return;
}

void OutputSystemMuxer::declareCheck()
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->declareCheck();
        }
    }
    return;
}

void OutputSystemMuxer::declareCheckmate()
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->declareCheckmate();
        }
    }
    return;
}

void OutputSystemMuxer::declareStalemate()
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->declareStalemate();
        }
    }
    return;
}

void OutputSystemMuxer::requestPromotionDecision()
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->requestPromotionDecision();
        }
    }
    return;
}

void OutputSystemMuxer::notifyUserOfPromotionTo(Chess::PieceType type)
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->notifyUserOfPromotionTo(type);
        }
    }
    return;
}

void OutputSystemMuxer::gameEndedDueToTenConsecutiveInvalidMoveAttempts()
{
    for(auto& pointer : muxedOutputSystems_)
    {
        if (pointer)
        {
            pointer->gameEndedDueToTenConsecutiveInvalidMoveAttempts();
        }
    }
    return;
}
