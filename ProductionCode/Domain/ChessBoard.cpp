//
//  ChessBoard.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#include "Bishop.hpp"
#include "ChessBoard.hpp"
#include "ChessMoveElement.hpp"
#include "ChessSquare.hpp"
#include "InternalChessMove.hpp"
#include "Pawn.hpp"
#include "Queen.hpp"
#include "Rook.hpp"
#include "King.hpp"
#include "Knight.hpp"

using namespace Chess;
using namespace std;

Pawn ChessBoard::whitePawnCapabilities_(PieceAffiliation::WHITE_PIECE);
Pawn ChessBoard::blackPawnCapabilities_(PieceAffiliation::BLACK_PIECE);
Knight ChessBoard::whiteKnightCapabilities_(PieceAffiliation::WHITE_PIECE);
Knight ChessBoard::blackKnightCapabilities_(PieceAffiliation::BLACK_PIECE);
Bishop ChessBoard::whiteBishopCapabilities_(PieceAffiliation::WHITE_PIECE);
Bishop ChessBoard::blackBishopCapabilities_(PieceAffiliation::BLACK_PIECE);
Rook ChessBoard::whiteRookCapabilities_(PieceAffiliation::WHITE_PIECE);
Rook ChessBoard::blackRookCapabilities_(PieceAffiliation::BLACK_PIECE);
Queen ChessBoard::whiteQueenCapabilities_(PieceAffiliation::WHITE_PIECE);
Queen ChessBoard::blackQueenCapabilities_(PieceAffiliation::BLACK_PIECE);
King ChessBoard::whiteKingCapabilities_(PieceAffiliation::WHITE_PIECE);
King ChessBoard::blackKingCapabilities_(PieceAffiliation::BLACK_PIECE);

ChessBoard::ChessBoard()
: playerToMakeNextMove_(PieceAffiliation::WHITE_PIECE)
{
   resetBoard();
}

ChessBoard::ChessBoard(const ChessBoard& src)
: playerToMakeNextMove_(src.playerToMakeNextMove_)
{
    touchedSquares_ = src.touchedSquares_;
    boardState_ = src.boardState_;
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
    clearBoard();
    for (char file = 'a'; file <= 'h'; file++)
    {
       boardState_[ChessSquare(file, 2)] = &whitePawnCapabilities_;
       boardState_[ChessSquare(file, 7)] = &blackPawnCapabilities_;
    }

    // setup the knights
    boardState_[ChessSquare('b', 1)] = &whiteKnightCapabilities_;
    boardState_[ChessSquare('g', 1)] = &whiteKnightCapabilities_;
    boardState_[ChessSquare('b', 8)] = &blackKnightCapabilities_;
    boardState_[ChessSquare('g', 8)] = &blackKnightCapabilities_;
    
    // setup the bishops
    boardState_[ChessSquare('c', 1)] = &whiteBishopCapabilities_;
    boardState_[ChessSquare('f', 1)] = &whiteBishopCapabilities_;
    boardState_[ChessSquare('c', 8)] = &blackBishopCapabilities_;
    boardState_[ChessSquare('f', 8)] = &blackBishopCapabilities_;
    
    // setup the rooks
    boardState_[ChessSquare('a', 1)] = &whiteRookCapabilities_;
    boardState_[ChessSquare('h', 1)] = &whiteRookCapabilities_;
    boardState_[ChessSquare('a', 8)] = &blackRookCapabilities_;
    boardState_[ChessSquare('h', 8)] = &blackRookCapabilities_;
    
    // setup the queens
    boardState_[ChessSquare('d', 1)] = &whiteQueenCapabilities_;
    boardState_[ChessSquare('d', 8)] = &blackQueenCapabilities_;
    
    // setup the kings
    boardState_[ChessSquare('e', 1)] = &whiteKingCapabilities_;
    boardState_[ChessSquare('e', 8)] = &blackKingCapabilities_;
}

PieceAffiliation ChessBoard::playerToMakeNextMove() const
{
    return playerToMakeNextMove_;
}

