//
//  ChessMoveDescriber.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-24.
//
//

#include "ChessMoveDescriber.hpp"
#include "ChessMoveElement.hpp"
#include "I_ChessPiece.hpp"
#include "StringifyUtilities.hpp"

using namespace Chess;
using namespace std;

ChessMoveDescriber::ChessMoveDescriber()
{
}

ChessMoveDescriber::~ChessMoveDescriber()
{
}

string ChessMoveDescriber::describeValidMove(const list<Chess::MoveElement>& moveElements)
{
    string output;
    if (moveElements.empty())
    {
        return output;
    }
    
    output.append("Moving ");
    PieceType instigatingPieceType = moveElements.front().type_;
    output.append(Chess::toString(instigatingPieceType));
    output.append(" ");
    
    ChessSquare startingSquare = moveElements.front().square_;
    ChessSquare endingSquare = destinationSquareOfInstigatingPiece(moveElements);
    
    output.append(toString(startingSquare));
    output.append(toString(endingSquare));
    
    if (moveElements.size() == 3 && !(moveElements.back().square_ == endingSquare))
    {
        output.append(", which removes Pawn at ");
        output.append(toString(moveElements.back().square_));
        output.append(" by en passant");
    }
    
    return output;
}

std::string ChessMoveDescriber::toString(const ChessSquare& square) const
{
    std::string stringSquare;
    char resultString[3];
    snprintf(resultString, 3, "%c%u", square.file(), square.rank());
    resultString[2] = '\0';
    stringSquare = resultString;
    return stringSquare;
}
