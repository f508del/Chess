//
//  FakeTerminalWrapper.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include "FakeTerminalWrapper.hpp"

FakeTerminalWrapper::FakeTerminalWrapper()
{
}

void FakeTerminalWrapper::writeToTerminal(const std::string& text)
{
    lastOutput_ = text;
}

bool FakeTerminalWrapper::lastOutputMatches(const std::string& outputString)
{
    bool stringIsMatching = (outputString == lastOutput_);
    if (!stringIsMatching)
    {
        fprintf(stdout, "Terminal output comparison failed! Expected: %s  Actual: %s\n",
                outputString.c_str(), lastOutput_.c_str());
    }
    return outputString == lastOutput_;
}
