//
//  ChessSquare.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-02.
//
//

#include "ChessSquare.hpp"
#include <cctype>

ChessSquare::ChessSquare()
: file_('\0')
, rank_(0)
{
}

ChessSquare::ChessSquare(char file, unsigned int rank)
: file_(std::tolower(file))
, rank_(rank)
{
}

bool ChessSquare::isSquareOnTheBoard() const
{
   return isValidFile() && isValidRank();
}

char ChessSquare::file() const
{
   return file_;
}

unsigned int ChessSquare::rank() const
{
   return rank_;
}

bool ChessSquare::isValidFile() const
{
   return (file_ >= 'a' && file_ <= 'h');
}

bool ChessSquare::isValidRank() const
{
   return (rank_ >= 1 && rank_ <= 8);
}
