//
//  ChessMove.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#pragma once

#include <string>
#include "ChessSquare.hpp"
#include <optional>

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
    
    bool isValidFile(char file) const noexcept;
    bool isValidRank(unsigned int rank) const noexcept;
    Chess::File toFile(char file) const;
    Chess::Rank toRank(unsigned int rank) const;
    std::optional<ChessSquare> convertFileAndRankIntoSquare(char file, unsigned int rank) const;

private:
    std::optional<ChessSquare> startingSquare_;
    std::optional<ChessSquare> endingSquare_;
};
