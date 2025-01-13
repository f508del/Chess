//
//  ChessBoard.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#include "Bishop.hpp"
#include "ChessBoard.hpp"
#include "ChessMove.hpp"
#include "ChessSquare.hpp"
#include "Pawn.hpp"
#include "Knight.hpp"

ChessBoard::ChessBoard()
: whitePawnCapabilities_(new Pawn(WHITE_PIECE))
, blackPawnCapabilities_(new Pawn(BLACK_PIECE))
, whiteKnightCapabilities_(new Knight(WHITE_PIECE))
, blackKnightCapabilities_(new Knight(BLACK_PIECE))
, whiteBishopCapabilities_(new Bishop(WHITE_PIECE))
, blackBishopCapabilities_(new Bishop(BLACK_PIECE))
, playerToMakeNextMove_(WHITE_PIECE)
{
   resetBoard();
}

ChessBoard::~ChessBoard()
{

}

bool ChessBoard::anyPieceExistsAt(const ChessSquare& square) const
{
   return (boardState_.find(square) != boardState_.end());
}

bool ChessBoard::whitePieceExistsAt(const ChessSquare& square) const
{
   if (anyPieceExistsAt(square))
   {
      return (pieceAt(square)->affiliation() == WHITE_PIECE);
   }
   return false;
}

bool ChessBoard::blackPieceExistsAt(const ChessSquare& square) const
{
   if (anyPieceExistsAt(square))
   {
      return (pieceAt(square)->affiliation() == BLACK_PIECE);
   }
   return false;}

const I_ChessPiece* ChessBoard::pieceAt(const ChessSquare& square) const
{
   if (anyPieceExistsAt(square))
   {
       return boardState_.at(square);
   }
   return nullptr;
}

void ChessBoard::resetBoard()
{
    boardState_.clear();
    for (char file = 'a'; file <= 'h'; file++)
    {
       boardState_[ChessSquare(file, 2)] = whitePawnCapabilities_.data();
       boardState_[ChessSquare(file, 7)] = blackPawnCapabilities_.data();
    }

    // make back rows pawns for now, until all pieces are implemented.
    for (char file = 'a'; file <= 'h'; file++)
    {
       boardState_[ChessSquare(file, 1)] = whitePawnCapabilities_.data();
       boardState_[ChessSquare(file, 8)] = blackPawnCapabilities_.data();
    }

    // setup the knights
    boardState_[ChessSquare('b', 1)] = whiteKnightCapabilities_.data();
    boardState_[ChessSquare('g', 1)] = whiteKnightCapabilities_.data();
    boardState_[ChessSquare('b', 8)] = blackKnightCapabilities_.data();
    boardState_[ChessSquare('g', 8)] = blackKnightCapabilities_.data();
    
    // setup the bishops
    boardState_[ChessSquare('c', 1)] = whiteBishopCapabilities_.data();
    boardState_[ChessSquare('f', 1)] = whiteBishopCapabilities_.data();
    boardState_[ChessSquare('c', 8)] = whiteBishopCapabilities_.data();
    boardState_[ChessSquare('f', 8)] = whiteBishopCapabilities_.data();
}

ChessPieceAffiliation ChessBoard::playerToMakeNextMove() const
{
    return playerToMakeNextMove_;
}

void ChessBoard::togglePlayerInitiative()
{
   if (playerToMakeNextMove_ == WHITE_PIECE)
   {
      playerToMakeNextMove_ = BLACK_PIECE;
   }
   else
   {
      playerToMakeNextMove_ = WHITE_PIECE;
   }
}

void ChessBoard::applyMove(const ChessMove &move) { 
    const I_ChessPiece* movingPiece = pieceAt(move.startingSquare());
    boardState_[move.endingSquare()] = movingPiece;
    boardState_.erase(boardState_.find(move.startingSquare()));
    return;
}

bool ChessBoard::squaresBetweenEndPointsAreEmpty(const ChessMove &move) const
{
    int rankDifference = move.endingSquare().rank() - move.startingSquare().rank();
    int fileDifference = move.endingSquare().file() - move.startingSquare().file();
    
    // Will yeild an increment of -1, 0, or 1 only.
    int rankIncrement = (rankDifference == 0) ? 0 : (rankDifference / abs(rankDifference));
    int fileIncrement = (fileDifference == 0) ? 0 : (fileDifference / abs(fileDifference));
    
    unsigned int currentRank = move.startingSquare().rank() + rankIncrement;
    char currentFile = move.startingSquare().file() + fileIncrement;
    while ((currentRank != move.endingSquare().rank()) || (currentFile != move.endingSquare().file()))
    {
        if (anyPieceExistsAt(ChessSquare(currentFile, currentRank)))
        {
            return false;
        }
        currentRank += rankIncrement;
        currentFile += fileIncrement;
    }
    return true;
}


