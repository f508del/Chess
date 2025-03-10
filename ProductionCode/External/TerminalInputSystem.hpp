//
//  TerminalInputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#pragma once

#include "I_InputSystem.hpp"

class TerminalWrapper;

class TerminalInputSystem : public I_InputSystem
{
public:
    explicit TerminalInputSystem(TerminalWrapper& wrapper);
    virtual ~TerminalInputSystem();

    std::string getNextInput() override;
    
    void registerNewGameCallback(std::function<void()> callback) override;
    void registerQuitCallback(std::function<void()> callback) override;
    
private:
    std::function<void()> newGameCallback_;
    std::function<void()> quitCallback_;
    TerminalWrapper& terminalWrapper_;
};
