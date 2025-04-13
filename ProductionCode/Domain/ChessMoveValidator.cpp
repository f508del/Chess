//
//  ChessMoveValidator.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#include "ChessMoveValidator.hpp"

#include "ChessBoard.hpp"
#include "ChessGameHistory.hpp"
#include "ChessMove.hpp"
#include "ChessSquare.hpp"
#include "I_ChessPiece.hpp"

using namespace std;
using namespace Chess;

ChessMoveValidator::ChessMoveValidator(const ChessBoard& board, const ChessGameHistory& gameHistory)
: board_(board)
, gameHistory_(gameHistory)
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
    
    if ((currentPiece->affiliation() != board_.playerToMakeNextMove()))
    {
        return MoveValidity::OPPOSING_PLAYERS_PIECE;
    }
    
    if (!board_.squaresBetweenEndPointsAreEmpty(currentMove) && !currentPiece->pieceCanJumpOtherPieces())
    {
        return MoveValidity::PATH_BLOCKED_BY_OTHER_PIECES;
    }
    
    if (enPassantIsCurrentlyPossible() && enPassantIsBeingAttempted(currentMove))
    {
        return MoveValidity::VALID_EN_PASSANT_MOVE;
    }
    
    if (movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(currentMove))
    {
        return MoveValidity::NOT_LEGAL_DESTINATION_FOR_CURRENT_PIECE;
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

bool ChessMoveValidator::isSquareThreatenedByColor(const ChessBoard& board, const ChessSquare& square, PieceAffiliation attackingColor)
{
    bool squareIsThreatened = false;
    
    list<ChessSquare> attackingPieces = board.allSquaresOccupiedByColor(attackingColor);
    for (auto attackingPieceLocationIterator = attackingPieces.begin(); attackingPieceLocationIterator != attackingPieces.end();
         attackingPieceLocationIterator++)
    {
        const I_ChessPiece* currentPiece = board.pieceAt(*attackingPieceLocationIterator);
        ExtendedSet<ChessSquare> potentialCaptureMoves = currentPiece->potentialCaptureMovesFrom(*attackingPieceLocationIterator);
        if (!potentialCaptureMoves.contains(square))
        {
            continue;
        }
        
        ChessMove currentExaminedMove(*attackingPieceLocationIterator,square);
        if (!board.squaresBetweenEndPointsAreEmpty(currentExaminedMove) && !currentPiece->pieceCanJumpOtherPieces())
        {
            continue;
        }
        
        squareIsThreatened = true;
        break;
    }
    
    return squareIsThreatened;
}

bool ChessMoveValidator::enPassantIsCurrentlyPossible() const
{
    if (abs((int)gameHistory_.mostRecentMove().startingSquare().rank() - (int)gameHistory_.mostRecentMove().endingSquare().rank()) == 2)
    {
        if (gameHistory_.mostRecentMovedPiece() == PieceType::PAWN)
        {
            return true;
        }
    }
    return false;
}

bool ChessMoveValidator::enPassantIsBeingAttempted(const ChessMove& move) const
{
    unsigned int validEnPassantRank =
    ((int)gameHistory_.mostRecentMove().startingSquare().rank() + (int)gameHistory_.mostRecentMove().endingSquare().rank()) / 2;
    ChessSquare onlyValidEndingSquareForEnPassantMove(gameHistory_.mostRecentMove().startingSquare().file(), validEnPassantRank);
    
    if (move.endingSquare() == onlyValidEndingSquareForEnPassantMove)
    {
        if (abs(move.startingSquare().file() - move.endingSquare().file()) == 1)
        {
            if (board_.pieceAt(move.startingSquare())->pieceType() == PieceType::PAWN)
            {
                return true;
            }
        }
    }
    
    return false;
}

bool ChessMoveValidator::movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(const ChessMove& move)
{
    // TODO
    // Setup the board with the move hypothetically applied...
    /*bool checkStillExists = isSquareThreatenedByColor(board_, board_.currentKingSquare(board_.playerToMakeNextMove()),
                                                      oppositePieceAffiliation(board_.playerToMakeNextMove()));*/
    return false;
}
