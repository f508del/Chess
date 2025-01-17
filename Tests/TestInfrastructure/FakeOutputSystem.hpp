//
//  FakeOutputSystem.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-27.
//
//

#pragma once

#include "I_OutputSystem.hpp"
#include <list>
#include <string>

class FakeOutputSystem: public I_OutputSystem
{
public:
    FakeOutputSystem();
    virtual ~FakeOutputSystem();

    // inherited
    void showTextToUser(const char* displayString) override;
    void initializeChessUserInterface() override;
    void endUserInteraction() override;
    void resetUxForNewGame() override;
    void displayMoveToUser(const ChessMove& move, const I_ReadOnlyChessBoard& board) override;
    
    // helpers
    size_t size() const;
    std::string mostRecentOutput() const;
    std::string secondLastOutput() const;
    bool contains(const std::string& outputEntry) const;
    

private:
    std::string mostRecentOutput_;
    std::list<std::string> capturedOutput_;
};
