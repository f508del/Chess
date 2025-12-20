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

class InternalChessMove;
class ChessMove;
class ChessBoard;
class ChessGameHistory;

class ChessMoveValidator
{
public:
    ChessMoveValidator(ChessBoard& board, const ChessGameHistory& gameHistory);
    virtual ~ChessMoveValidator();

    InternalChessMove validateMove(const ChessMove& currentMove);
    
    bool isSquareThreatenedByColor(const ChessBoard& board, const ChessSquare& square, Chess::PieceAffiliation attackingColor);

private:
    bool enPassantIsCurrentlyPossible() const;
    bool enPassantIsBeingAttempted(const ChessMove& move) const;
    bool movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(const InternalChessMove& move);
    InternalChessMove assembleValidMove(const ChessMove& currentMove);
    
private:
    ChessBoard& board_;
    const ChessGameHistory& gameHistory_;
};
