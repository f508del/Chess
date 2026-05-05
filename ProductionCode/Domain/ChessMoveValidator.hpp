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
#include <list>

class InternalChessMove;
class ChessMoveRequest;
class ChessBoard;
class ChessGameHistory;

class ChessMoveValidator
{
public:
    ChessMoveValidator(const ChessBoard& board, const ChessGameHistory& gameHistory);
    virtual ~ChessMoveValidator();

    InternalChessMove validateMove(const ChessMoveRequest& currentMove);
    
    bool isSquareThreatenedByColor(const ChessSquare& square, Chess::PieceAffiliation attackingColor);
    ChessSquare findSquareOfPieceThatCouldCapture(const ChessSquare& squareInThreat, Chess::PieceAffiliation attackingColor,
                                                  const ChessBoard& currentBoard);
    ChessSquare findSquareOfPieceThatCouldMoveTo(const ChessSquare& destinationSquare, Chess::PieceAffiliation movingColor);
    std::list<InternalChessMove> findAllPotentialMovesFor(Chess::PieceAffiliation playerColor);
    bool movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(const InternalChessMove& move);
    
private:
    bool enPassantIsCurrentlyPossible() const;
    bool enPassantIsBeingAttempted(const ChessMoveRequest& move) const;
    
    InternalChessMove assembleValidMove(const ChessMoveRequest& currentMove);
    bool castlingPathIsNotThreatenedByColor(const ChessSquare& startingSquare, const ChessSquare& endingSquare, Chess::PieceAffiliation threateningColor);
    
private:
    const ChessBoard& board_;
    const ChessGameHistory& gameHistory_;
};
