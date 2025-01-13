//
//  ChessSquare.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-02.
//
//

#pragma once

// Note: file() will return a lower case form of whatever file char was given.
class ChessSquare
{
public:
   ChessSquare();
   ChessSquare(char file, unsigned int rank);

   bool isSquareOnTheBoard() const;

   char file() const;
   unsigned int rank() const;

   bool operator< (const ChessSquare& otherSquare) const;

private:
   bool isValidFile() const;
   bool isValidRank() const;

private:
   char file_;
   unsigned int rank_;
};
