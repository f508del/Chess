//
//  ChessMoveDescriber.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-24.
//
//

#include "ChessMoveDescriber.hpp"
#include "ChessMove.hpp"
#include "I_ReadOnlyChessBoard.hpp"
#include "I_ChessPiece.hpp"

using namespace Chess;

ChessMoveDescriber::ChessMoveDescriber()
{
}

ChessMoveDescriber::~ChessMoveDescriber()
{
}

std::string ChessMoveDescriber::describeMove(const ChessMove& move, const I_ReadOnlyChessBoard& board) const
{
   std::string description("Moving ");
   if (board.anyPieceExistsAt(move.startingSquare()))
   {
       const I_ChessPiece* currentPiece = board.pieceAt(move.startingSquare());
       PieceType pieceType = currentPiece->pieceType();
       std::string typeName = chessPieceTypeName(pieceType);
       description.append(typeName);
   }

   return description.append(" ").append(move.toString());
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
