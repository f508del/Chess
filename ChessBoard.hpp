//
//  ChessBoard.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#pragma once

#include "ChessPieceAffiliation.hpp"
#include "ScopedPointer.hpp"
#include <map>

class Bishop;
class ChessSquare;
class ChessMove;
class I_ChessPiece;
class Knight;
class Pawn;


class ChessBoard
{
public:
    explicit ChessBoard();
    virtual ~ChessBoard();

    bool anyPieceExistsAt(const ChessSquare& square) const;
    bool whitePieceExistsAt(const ChessSquare& square) const;
    bool blackPieceExistsAt(const ChessSquare& square) const;

    I_ChessPiece* pieceAt(const ChessSquare& square) const;

    bool squaresBetweenEndPointsAreEmpty(const ChessMove& move) const;
    void applyMove(const ChessMove& move);
    void resetBoard();

    ChessPieceAffiliation playerToMakeNextMove() const;
    void togglePlayerInitiative();

private:
    ScopedPointer<Pawn> whitePawnCapabilities_;
    ScopedPointer<Pawn> blackPawnCapabilities_;
    ScopedPointer<Knight> whiteKnightCapabilities_;
    ScopedPointer<Knight> blackKnightCapabilities_;
    ScopedPointer<Bishop> whiteBishopCapabilities_;
    ScopedPointer<Bishop> blackBishopCapabilities_;

   std::map<ChessSquare, I_ChessPiece*> boardState_;

   ChessPieceAffiliation playerToMakeNextMove_;
};
