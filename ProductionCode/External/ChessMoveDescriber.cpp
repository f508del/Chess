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
    output.append(chessPieceTypeName(instigatingPieceType));
    output.append(" ");
    
    ChessSquare startingSquare = moveElements.front().square_;
    ChessSquare endingSquare = destinationSquareOfInstigatingPiece(moveElements);
    
    std::string moveString;
    char resultString[5];
    snprintf(resultString, 5, "%c%u%c%u", startingSquare.file(),
             startingSquare.rank(), endingSquare.file(), endingSquare.rank());
    resultString[4] = '\0';
    moveString = resultString;
    
    output.append(moveString);
    
    return output;
}

std::string ChessMoveDescriber::chessPieceTypeName(PieceType type) const
{
    switch (type)
    {
        case PieceType::PAWN:
        {
            return "Pawn";
        }
        case PieceType::BISHOP:
        {
            return "Bishop";
        }
        case PieceType::KNIGHT:
        {
            return "Knight";
        }
        case PieceType::ROOK:
        {
            return "Rook";
        }
        case PieceType::QUEEN:
        {
            return "Queen";
        }
        case PieceType::KING:
        {
            return "King";
        }
        default:
        {
            break;
        }
    }
    return "Invalid Piece Type";
}

