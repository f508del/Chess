//
//  ChessMoveDescriber.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-24.
//
//

#include "ChessMoveDescriber.hpp"
#include "ChessMoveRequest.hpp"
#include "I_ReadOnlyChessBoard.hpp"
#include "I_ChessPiece.hpp"

using namespace Chess;

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
