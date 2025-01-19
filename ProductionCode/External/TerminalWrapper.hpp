//
//  TerminalWrapper.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include <string>

class TerminalWrapper
{
public:
    TerminalWrapper() = default;
    
    virtual void writeToTerminal(const std::string& text);
};

