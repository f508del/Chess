//
//  ChessMoveDescriber.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-24.
//
//

#include "ChessMoveDescriber.hpp"
#include "ChessMoveElement.hpp"
#include "ChessMoveRequest.hpp"
#include "I_ReadOnlyChessBoard.hpp"
#include "I_ChessPiece.hpp"

using namespace Chess;
using namespace std;

ChessMoveDescriber::ChessMoveDescriber()
{
}

ChessMoveDescriber::~ChessMoveDescriber()
{
}

std::string ChessMoveDescriber::describeValidMove(const ChessMoveRequest& move, const I_ReadOnlyChessBoard& board) const
{
    std::string description("Moving ");
    if (board.anyPieceExistsAt(move.startingSquare()))
    {
       const I_ChessPiece* currentPiece = board.pieceAt(move.startingSquare());
       PieceType pieceType = currentPiece->pieceType();
       std::string typeName = chessPieceTypeName(pieceType);
       description.append(typeName);
    }

    std::string moveString;
    char resultString[5];
    snprintf(resultString, 5, "%c%u%c%u", move.startingSquare().file(),
            move.startingSquare().rank(), move.endingSquare().file(), move.endingSquare().rank());
    resultString[4] = '\0';
    moveString = resultString;
    
    return description.append(" ").append(moveString);
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

ChessSquare ChessMoveDescriber::destinationSquareOfInstigatingPiece(const std::list<Chess::MoveElement>& moveElements)
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
