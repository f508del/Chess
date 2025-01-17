//
//  TerminalOutputSystem.h
//  Chess
//
//  Created by Trevor Phillips on 2020-12-25.
//
//

#pragma once

#include "I_OutputSystem.hpp"

class TerminalOutputSystem : public I_OutputSystem
{
public:
   explicit TerminalOutputSystem();
   virtual ~TerminalOutputSystem();

    void showTextToUser(const char* displayString) override;
    void initializeChessUserInterface() override;
    void endUserInteraction() override;
    void resetUxForNewGame() override;
    void displayMoveToUser(const ChessMove& move, const I_ReadOnlyChessBoard& board) override;
};
