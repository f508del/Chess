//
//  ChessSquare.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-02.
//
//

#include "ChessSquare.hpp"
#include <cctype>
#include <tuple>

using namespace Chess;

ChessSquare::ChessSquare()
: deprecatedFile_('\0')
, deprecatedRank_(0)
{
}

ChessSquare::ChessSquare(Chess::File file, unsigned int rank)
: deprecatedRank_(rank)
{
    switch(file)
    {
        case Chess::File::A:
            deprecatedFile_ = 'a';
            break;
        case Chess::File::B:
            deprecatedFile_ = 'b';
            break;
        case Chess::File::C:
            deprecatedFile_ = 'c';
            break;
        case Chess::File::D:
            deprecatedFile_ = 'd';
            break;
        case Chess::File::E:
            deprecatedFile_ = 'e';
            break;
        case Chess::File::F:
            deprecatedFile_ = 'f';
            break;
        case Chess::File::G:
            deprecatedFile_ = 'g';
            break;
        case Chess::File::H:
            deprecatedFile_ = 'h';
            break;
    }
}

ChessSquare::ChessSquare(File file, Rank rank)
{
    switch(file)
    {
        case File::A:
            deprecatedFile_ = 'a';
            break;
        case File::B:
            deprecatedFile_ = 'b';
            break;
        case File::C:
            deprecatedFile_ = 'c';
            break;
        case File::D:
            deprecatedFile_ = 'd';
            break;
        case File::E:
            deprecatedFile_ = 'e';
            break;
        case File::F:
            deprecatedFile_ = 'f';
            break;
        case File::G:
            deprecatedFile_ = 'g';
            break;
        case File::H:
            deprecatedFile_ = 'h';
            break;
    }

    switch(rank)
    {
        case Rank::R1:
            deprecatedRank_ = 1;
            break;
        case Rank::R2:
            deprecatedRank_ = 2;
            break;
        case Rank::R3:
            deprecatedRank_ = 3;
            break;
        case Rank::R4:
            deprecatedRank_ = 4;
            break;
        case Rank::R5:
            deprecatedRank_ = 5;
            break;
        case Rank::R6:
            deprecatedRank_ = 6;
            break;
        case Rank::R7:
            deprecatedRank_ = 7;
            break;
        case Rank::R8:
            deprecatedRank_ = 8;
            break;
    }
    
}

bool ChessSquare::isSquareOnTheBoard() const noexcept
{
   return isValidFile() && isValidRank();
}

char ChessSquare::file() const noexcept
{
   return deprecatedFile_;
}

unsigned int ChessSquare::rank() const noexcept
{
   return deprecatedRank_;
}

bool ChessSquare::operator<(const ChessSquare& otherSquare) const noexcept
{
    return std::tie(deprecatedFile_, deprecatedRank_) < std::tie(otherSquare.deprecatedFile_, otherSquare.deprecatedRank_);
}

bool ChessSquare::operator==(const ChessSquare& otherSquare) const noexcept
{
    return ((deprecatedFile_ == otherSquare.deprecatedFile_) && (deprecatedRank_ == otherSquare.deprecatedRank_));
}

bool ChessSquare::operator!=(const ChessSquare& otherSquare) const noexcept
{
    return ((deprecatedFile_ != otherSquare.deprecatedFile_) || (deprecatedRank_ != otherSquare.deprecatedRank_));
}

bool ChessSquare::isValidFile() const noexcept
{
   return (deprecatedFile_ >= 'a' && deprecatedFile_ <= 'h');
}

bool ChessSquare::isValidRank() const noexcept
{
   return (deprecatedRank_ >= 1 && deprecatedRank_ <= 8);
}
