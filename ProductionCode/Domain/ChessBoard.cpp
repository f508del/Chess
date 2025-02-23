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
#include "Queen.hpp"
#include "Rook.hpp"
#include "Knight.hpp"

using namespace Chess;

ChessBoard::ChessBoard()
: whitePawnCapabilities_(new Pawn(PieceAffiliation::WHITE_PIECE))
, blackPawnCapabilities_(new Pawn(PieceAffiliation::BLACK_PIECE))
, whiteKnightCapabilities_(new Knight(PieceAffiliation::WHITE_PIECE))
, blackKnightCapabilities_(new Knight(PieceAffiliation::BLACK_PIECE))
, whiteBishopCapabilities_(new Bishop(PieceAffiliation::WHITE_PIECE))
, blackBishopCapabilities_(new Bishop(PieceAffiliation::BLACK_PIECE))
, whiteRookCapabilities_(new Rook(PieceAffiliation::WHITE_PIECE))
, blackRookCapabilities_(new Rook(PieceAffiliation::BLACK_PIECE))
, whiteQueenCapabilities_(new Queen(PieceAffiliation::WHITE_PIECE))
, blackQueenCapabilities_(new Queen(PieceAffiliation::BLACK_PIECE))
, playerToMakeNextMove_(PieceAffiliation::WHITE_PIECE)
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
      return (pieceAt(square)->affiliation() == PieceAffiliation::WHITE_PIECE);
   }
   return false;
}

bool ChessBoard::blackPieceExistsAt(const ChessSquare& square) const
{
   if (anyPieceExistsAt(square))
   {
      return (pieceAt(square)->affiliation() == PieceAffiliation::BLACK_PIECE);
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
    boardState_[ChessSquare('c', 8)] = blackBishopCapabilities_.data();
    boardState_[ChessSquare('f', 8)] = blackBishopCapabilities_.data();
    
    // setup the rooks
    boardState_[ChessSquare('a', 1)] = whiteRookCapabilities_.data();
    boardState_[ChessSquare('h', 1)] = whiteRookCapabilities_.data();
    boardState_[ChessSquare('a', 8)] = blackRookCapabilities_.data();
    boardState_[ChessSquare('h', 8)] = blackRookCapabilities_.data();
    
    // setup the queens
    boardState_[ChessSquare('e', 1)] = whiteQueenCapabilities_.data();
    boardState_[ChessSquare('e', 8)] = blackQueenCapabilities_.data();
}

PieceAffiliation ChessBoard::playerToMakeNextMove() const
{
    return playerToMakeNextMove_;
}

void ChessBoard::togglePlayerInitiative()
{
   if (playerToMakeNextMove_ == PieceAffiliation::WHITE_PIECE)
   {
      playerToMakeNextMove_ = PieceAffiliation::BLACK_PIECE;
   }
   else
   {
      playerToMakeNextMove_ = PieceAffiliation::WHITE_PIECE;
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
    
    // Will yield an increment of -1, 0, or 1 only.
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


