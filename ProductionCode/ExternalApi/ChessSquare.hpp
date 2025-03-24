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

    bool isSquareOnTheBoard() const;

    char file() const;
    unsigned int rank() const;

    bool operator< (const ChessSquare& otherSquare) const;
    bool operator==(const ChessSquare& otherSquare) const;

private:
    bool isValidFile() const;
    bool isValidRank() const;

private:
    char file_;
    unsigned int rank_;
};
