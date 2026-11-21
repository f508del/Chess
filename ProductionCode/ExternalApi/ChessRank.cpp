//
//  ChessRank.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-11-21.
//

#include "ChessRank.hpp"

using namespace Chess;

std::vector<Rank> Chess::allRanks()
{
    std::vector<Rank> ranks{
        Rank::R1,
        Rank::R2,
        Rank::R3,
        Rank::R4,
        Rank::R5,
        Rank::R6,
        Rank::R7,
        Rank::R8};
    return ranks;
};

std::vector<Rank> Chess::allRanksExcept(const Rank rank)
{
    std::vector<Rank> ranks = allRanks();
    
    for (auto rankIterator = ranks.begin(); rankIterator != ranks.end(); ++rankIterator)
    {
        if (rank == *rankIterator)
        {
            ranks.erase(rankIterator);
            return ranks;
        }
    }
    
    return ranks;
};
