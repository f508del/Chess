//
//  ChessRank.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-11-21.
//

#include "ChessRank.hpp"

using namespace Chess;
using namespace std;

vector<Rank> Chess::allRanks()
{
    vector<Rank> ranks{
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

vector<Rank> Chess::allRanksExcept(const Rank rank)
{
    vector<Rank> ranks = allRanks();
    
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

vector<Rank> Chess::allRanksIncreasingGreaterThan(const Rank rank)
{
    vector<Rank> ranks = allRanks();
    vector<Rank> resultRanks;
    bool reachedStartPoint = false;
    
    for (auto rankIterator = ranks.begin(); rankIterator != ranks.end(); ++rankIterator)
    {
        if (reachedStartPoint)
        {
            resultRanks.push_back(*rankIterator);
        }
        if (rank == *rankIterator)
        {
            reachedStartPoint = true;
        }
    }
    
    return resultRanks;
}

vector<Rank> Chess::allRanksDecreasingLessThan(const Rank rank)
{
    vector<Rank> ranks = allRanks();
    vector<Rank> resultRanks;
    bool reachedStartPoint = false;
    
    for (auto rankIterator = ranks.rbegin(); rankIterator != ranks.rend(); ++rankIterator)
    {
        if (reachedStartPoint)
        {
            resultRanks.push_back(*rankIterator);
        }
        if (rank == *rankIterator)
        {
            reachedStartPoint = true;
        }
    }
    
    return resultRanks;
}
