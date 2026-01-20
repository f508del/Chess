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
    void registerMoveAttemptCallback(std::function<void(const ChessMoveRequest&)> callback) override;
    void registerPromotionSelectionCallback(std::function<void(Chess::PieceType)> callback) override;
    
    // Helpers
    void setInputSequence(const std::list<std::string>& inputSequence);

private:
    std::list<std::string> inputBuffer_;
    
    std::function<void()> newGameCallback_;
    std::function<void()> quitCallback_;
    std::function<void(const ChessMoveRequest&)> moveAttemptCallback_;
};
