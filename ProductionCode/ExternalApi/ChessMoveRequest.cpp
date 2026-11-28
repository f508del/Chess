//
//  ChessMove.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "ChessMoveRequest.hpp"

using namespace std;
using namespace Chess;

ChessMoveRequest::ChessMoveRequest()
: startingSquare_(std::nullopt)
, endingSquare_(std::nullopt)
{
   resetState();
}

ChessMoveRequest::ChessMoveRequest(const std::string& moveString)
{
    if (!populateFromString(moveString))
    {
        resetState();
    }
}

ChessMoveRequest::ChessMoveRequest(const ChessSquare& startingSquare, const ChessSquare& endingSquare)
: startingSquare_(startingSquare)
, endingSquare_(endingSquare)
{
    
}

bool ChessMoveRequest::populateFromString(const string& moveString)
{
   resetState();
   if (moveString.length() != 4)
   {
      return false;
   }
   char startingFile = '\0';
   unsigned int startingRank = 0;
   char endingFile = '\0';
   unsigned int endingRank = 0;
   sscanf(moveString.c_str(), "%c%u%c%u", &startingFile, &startingRank, &endingFile, &endingRank);

   startingSquare_ = convertFileAndRankIntoSquare(startingFile, startingRank);
   endingSquare_ = convertFileAndRankIntoSquare(endingFile, endingRank);

   return isOnTheBoard();
}

const ChessSquare& ChessMoveRequest::startingSquare() const
{
   return *startingSquare_;
}

const ChessSquare& ChessMoveRequest::endingSquare() const
{
   return *endingSquare_;
}

bool ChessMoveRequest::isOnTheBoard() const
{
   return (startingSquare_.has_value() && endingSquare_.has_value());
}

void ChessMoveRequest::resetState()
{
   startingSquare_ = std::nullopt;
   endingSquare_ = std::nullopt;
}

bool ChessMoveRequest::operator==(const ChessMoveRequest& move) const
{
    return ((*startingSquare_ == *(move.startingSquare_)) && (*endingSquare_ == *(move.endingSquare_)));
}

bool ChessMoveRequest::isValidFile(char file) const noexcept
{
    return (file >= 'a' && file <= 'h');
}

bool ChessMoveRequest::isValidRank(unsigned int rank) const noexcept
{ 
    return (rank >= 1 && rank <= 8);
}

Chess::File ChessMoveRequest::toFile(char file) const
{
    switch(file)
    {
        case 'a':
            return File::A;
        case 'b':
            return File::B;
        case 'c':
            return File::C;
        case 'd':
            return File::D;
        case 'e':
            return File::E;
        case 'f':
            return File::F;
        case 'g':
            return File::G;
        case 'h':
            return File::H;
    }
    // invalid, but validity is handled in the convertFileAndRankIntoSquare function
    return File::A;
}

Chess::Rank ChessMoveRequest::toRank(unsigned int rank) const
{
    switch(rank)
    {
        case 1:
            return Rank::R1;
        case 2:
            return Rank::R2;
        case 3:
            return Rank::R3;
        case 4:
            return Rank::R4;
        case 5:
            return Rank::R5;
        case 6:
            return Rank::R6;
        case 7:
            return Rank::R7;
        case 8:
            return Rank::R8;
    }
    // invalid, but validity is handled in the convertFileAndRankIntoSquare function
    return Rank::R1;
}

std::optional<ChessSquare> ChessMoveRequest::convertFileAndRankIntoSquare(char file, unsigned int rank) const
{
    if (!isValidFile(file) || !isValidRank(rank))
    {
        return std::nullopt;
    }
    
    return ChessSquare(toFile(file), toRank(rank));
}

