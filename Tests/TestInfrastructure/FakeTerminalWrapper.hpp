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
    void writeToTerminal(const std::string& text) override;
    
    // helpers
    bool lastOutputMatches(const std::string& outputString) const;
    bool outputContains(const std::string& outputEntry) const;
private:
    std::list<std::string> capturedOutput_;
    std::string lastOutput_;
};
