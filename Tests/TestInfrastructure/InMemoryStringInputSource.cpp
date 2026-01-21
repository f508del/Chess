//
//  InMemoryStringInputSource.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-20.
//

#include "InMemoryStringInputSource.hpp"

using namespace std;

InMemoryStringInputSource::InMemoryStringInputSource()
: inputBuffer_()
{
    
}

InMemoryStringInputSource::~InMemoryStringInputSource()
{
    
}

std::string InMemoryStringInputSource::readNextInputString()
{
    if (!inputBuffer_.empty())
    {
        string nextInput = inputBuffer_.front();
        inputBuffer_.pop_front();
        return nextInput;
    }
    return string();
}


void InMemoryStringInputSource::setInputSequence(const std::list<std::string>& inputSequence)
{
    inputBuffer_ = inputSequence;
}

