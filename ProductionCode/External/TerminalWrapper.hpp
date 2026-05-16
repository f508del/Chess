//
//  TerminalWrapper.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include <string>
#include "I_StringInputSource.hpp"

class TerminalWrapper : public I_StringInputSource
{
public:
    TerminalWrapper() = default;
    virtual ~TerminalWrapper() = default;
    
    virtual void writeOutputString(const std::string& text);
    virtual std::string readNextInputString() override;
};

