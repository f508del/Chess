//
//  TestBishop.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-01.
//

#include "Catch.hpp"
#include "Bishop.hpp"

TEST_CASE("Testing the Bishop object")
{
    SECTION("Piece knows it is a bishop")
    {
        Bishop piece(Chess::PieceAffiliation::WHITE_PIECE);
        CHECK(piece.pieceType() == Chess::PieceType::BISHOP);
    }
    
    SECTION("Will allow bishop to move diagonally towards the top right")
    {
        Bishop bishop(Chess::PieceAffiliation::WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('c', 1));
        CHECK(allowedMoves.contains(ChessSquare('d', 2)));
    }
    
    SECTION("Will allow bishop to move diagonally towards the bottom right")
    {
        Bishop bishop(Chess::PieceAffiliation::WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('d', 2));
        CHECK(allowedMoves.contains(ChessSquare('e', 1)));
    }
    
    SECTION("Will allow bishops to move diagonally towards bottom left")
    {
        Bishop bishop(Chess::PieceAffiliation::WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        CHECK(allowedMoves.contains(ChessSquare('c', 3)));
    }
    
    SECTION("Will allow bishops to move diagonally towards top left")
    {
        Bishop bishop(Chess::PieceAffiliation::WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        CHECK(allowedMoves.contains(ChessSquare('c', 5)));
    }
    
    SECTION("Will not allow bishops to move in cardinal directions")
    {
        Bishop bishop(Chess::PieceAffiliation::WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        CHECK(!allowedMoves.contains(ChessSquare('d', 5)));
        CHECK(!allowedMoves.contains(ChessSquare('d', 3)));
        CHECK(!allowedMoves.contains(ChessSquare('c', 4)));
        CHECK(!allowedMoves.contains(ChessSquare('e', 4)));
    }
    
    SECTION("Will not allow bishop to jump other pieces")
    {
        Bishop bishop(Chess::PieceAffiliation::WHITE_PIECE);
        CHECK(bishop.pieceCanJumpOtherPieces() == false);
    }
}
