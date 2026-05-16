//
//  FakeTerminalWrapper.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-19.
//

#include "TerminalWrapper.hpp"
#include <list>

class FakeTerminalWrapper : public TerminalWrapper
{
public:
    FakeTerminalWrapper();
    
    // inherited
    void writeOutputString(const std::string& text) override;
    std::string readNextInputString() override;
    
    // helpers
    bool lastOutputMatches(const std::string& outputString) const;
    bool outputContains(const std::string& outputEntry) const;
    void enqueueInput(const std::list<std::string>& inputList);
private:
    std::list<std::string> capturedOutput_;
    std::string lastOutput_;
    
    std::list<std::string> queuedInput_;
};
