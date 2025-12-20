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
#include "ChessMoveElement.hpp"
#include "ChessMoveRecord.hpp"
#include "ChessSquare.hpp"
#include "InternalChessMove.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "King.hpp"
#include "Knight.hpp"

using namespace Chess;
using namespace std;

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
, whiteKingCapabilities_(new King(PieceAffiliation::WHITE_PIECE))
, blackKingCapabilities_(new King(PieceAffiliation::BLACK_PIECE))
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
    boardState_[ChessSquare('d', 1)] = whiteQueenCapabilities_.data();
    boardState_[ChessSquare('d', 8)] = blackQueenCapabilities_.data();
    
    // setup the kings
    boardState_[ChessSquare('e', 1)] = whiteKingCapabilities_.data();
    boardState_[ChessSquare('e', 8)] = blackKingCapabilities_.data();
}

PieceAffiliation ChessBoard::playerToMakeNextMove() const
{
    return playerToMakeNextMove_;
}

ChessSquare ChessBoard::currentKingSquare(Chess::PieceAffiliation affiliation) const
{
    King* kingOfInterest = (affiliation == Chess::PieceAffiliation::WHITE_PIECE ? whiteKingCapabilities_.data() : blackKingCapabilities_.data());
    
    for(auto boardIterator = boardState_.begin(); boardIterator != boardState_.end(); boardIterator++)
    {
        if (boardIterator->second == kingOfInterest)
        {
            return boardIterator->first;
        }
    }
    return ChessSquare();
}

list<ChessSquare> ChessBoard::allSquaresOccupiedByColor(Chess::PieceAffiliation affiliation) const
{
    list<ChessSquare> occupiedSquares;
    for(auto boardIterator = boardState_.begin(); boardIterator != boardState_.end(); boardIterator++)
    {
        if (boardIterator->second->affiliation() == affiliation)
        {
            occupiedSquares.push_back(boardIterator->first);
        }
    }
    return occupiedSquares;
}

void ChessBoard::togglePlayerInitiative()
{
    playerToMakeNextMove_ = oppositePieceAffiliation(playerToMakeNextMove_);
}

ChessMoveRecord ChessBoard::applyMove(const ChessMove &move) {
    
    const I_ChessPiece* movingPiece = pieceAt(move.startingSquare());
    if (nullptr == movingPiece)
    {
        return ChessMoveRecord();
    }
    
    ChessMoveRecord moveRecord;
    moveRecord.movingPieceAffiliation = movingPiece->affiliation();
    moveRecord.movingPieceType = movingPiece->pieceType();
    moveRecord.movingPieceStartingSquare = move.startingSquare();
    moveRecord.movingPieceEndingSquare = move.endingSquare();
    
    const I_ChessPiece* capturedPiece = pieceAt(move.endingSquare());
    if (nullptr != capturedPiece)
    {
        moveRecord.capturedPieceType = capturedPiece->pieceType();
        moveRecord.capturedPieceSquare = move.endingSquare();
    }
    
    boardState_[move.endingSquare()] = movingPiece;
    removePieceAtSquare(move.startingSquare());
    
    return moveRecord;
}

bool ChessBoard::applyMove(const InternalChessMove& internalMove)
{
    for (auto it = internalMove.moveElements().begin(); it != internalMove.moveElements().end(); it++)
    {
        if (!applyMoveElement(*it))
        {
            return false;
        }
    }
    return true;
}

