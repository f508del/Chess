//
//  ChessBoard.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#pragma once

#include "ChessPieceAffiliation.hpp"
#include "ChessPieceType.hpp"
#include "ScopedPointer.hpp"
#include "I_ReadOnlyChessBoard.hpp"
#include <map>
#include <list>

class Bishop;
class ChessSquare;
class ChessMoveRequest;
class I_ChessPiece;
class InternalChessMove;
class King;
class Knight;
class Pawn;
class Queen;
class Rook;

namespace Chess{
class MoveElement;
}

class ChessBoard : public I_ReadOnlyChessBoard
{
public:
    explicit ChessBoard();
    explicit ChessBoard(const ChessBoard& src);
    virtual ~ChessBoard();

    bool anyPieceExistsAt(const ChessSquare& square) const;
    bool whitePieceExistsAt(const ChessSquare& square) const;
    bool blackPieceExistsAt(const ChessSquare& square) const;

    const I_ChessPiece* pieceAt(const ChessSquare& square) const;

    std::list<ChessSquare> listOfSquaresBetweenEndPoints(const ChessSquare& startSquare, const ChessSquare& endSquare) const;
    bool squaresBetweenEndPointsAreEmpty(const ChessSquare& startSquare, const ChessSquare& endSquare) const;
    Chess::PieceAffiliation playerToMakeNextMove() const;
    
    ChessSquare currentKingSquare(Chess::PieceAffiliation affiliation) const;
    std::list<ChessSquare> allSquaresOccupiedByColor(Chess::PieceAffiliation affiliation) const;
    bool hasAnyMoveTouchedSquare(const ChessSquare& square) const;
    bool hasAnyPawnReachedFinalRank() const;
    
    bool applyMove(const InternalChessMove& internalMove);
    bool reverseMove(const InternalChessMove& internalMove);
    void removePieceAtSquare(const ChessSquare& square);
    void resetBoard();
    void togglePlayerInitiative();
    void clearBoard();

private:
    I_ChessPiece* chessPieceOfTypeAndAffiliation(Chess::PieceType type, Chess::PieceAffiliation affiliation) const;
    bool applyMoveElement(const Chess::MoveElement& moveElement);
    bool applyPlacePieceMoveElement(const Chess::MoveElement& moveElement);
    bool applyRemovePieceMoveElement(const Chess::MoveElement& moveElement);
    bool reverseMoveElement(const Chess::MoveElement& moveElement);
    
    static Pawn whitePawnCapabilities_;
    static Pawn blackPawnCapabilities_;
    static Knight whiteKnightCapabilities_;
    static Knight blackKnightCapabilities_;
    static Bishop whiteBishopCapabilities_;
    static Bishop blackBishopCapabilities_;
    static Rook whiteRookCapabilities_;
    static Rook blackRookCapabilities_;
    static Queen whiteQueenCapabilities_;
    static Queen blackQueenCapabilities_;
    static King whiteKingCapabilities_;
    static King blackKingCapabilities_;

    std::map<ChessSquare, const I_ChessPiece*> boardState_;
    std::map<ChessSquare, bool> touchedSquares_;

    Chess::PieceAffiliation playerToMakeNextMove_;
};
