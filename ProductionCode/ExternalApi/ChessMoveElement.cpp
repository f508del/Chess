//
//  ChessMoveElement.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-11-10.
//

#include "ChessMoveElement.hpp"

using namespace Chess;

MoveElement::MoveElement()
: action_(MoveElementAction::NO_ACTION)
, square_()
, affiliation_(PieceAffiliation::WHITE_PIECE)
, type_(PieceType::NONE)
{
    
}

MoveElement::MoveElement(const MoveElementAction& action, const ChessSquare& square, const PieceAffiliation& affiliation, const PieceType& type)
: action_(action)
, square_(square)
, affiliation_(affiliation)
, type_(type)
{
    
}

ChessSquare Chess::destinationSquareOfInstigatingPiece(const std::list<Chess::MoveElement>& moveElements)
{
    ChessSquare destinationSquare;
    
    Chess::PieceType instigatingType = moveElements.front().type_;
    Chess::PieceAffiliation instigatingAffiliation = moveElements.front().affiliation_;
    
    for (auto it = moveElements.begin(); it != moveElements.end(); it++)
    {
        if (it == moveElements.begin())
        {
            // don't match the first element to itself
            continue;
        }
        
        if (it->type_ == instigatingType && it->affiliation_ == instigatingAffiliation)
        {
            return it->square_;
        }
    }
    
    return destinationSquare;
}
