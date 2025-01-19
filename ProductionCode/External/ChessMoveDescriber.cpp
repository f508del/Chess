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
       Chess::PieceType pieceType = currentPiece->pieceType();
       std::string typeName = chessPieceTypeName(pieceType);
       description.append(typeName);
   }

   return description.append(" ").append(move.toString());
}

std::string ChessMoveDescriber::chessPieceTypeName(Chess::PieceType type) const
{
    switch (type)
    {
        case Chess::PieceType::PAWN:
        {
            return "Pawn";
        }
        case Chess::PieceType::BISHOP:
        {
            return "Bishop";
        }
        case Chess::PieceType::KNIGHT:
        {
            return "Knight";
        }
        case Chess::PieceType::ROOK:
        {
            return "Rook";
        }
        case Chess::PieceType::QUEEN:
        {
            return "Queen";
        }
        case Chess::PieceType::KING:
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
