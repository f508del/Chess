//
//  ChessPieceType.cpp
//  Chess
//
//  Created by Trevor Phillips on 2026-01-20.
//

#include "ChessPieceType.hpp"

using namespace std;

Chess::PieceType Chess::pieceTypeFromString(const std::string& input)
{
    string lowerInput = input;
    transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(),
                   [](unsigned char c){return tolower(c);});
    
    if (lowerInput == "knight")
    {
        return Chess::PieceType::KNIGHT;
    }
    
    return Chess::PieceType::NONE;
}
