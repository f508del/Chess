//
//  StringBasedInputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#pragma once

#include "I_InputSystem.hpp"

class I_StringInputSource;

class StringBasedInputSystem : public I_InputSystem
{
public:
    explicit StringBasedInputSystem(I_StringInputSource& wrapper);
    virtual ~StringBasedInputSystem();

    void getNextInput() override;
    
    void registerNewGameCallback(std::function<void()> callback) override;
    void registerQuitCallback(std::function<void()> callback) override;
    void registerMoveAttemptCallback(std::function<void(const ChessMoveRequest&)> callback) override;
    void registerPromotionSelectionCallback(std::function<void(Chess::PieceType)> callback) override;
    
private:
    std::function<void()> newGameCallback_;
    std::function<void()> quitCallback_;
    std::function<void(const ChessMoveRequest&)> moveAttemptCallback_;
    std::function<void(Chess::PieceType)> promotionCallback_;
    I_StringInputSource& stringSource_;
};
