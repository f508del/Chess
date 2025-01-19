//
//  FakeTerminalWrapper.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include "TerminalWrapper.hpp"

class FakeTerminalWrapper : public TerminalWrapper
{
public:
    FakeTerminalWrapper();
    
    void writeToTerminal(const std::string& text) override;
    
    bool lastOutputMatches(const std::string& outputString);
    
private:
    std::string lastOutput_;
};
