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

ChessSquare::ChessSquare()
: file_('\0')
, rank_(0)
{
}

ChessSquare::ChessSquare(Chess::File file, unsigned int rank)
: rank_(rank)
{
    switch(file)
    {
        case Chess::File::A:
            file_ = 'a';
            break;
        case Chess::File::B:
            file_ = 'b';
            break;
        case Chess::File::C:
            file_ = 'c';
            break;
        case Chess::File::D:
            file_ = 'd';
            break;
        case Chess::File::E:
            file_ = 'e';
            break;
        case Chess::File::F:
            file_ = 'f';
            break;
        case Chess::File::G:
            file_ = 'g';
            break;
        case Chess::File::H:
            file_ = 'h';
            break;
    }
}

bool ChessSquare::isSquareOnTheBoard() const noexcept
{
   return isValidFile() && isValidRank();
}

char ChessSquare::file() const noexcept
{
   return file_;
}

unsigned int ChessSquare::rank() const noexcept
{
   return rank_;
}

bool ChessSquare::operator<(const ChessSquare& otherSquare) const noexcept
{
    return std::tie(file_, rank_) < std::tie(otherSquare.file_, otherSquare.rank_);
}

bool ChessSquare::operator==(const ChessSquare& otherSquare) const noexcept
{
    return ((file_ == otherSquare.file_) && (rank_ == otherSquare.rank_));
}

bool ChessSquare::operator!=(const ChessSquare& otherSquare) const noexcept
{
    return ((file_ != otherSquare.file_) || (rank_ != otherSquare.rank_));
}

bool ChessSquare::isValidFile() const noexcept
{
   return (file_ >= 'a' && file_ <= 'h');
}

bool ChessSquare::isValidRank() const noexcept
{
   return (rank_ >= 1 && rank_ <= 8);
}
