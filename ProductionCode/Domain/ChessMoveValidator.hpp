//
//  ChessMoveValidator.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#pragma once
#include "ChessMoveValidity.hpp"
#include "ChessPieceAffiliation.hpp"
#include "ChessSquare.hpp"

class ChessMove;
class ChessBoard;
class ChessGameHistory;

class ChessMoveValidator
{
public:
    ChessMoveValidator(const ChessBoard& board, const ChessGameHistory& gameHistory);
    virtual ~ChessMoveValidator();

    Chess::MoveValidity validateMove(const ChessMove& currentMove);
    
    bool isSquareThreatenedByColor(const ChessSquare& square, Chess::PieceAffiliation attackingColor);

private:
    void ignorePlayerInitiative();
    void accountForPlayerInitiative();

    bool enPassantIsCurrentlyPossible() const;
    bool enPassantIsBeingAttempted(const ChessMove& move) const;
    
private:
    const ChessBoard& board_;
    const ChessGameHistory& gameHistory_;
    bool playerInitiativeIsApplicable_;
};
