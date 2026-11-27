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
    {
        
    }
    
    ChessSquare(Chess::File file, unsigned int rank);
    ChessSquare(Chess::File file, Chess::Rank rank);

    bool isSquareOnTheBoard() const noexcept;

    char dep_File() const noexcept;
    unsigned int dep_Rank() const noexcept;

    bool operator< (const ChessSquare& otherSquare) const noexcept;
    bool operator==(const ChessSquare& otherSquare) const noexcept;
    bool operator!=(const ChessSquare& otherSquare) const noexcept;

private:
    bool isValidFile() const noexcept;
    bool isValidRank() const noexcept;

private:
    char deprecatedFile_;
    unsigned int deprecatedRank_;
};

