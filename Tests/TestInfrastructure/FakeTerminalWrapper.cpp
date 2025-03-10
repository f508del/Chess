//
//  FakeTerminalWrapper.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include "FakeTerminalWrapper.hpp"

using namespace std;

FakeTerminalWrapper::FakeTerminalWrapper()
{
}

void FakeTerminalWrapper::writeToTerminal(const string& text)
{
    lastOutput_ = text;
    capturedOutput_.push_back(text);
}

string FakeTerminalWrapper::readFromTerminal()
{
    string output;
    if (!queuedInput_.empty())
    {
        output = queuedInput_.front();
        queuedInput_.pop_front();
    }
    return output;
}

bool FakeTerminalWrapper::lastOutputMatches(const string& outputString) const
{
    bool stringIsMatching = (outputString == lastOutput_);
    if (!stringIsMatching)
    {
        fprintf(stdout, "Terminal output comparison failed! Expected: %s  Actual: %s\n",
                outputString.c_str(), lastOutput_.c_str());
    }
    return outputString == lastOutput_;
}

bool FakeTerminalWrapper::outputContains(const string& outputEntry) const
{
   for (list<string>::const_iterator it = capturedOutput_.begin(); it != capturedOutput_.end(); it++)
      {
         if (*it == outputEntry)
         {
            return true;
         }
      }

   return false;
}

void FakeTerminalWrapper::enqueueInput(const list<string>& inputList)
{
    queuedInput_ = inputList;
}
