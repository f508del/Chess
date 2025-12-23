//
//  ChessMove.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

#include <string>
#include "ScopedPointer.hpp"
#include "ChessSquare.hpp"

class ChessMoveRequest
{
public:
    ChessMoveRequest();
    ChessMoveRequest(const std::string& moveString);
    ChessMoveRequest(const ChessSquare& startingSquare, const ChessSquare& endingSquare);
    bool isOnTheBoard() const;
    bool populateFromString(const std::string& moveString);

    const ChessSquare& startingSquare() const;
    const ChessSquare& endingSquare() const;
    
    bool operator==(const ChessMoveRequest& move) const;

private:
    void resetState();

private:
    ChessSquare startingSquare_;
    ChessSquare endingSquare_;
};
