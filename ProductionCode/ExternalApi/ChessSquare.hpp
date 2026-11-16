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

// Note: file() will return a lower case form of whatever file char was given.
class ChessSquare
{
public:
    ChessSquare();
    template<typename T,
             typename = typename std::enable_if<
                std::is_same<char, T>::value>::type>
    ChessSquare(T file, unsigned int rank)
    : file_(std::tolower(file))
    , rank_(rank)
    {
        
    }
    
    ChessSquare(Chess::File file, unsigned int rank);

    bool isSquareOnTheBoard() const noexcept;

    char file() const noexcept;
    unsigned int rank() const noexcept;

    bool operator< (const ChessSquare& otherSquare) const noexcept;
    bool operator==(const ChessSquare& otherSquare) const noexcept;
    bool operator!=(const ChessSquare& otherSquare) const noexcept;

private:
    bool isValidFile() const noexcept;
    bool isValidRank() const noexcept;

private:
    char file_;
    unsigned int rank_;
};
