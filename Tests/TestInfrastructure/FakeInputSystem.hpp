//
//  FakeInputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "I_InputSystem.hpp"
#include <list>

class FakeInputSystem : public I_InputSystem
{
public:
    explicit FakeInputSystem();
    virtual ~FakeInputSystem();

    // from I_InputSystem:
    void getNextInput() override;
    void registerNewGameCallback(std::function<void()> callback) override;
    void registerQuitCallback(std::function<void()> callback) override;
    void registerMoveAttemptCallback(std::function<void(const ChessMove&)> callback) override;
    
    // Helpers
    void setInputSequence(const std::list<std::string>& inputSequence);
    void clearInputSequence();

private:
    std::list<std::string> inputBuffer_;
    
    std::function<void()> newGameCallback_;
    std::function<void()> quitCallback_;
    std::function<void(const ChessMove&)> moveAttemptCallback_;
};
