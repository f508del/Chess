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
class ChessMove;
class I_ChessPiece;
class King;
class Knight;
class Pawn;
class Queen;
class Rook;
struct ChessMoveRecord;

class ChessBoard : public I_ReadOnlyChessBoard
{
public:
    explicit ChessBoard();
    virtual ~ChessBoard();

    bool anyPieceExistsAt(const ChessSquare& square) const;
    bool whitePieceExistsAt(const ChessSquare& square) const;
    bool blackPieceExistsAt(const ChessSquare& square) const;

    const I_ChessPiece* pieceAt(const ChessSquare& square) const;

    bool squaresBetweenEndPointsAreEmpty(const ChessMove& move) const;
    Chess::PieceAffiliation playerToMakeNextMove() const;
    
    ChessSquare currentKingSquare(Chess::PieceAffiliation affiliation) const;
    std::list<ChessSquare> allSquaresOccupiedByColor(Chess::PieceAffiliation affiliation) const;
    
    ChessMoveRecord applyMove(const ChessMove& move);
    bool reverseMove(const ChessMoveRecord& priorMove);
    void removePieceAtSquare(const ChessSquare& square);
    void resetBoard();
    void togglePlayerInitiative();

private:
    I_ChessPiece* chessPieceOfTypeAndAffiliation(Chess::PieceType type, Chess::PieceAffiliation affiliation) const;
    
    ScopedPointer<Pawn> whitePawnCapabilities_;
    ScopedPointer<Pawn> blackPawnCapabilities_;
    ScopedPointer<Knight> whiteKnightCapabilities_;
    ScopedPointer<Knight> blackKnightCapabilities_;
    ScopedPointer<Bishop> whiteBishopCapabilities_;
    ScopedPointer<Bishop> blackBishopCapabilities_;
    ScopedPointer<Rook> whiteRookCapabilities_;
    ScopedPointer<Rook> blackRookCapabilities_;
    ScopedPointer<Queen> whiteQueenCapabilities_;
    ScopedPointer<Queen> blackQueenCapabilities_;
    ScopedPointer<King> whiteKingCapabilities_;
    ScopedPointer<King> blackKingCapabilities_;

   std::map<ChessSquare, const I_ChessPiece*> boardState_;

   Chess::PieceAffiliation playerToMakeNextMove_;
};
