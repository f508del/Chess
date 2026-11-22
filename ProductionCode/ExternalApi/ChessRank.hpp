//
//  ChessRank.hpp
//  Chess
//
//  Created by Trevor Phillips on 2026-11-21.
//

#pragma once

#include <vector>

namespace Chess
{
enum class Rank : uint8_t
{
    R1,
    R2,
    R3,
    R4,
    R5,
    R6,
    R7,
    R8
};

std::vector<Rank> allRanks();
std::vector<Rank> allRanksExcept(const Rank rank);
std::vector<Rank> allRanksIncreasingGreaterThan(const Rank rank);
std::vector<Rank> allRanksDecreasingLessThan(const Rank rank);
}
