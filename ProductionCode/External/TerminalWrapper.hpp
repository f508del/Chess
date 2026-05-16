//
//  TerminalWrapper.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include <string>
#include "I_StringInputSource.hpp"
#include "I_StringOutputDestination.hpp"

class TerminalWrapper : public I_StringInputSource, public I_StringOutputDestination
{
public:
    TerminalWrapper() = default;
    virtual ~TerminalWrapper() = default;
    
    void writeOutputString(const std::string& text) override;
    std::string readNextInputString() override;
};

