//
//  ChessMoveValidator.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#include "ChessMoveValidator.hpp"

#include "ChessBoard.hpp"
#include "ChessMove.hpp"
#include "ChessSquare.hpp"
#include "I_ChessPiece.hpp"

using namespace std;
using namespace Chess;

ChessMoveValidator::ChessMoveValidator(const ChessBoard& board)
: board_(board)
, playerInitiativeIsApplicable_(true)
{

}

ChessMoveValidator::~ChessMoveValidator()
{

}

MoveValidity ChessMoveValidator::validateMove(const ChessMove& currentMove)
{
    if (!currentMove.isOnTheBoard())
    {
        return MoveValidity::END_SQUARE_NOT_ON_BOARD;
    }

    const I_ChessPiece* currentPiece = board_.pieceAt(currentMove.startingSquare());
    if (nullptr == currentPiece)
    {
        return MoveValidity::NO_PIECE_AT_STARTING_LOCATION;
    }
    
    if ((currentPiece->affiliation() != board_.playerToMakeNextMove()) && playerInitiativeIsApplicable_)
    {
        return MoveValidity::OPPOSING_PLAYERS_PIECE;
    }
    
    if (!board_.squaresBetweenEndPointsAreEmpty(currentMove) && !currentPiece->pieceCanJumpOtherPieces())
    {
        return MoveValidity::PATH_BLOCKED_BY_OTHER_PIECES;
    }
    
    if (!board_.anyPieceExistsAt(currentMove.endingSquare()))
    {
        ExtendedSet<ChessSquare> potentialEmptyBoardMoves = currentPiece->potentialEmptyBoardMovesFrom(currentMove.startingSquare());
        if (!potentialEmptyBoardMoves.contains(currentMove.endingSquare()))
        {
            return MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE;
        }
    }
    else
    {
        // a piece exists at destination square...
        ExtendedSet<ChessSquare> potentialCaptureMoves = currentPiece->potentialCaptureMovesFrom(currentMove.startingSquare());
        if (!potentialCaptureMoves.contains(currentMove.endingSquare()))
        {
            return MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE;
        }
        
        if ((currentPiece->affiliation() ==
             (board_.pieceAt(currentMove.endingSquare())->affiliation())))
        {
            return MoveValidity::DESTINATION_BLOCKED_BY_EXISTING_PIECE;
        }
    }

    return MoveValidity::VALID_MOVE;
}

void ChessMoveValidator::ignorePlayerInitiative()
{
    playerInitiativeIsApplicable_ = false;
}

void ChessMoveValidator::accountForPlayerInitiative()
{
    playerInitiativeIsApplicable_ = true;
}
