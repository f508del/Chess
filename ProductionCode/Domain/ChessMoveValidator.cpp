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
#include "ChessMoveRequest.hpp"
#include "ChessSquare.hpp"
#include "I_ChessPiece.hpp"
#include "InternalChessMove.hpp"

using namespace std;
using namespace Chess;

ChessMoveValidator::ChessMoveValidator(ChessBoard& board, const ChessGameHistory& gameHistory)
: board_(board)
, gameHistory_(gameHistory)
{

}

ChessMoveValidator::~ChessMoveValidator()
{

}

InternalChessMove ChessMoveValidator::validateMove(const ChessMoveRequest& currentMove)
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
    
    if (!board_.squaresBetweenEndPointsAreEmpty(currentMove.startingSquare(), currentMove.endingSquare()) && !currentPiece->pieceCanJumpOtherPieces())
    {
        return MoveValidity::PATH_BLOCKED_BY_OTHER_PIECES;
    }
    
    if (enPassantIsCurrentlyPossible() && enPassantIsBeingAttempted(currentMove))
    {
        InternalChessMove internalMove = assembleValidMove(currentMove);
        ChessSquare bypassedSquare(currentMove.endingSquare().file(),
                                   currentMove.startingSquare().rank());
        internalMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE,
                                             bypassedSquare,
                                             oppositePieceAffiliation(board_.playerToMakeNextMove()),
                                             Chess::PieceType::PAWN));
        
        if (movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(internalMove))
        {
            return MoveValidity::CANNOT_LEAVE_KING_IN_DANGER;
        }
        
        return internalMove;
    }
    
    if (!board_.anyPieceExistsAt(currentMove.endingSquare()))
    {
        ExtendedSet<ChessSquare> potentialEmptyBoardMoves = currentPiece->potentialEmptyBoardMovesFrom(currentMove.startingSquare());
        if ((currentPiece->pieceType() == PieceType::KING) && (!board_.hasAnyMoveTouchedSquare(currentMove.startingSquare())))
        {
            char rookStartingFile = currentMove.endingSquare().file() == 'g' ? 'h' : 'a';
            if (!board_.hasAnyMoveTouchedSquare(ChessSquare(rookStartingFile, currentMove.startingSquare().rank()))
                && pathIsNotThreatenedByColor(currentMove.startingSquare(), currentMove.endingSquare(), oppositePieceAffiliation(board_.playerToMakeNextMove())))
            {
                // Castling may be possible...
                potentialEmptyBoardMoves.insert(ChessSquare('g', currentMove.startingSquare().rank()));
                potentialEmptyBoardMoves.insert(ChessSquare('c', currentMove.startingSquare().rank()));
            }
        }
        
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
    
    InternalChessMove potentiallyValidMove = assembleValidMove(currentMove);
    
    if ((currentPiece->pieceType() == PieceType::KING) && (abs(currentMove.startingSquare().file() - currentMove.endingSquare().file()) == 2))
    {
        char rookStartingFile = currentMove.endingSquare().file() == 'g' ? 'h' : 'a';
        char rookEndingFile = rookStartingFile == 'h' ? 'f' : 'd';
        // castling is requested, add the rook shift into the move.
        potentiallyValidMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE,
                                             ChessSquare(rookStartingFile, currentMove.startingSquare().rank()),
                                             board_.playerToMakeNextMove(),
                                             Chess::PieceType::ROOK));
        potentiallyValidMove.addValidMoveElement(MoveElement(MoveElementAction::PLACE_PIECE,
                                             ChessSquare(rookEndingFile, currentMove.startingSquare().rank()),
                                             board_.playerToMakeNextMove(),
                                             Chess::PieceType::ROOK));
    }
    
    
    
    if (movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(potentiallyValidMove))
    {
        return MoveValidity::CANNOT_LEAVE_KING_IN_DANGER;
    }

    return potentiallyValidMove;
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
        
        ChessMoveRequest currentExaminedMove(*attackingPieceLocationIterator,square);
        if (!board.squaresBetweenEndPointsAreEmpty(currentExaminedMove.startingSquare(), currentExaminedMove.endingSquare()) &&
            !currentPiece->pieceCanJumpOtherPieces())
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
    if (abs((int)gameHistory_.mostRecentMoveStartingSquare().rank() - (int)gameHistory_.mostRecentMoveEndingSquare().rank()) == 2)
    {
        if (gameHistory_.mostRecentMovedPiece() == PieceType::PAWN)
        {
            return true;
        }
    }
    return false;
}

bool ChessMoveValidator::enPassantIsBeingAttempted(const ChessMoveRequest& move) const
{
    unsigned int validEnPassantRank =
    ((int)gameHistory_.mostRecentMoveStartingSquare().rank() + (int)gameHistory_.mostRecentMoveEndingSquare().rank()) / 2;
    ChessSquare onlyValidEndingSquareForEnPassantMove(gameHistory_.mostRecentMoveStartingSquare().file(), validEnPassantRank);
    
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

bool ChessMoveValidator::movingPlayersKingWouldBeInCheckAfterApplyingProposedMove(const InternalChessMove& move)
{
    board_.applyMove(move);
    
    bool checkStillExists = isSquareThreatenedByColor(board_, board_.currentKingSquare(board_.playerToMakeNextMove()),
                                                      oppositePieceAffiliation(board_.playerToMakeNextMove()));
    
    board_.reverseMove(move);
    return checkStillExists;
}

InternalChessMove ChessMoveValidator::assembleValidMove(const ChessMoveRequest& currentMove)
{
    InternalChessMove moveElements;
    
    // Start by "picking up" the piece at the starting square
    moveElements.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE,
                                                 currentMove.startingSquare(),
                                                 board_.playerToMakeNextMove(),
                                                 board_.pieceAt(currentMove.startingSquare())->pieceType()));
    
    // If the destination square has a piece on it, insert that removal element (validation done earlier...)
    if (board_.anyPieceExistsAt(currentMove.endingSquare()))
    {
        moveElements.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE,
                                                     currentMove.endingSquare(),
                                                     oppositePieceAffiliation(board_.playerToMakeNextMove()),
                                                     board_.pieceAt(currentMove.endingSquare())->pieceType()));
    }
    
    // Now place the moving piece at the destination square
    moveElements.addValidMoveElement(MoveElement(MoveElementAction::PLACE_PIECE,
                                                 currentMove.endingSquare(),
                                                 board_.playerToMakeNextMove(),
                                                 board_.pieceAt(currentMove.startingSquare())->pieceType()));
    return moveElements;
}

bool ChessMoveValidator::pathIsNotThreatenedByColor(const ChessSquare& startingSquare,
                                                    const ChessSquare& endingSquare,
                                                    Chess::PieceAffiliation threateningColor)
{
    if (isSquareThreatenedByColor(board_, startingSquare, threateningColor))
    {
        return false;
    }
    if (isSquareThreatenedByColor(board_, endingSquare, threateningColor))
    {
        return false;
    }
    return true;
}
