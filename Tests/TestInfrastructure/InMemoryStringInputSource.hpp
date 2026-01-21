//
//  InMemoryString.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-20.
//

#include "I_StringInputSource.hpp"
#include <list>

class InMemoryStringInputSource : public I_StringInputSource
{
public:
    InMemoryStringInputSource();
    virtual ~InMemoryStringInputSource();
    
    // From parent
    std::string readNextInputString() override;
    
    // helpers
    void setInputSequence(const std::list<std::string>& inputSequence);
    
private:
    std::list<std::string> inputBuffer_;
};