ChessSquare ChessBoard::currentKingSquare(Chess::PieceAffiliation affiliation) const
{
    King* kingOfInterest = (affiliation == Chess::PieceAffiliation::WHITE_PIECE ? &whiteKingCapabilities_ : &blackKingCapabilities_);
    
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

bool ChessBoard::hasAnyMoveTouchedSquare(const ChessSquare& square) const
{
    return (touchedSquares_.find(square) != touchedSquares_.end());;
}

bool ChessBoard::hasAnyPawnReachedFinalRank() const
{
    for(auto boardIterator = boardState_.begin(); boardIterator != boardState_.end(); boardIterator++)
    {
        if (boardIterator->second->pieceType() == PieceType::PAWN)
        {
            if (boardIterator->first.rank() == 1 || boardIterator->first.rank() == 8)
            {
                return true;
            }
        }
    }
    return false;
}

void ChessBoard::togglePlayerInitiative()
{
    playerToMakeNextMove_ = oppositePieceAffiliation(playerToMakeNextMove_);
}

void ChessBoard::clearBoard()
{
    boardState_.clear();
    touchedSquares_.clear();
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
    touchedSquares_[square] = true;
}

std::list<ChessSquare> ChessBoard::listOfSquaresBetweenEndPoints(const ChessSquare& startSquare, const ChessSquare& endSquare) const
{
    std::list<ChessSquare> pathBetweenEndPoints;
    
    int rankDifference = endSquare.rank() - startSquare.rank();
    int fileDifference = endSquare.file() - startSquare.file();
    
    // Will yield an increment of -1, 0, or 1 only.
    int rankIncrement = (rankDifference == 0) ? 0 : (rankDifference / abs(rankDifference));
    int fileIncrement = (fileDifference == 0) ? 0 : (fileDifference / abs(fileDifference));
    
    // handle the case for knight moves: (basically fancy math to avoid infinite loop below when checking knight moves)
    if (rankDifference * fileDifference != 0) // ignore pieces that move cardinal directions to avoid divide by zero
    {
        if (abs(rankDifference / fileDifference) == 2) // only knight moves have this ratio
        {
            rankIncrement *= 2;
        }
        if (abs(fileDifference / rankDifference) == 2) // this is the other half of possible knight moves
        {
            fileIncrement *= 2;
        }
    }
    
    unsigned int currentRank = startSquare.rank() + rankIncrement;
    char currentFile = startSquare.file() + fileIncrement;
    while ((currentRank != endSquare.rank()) || (currentFile != endSquare.file()))
    {
        pathBetweenEndPoints.push_back(ChessSquare(currentFile, currentRank));
        currentRank += rankIncrement;
        currentFile += fileIncrement;
    }
    return pathBetweenEndPoints;
}

bool ChessBoard::squaresBetweenEndPointsAreEmpty(const ChessSquare& startSquare, const ChessSquare& endSquare) const
{
    std::list<ChessSquare> pathSquares = listOfSquaresBetweenEndPoints(startSquare, endSquare);
    
    for (auto it = pathSquares.begin(); it != pathSquares.end(); it++)
    {
        if (anyPieceExistsAt(*it))
        {
            return false;
        }
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

I_ChessPiece* ChessBoard::chessPieceOfTypeAndAffiliation(Chess::PieceType type, Chess::PieceAffiliation affiliation) const
{
    I_ChessPiece* piece = nullptr;
    
    if (affiliation == Chess::PieceAffiliation::WHITE_PIECE)
    {
        switch(type)
        {
            case Chess::PieceType::PAWN:
                piece = &whitePawnCapabilities_;
                break;
            case Chess::PieceType::KNIGHT:
                piece = &whiteKnightCapabilities_;
                break;
            case Chess::PieceType::BISHOP:
                piece = &whiteBishopCapabilities_;
                break;
            case Chess::PieceType::ROOK:
                piece = &whiteRookCapabilities_;
                break;
            case Chess::PieceType::QUEEN:
                piece = &whiteQueenCapabilities_;
                break;
            case Chess::PieceType::KING:
                piece = &whiteKingCapabilities_;
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
                piece = &blackPawnCapabilities_;
                break;
            case Chess::PieceType::KNIGHT:
                piece = &blackKnightCapabilities_;
                break;
            case Chess::PieceType::BISHOP:
                piece = &blackBishopCapabilities_;
                break;
            case Chess::PieceType::ROOK:
                piece = &blackRookCapabilities_;
                break;
            case Chess::PieceType::QUEEN:
                piece = &blackQueenCapabilities_;
                break;
            case Chess::PieceType::KING:
                piece = &blackKingCapabilities_;
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
    touchedSquares_[moveElement.square_] = true;
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
