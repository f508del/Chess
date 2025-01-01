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
        Bishop piece(WHITE_PIECE);
        CHECK(piece.pieceName() == "Bishop");
    }
    
    SECTION("Will allow bishop to move diagonally towards the top right")
    {
        Bishop bishop(WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('c', 1));
        CHECK(allowedMoves.contains(ChessSquare('d', 2)));
    }
    
    SECTION("Will allow bishop to move diagonally towards the bottom right")
    {
        Bishop bishop(WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('d', 2));
        CHECK(allowedMoves.contains(ChessSquare('e', 1)));
    }
    
    SECTION("Will allow bishops to move diagonally towards bottom left")
    {
        Bishop bishop(WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        CHECK(allowedMoves.contains(ChessSquare('c', 3)));
    }
    
    SECTION("Will allow bishops to move diagonally towards top left")
    {
        Bishop bishop(WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        CHECK(allowedMoves.contains(ChessSquare('c', 5)));
    }
    
    SECTION("Will not allow bishops to move in cardinal directions")
    {
        Bishop bishop(WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        CHECK(!allowedMoves.contains(ChessSquare('d', 5)));
        CHECK(!allowedMoves.contains(ChessSquare('d', 3)));
        CHECK(!allowedMoves.contains(ChessSquare('c', 4)));
        CHECK(!allowedMoves.contains(ChessSquare('e', 4)));
    }
}