void ChessBoard::removePieceAtSquare(const ChessSquare& square)
{
    boardState_.erase(boardState_.find(square));
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

bool ChessBoard::reverseMove(const InternalChessMove& internalMove)
{
    for (auto it = internalMove.moveElements().rbegin(); it != internalMove.moveElements().rend(); it++)
    {
        if (!reverseMoveElement(*it))
        {
            return false;
        }
    }
    return true;
}

bool ChessBoard::reverseMove(const ChessMoveRecord& priorMove)
{
    // first, check that the reversal won't step on an existing piece:
    if (anyPieceExistsAt(priorMove.movingPieceStartingSquare))
    {
        return false;
    }
    
    // next make sure the piece that was moved is still where it was put in the record
    const I_ChessPiece* piece = pieceAt(priorMove.movingPieceEndingSquare);
    if (nullptr == piece)
    {
        return false;
    }
    
    if ((piece->affiliation() != priorMove.movingPieceAffiliation) ||
        (piece->pieceType() != priorMove.movingPieceType))
    {
        return false;
    }
    
    // Ok now reverse the move, replacing any captured pieces as needed
    boardState_[priorMove.movingPieceStartingSquare] = piece;
    removePieceAtSquare(priorMove.movingPieceEndingSquare);
    
    if (priorMove.capturedPieceType != Chess::PieceType::NONE)
    {
        boardState_[priorMove.capturedPieceSquare] = chessPieceOfTypeAndAffiliation(priorMove.capturedPieceType,
                                                                                    Chess::oppositePieceAffiliation(priorMove.movingPieceAffiliation));
    }
    
    return true;
}

I_ChessPiece* ChessBoard::chessPieceOfTypeAndAffiliation(Chess::PieceType type, Chess::PieceAffiliation affiliation) const
{
    I_ChessPiece* piece = nullptr;
    
    if (affiliation == Chess::PieceAffiliation::WHITE_PIECE)
    {
        switch(type)
        {
            case Chess::PieceType::PAWN:
                piece = whitePawnCapabilities_.data();
                break;
            case Chess::PieceType::KNIGHT:
                piece = whiteKnightCapabilities_.data();
                break;
            case Chess::PieceType::BISHOP:
                piece = whiteBishopCapabilities_.data();
                break;
            case Chess::PieceType::ROOK:
                piece = whiteRookCapabilities_.data();
                break;
            case Chess::PieceType::QUEEN:
                piece = whiteQueenCapabilities_.data();
                break;
            case Chess::PieceType::KING:
                piece = whiteKingCapabilities_.data();
                break;
            default:
                break;
        }
    }
    else // Affiliation is black
    {
        switch(type)
        {
            case Chess::PieceType::PAWN:
                piece = blackPawnCapabilities_.data();
                break;
            case Chess::PieceType::KNIGHT:
                piece = blackKnightCapabilities_.data();
                break;
            case Chess::PieceType::BISHOP:
                piece = blackBishopCapabilities_.data();
                break;
            case Chess::PieceType::ROOK:
                piece = blackRookCapabilities_.data();
                break;
            case Chess::PieceType::QUEEN:
                piece = blackQueenCapabilities_.data();
                break;
            case Chess::PieceType::KING:
                piece = blackKingCapabilities_.data();
                break;
            default:
                break;
        }
    }
    
    return piece;
}

bool ChessBoard::applyMoveElement(const MoveElement& moveElement)
{
    if (moveElement.action_ == MoveElementAction::PLACE_PIECE)
    {
        return applyPlacePieceMoveElement(moveElement);
    }
    else if (moveElement.action_ == MoveElementAction::REMOVE_PIECE)
    {
        return applyRemovePieceMoveElement(moveElement);
    }
    // In this case it is a NO_ACTION, and should be accepted as is
    return true;
}

bool ChessBoard::applyPlacePieceMoveElement(const MoveElement& moveElement)
{
    const I_ChessPiece* pieceToPlace = chessPieceOfTypeAndAffiliation(moveElement.type_, moveElement.affiliation_);
    boardState_[moveElement.square_] = pieceToPlace;
    return true;
}

bool ChessBoard::applyRemovePieceMoveElement(const MoveElement& moveElement)
{
    removePieceAtSquare(moveElement.square_);
    return true;
}

bool ChessBoard::reverseMoveElement(const MoveElement& moveElement)
{
    if (moveElement.action_ == MoveElementAction::REMOVE_PIECE)
    {
        return applyPlacePieceMoveElement(moveElement);
    }
    else if (moveElement.action_ == MoveElementAction::PLACE_PIECE)
    {
        return applyRemovePieceMoveElement(moveElement);
    }
    // In this case it is a NO_ACTION, and should be accepted as is
    return true;
}
