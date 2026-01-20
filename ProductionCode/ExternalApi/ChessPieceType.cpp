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
    
    // Notably absent here is both pawn and king, as the only reason to parse
    // from string to piece is for promotions, and this provides intrinsic input sanitizing...
    if (lowerInput == "knight")
    {
        return Chess::PieceType::KNIGHT;
    }
    else if (lowerInput == "bishop")
    {
        return Chess::PieceType::BISHOP;
    }
    else if (lowerInput == "rook")
    {
        return Chess::PieceType::ROOK;
    }
    else if (lowerInput == "queen")
    {
        return Chess::PieceType::QUEEN;
    }
    
    return Chess::PieceType::NONE;
}
