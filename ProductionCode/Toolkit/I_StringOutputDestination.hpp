//
//  I_StringOutputDestination.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-05-16.
//

#include <string>

class I_StringOutputDestination
{
public:
    virtual void writeOutputString(const std::string& text) = 0;
};
