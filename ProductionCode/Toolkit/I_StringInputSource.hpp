//
//  I_StringSource.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-20.
//

#include <string>

class I_StringInputSource
{
public:
    virtual std::string readNextInputString() = 0;
};
