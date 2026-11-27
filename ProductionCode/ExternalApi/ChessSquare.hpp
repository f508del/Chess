//
//  ChessSquare.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-02.
//
//

#pragma once
#include <type_traits>
#include <cctype>
#include "ChessFile.hpp"
#include "ChessRank.hpp"

namespace Chess
{
enum class SquareLookupError {SQUARE_NOT_FOUND};
}

// Note: file() will return a lower case form of whatever file char was given.
class ChessSquare
{
public:
    ChessSquare();
    template<typename T,
             typename = typename std::enable_if<
                std::is_same<char, T>::value>::type>
    ChessSquare(T file, unsigned int rank)
    : deprecatedFile_(std::tolower(file))
    , deprecatedRank_(rank)
    , file_(toFile(std::tolower(file)))
    , rank_(toRank(rank))
    {
        
    }
    
    ChessSquare(Chess::File file, unsigned int rank);
    ChessSquare(Chess::File file, Chess::Rank rank);

    bool isSquareOnTheBoard() const noexcept;
    
    Chess::File file() const noexcept;
    Chess::Rank rank() const noexcept;

    char dep_File() const noexcept;
    unsigned int dep_Rank() const noexcept;

    bool operator< (const ChessSquare& otherSquare) const noexcept;
    bool operator==(const ChessSquare& otherSquare) const noexcept;
    bool operator!=(const ChessSquare& otherSquare) const noexcept;

private:
    bool isValidFile() const noexcept;
    bool isValidRank() const noexcept;
    
    Chess::File toFile(char file) const;
    Chess::Rank toRank(unsigned int rank) const;

private:
    char deprecatedFile_;
    unsigned int deprecatedRank_;
    
    Chess::File file_;
    Chess::Rank rank_;
};

