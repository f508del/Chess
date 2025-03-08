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
    std::string readFromTerminal() override;
    
    // helpers
    bool lastOutputMatches(const std::string& outputString) const;
    bool outputContains(const std::string& outputEntry) const;
    void enqueueInput(std::list<std::string>& inputList);
private:
    std::list<std::string> capturedOutput_;
    std::string lastOutput_;
    
    std::list<std::string> queuedInput_;
};
