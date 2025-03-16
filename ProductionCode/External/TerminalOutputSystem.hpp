//
//  TerminalOutputSystem.h
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#pragma once

class ChessMoveDescriber;
class TerminalWrapper;

#include "I_OutputSystem.hpp"
#include "ScopedPointer.hpp"

class TerminalOutputSystem : public I_OutputSystem
{
public:
   explicit TerminalOutputSystem(TerminalWrapper& wrapper);
   virtual ~TerminalOutputSystem();

    void initializeChessUserInterface() override;
    void endUserInteraction() override;
    void resetUxForNewGame() override;
    void displayValidMoveToUser(const ChessMove& move, const I_ReadOnlyChessBoard& board) override;
    void rejectMoveAttempt(Chess::MoveValidity validity) override;
    void declareCheck() override;
    
private: // helper functions
    void showTextToUser(const char* displayString);
    
private:
    ScopedPointer<ChessMoveDescriber> moveDescriber_;
    TerminalWrapper& terminalWrapper_;
};
