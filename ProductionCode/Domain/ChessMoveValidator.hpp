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
class ChessMoveRequest;
class ChessBoard;
class ChessGameHistory;

class ChessMoveValidator
{
public:
    ChessMoveValidator(ChessBoard& board, const ChessGameHistory& gameHistory);
    virtual ~ChessMoveValidator();

    InternalChessMove validateMove(const ChessMoveRequest& currentMove);
    
    bool isSquareThreatenedByColor(const ChessBoard& board, const ChessSquare& square, Chess::PieceAffiliation attackingColor);

private:
    bool enPassantIsCurrentlyPossible() const;
    bool enPassantIsBeingAttempted(const ChessMoveRequest& move) const;
    bool movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(const InternalChessMove& move);
    InternalChessMove assembleValidMove(const ChessMoveRequest& currentMove);
    bool pathIsNotThreatenedByColor(const ChessSquare& startingSquare, const ChessSquare& endingSquare, Chess::PieceAffiliation threateningColor);
    
private:
    ChessBoard& board_;
    const ChessGameHistory& gameHistory_;
};
