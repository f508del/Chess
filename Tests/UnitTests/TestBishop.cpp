//
//  TestBishop.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-01.
//

#include "Catch.hpp"
#include "Bishop.hpp"

using namespace Chess;

TEST_CASE("Testing the Bishop object")
{
    SECTION("Piece knows it is a bishop")
    {
        Bishop piece(randomPieceAffiliation());
        CHECK(piece.pieceType() == PieceType::BISHOP);
    }
    
    SECTION("Will allow bishop to move diagonally towards the top right")
    {
        Bishop bishop(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R1));
        CHECK(allowedMoves.contains(ChessSquare(File::H, Rank::R8)));
    }
    
    SECTION("Will allow bishop to move diagonally towards the bottom right")
    {
        Bishop bishop(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R2));
        CHECK(allowedMoves.contains(ChessSquare(File::E, Rank::R1)));
    }
    
    SECTION("Will allow bishops to move diagonally towards bottom left")
    {
        Bishop bishop(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R4));
        CHECK(allowedMoves.contains(ChessSquare(File::C, Rank::R3)));
    }
    
    SECTION("Will allow bishops to move diagonally towards top left")
    {
        Bishop bishop(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R4));
        CHECK(allowedMoves.contains(ChessSquare(File::C, Rank::R5)));
    }
    
    SECTION("Will not allow bishops to move in cardinal directions")
    {
        Bishop bishop(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        bishop.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R4));
        CHECK(!allowedMoves.contains(ChessSquare(File::D, Rank::R5)));
        CHECK(!allowedMoves.contains(ChessSquare(File::D, Rank::R3)));
        CHECK(!allowedMoves.contains(ChessSquare(File::C, Rank::R4)));
        CHECK(!allowedMoves.contains(ChessSquare(File::E, Rank::R4)));
    }
    
    SECTION("Will not allow bishop to jump other pieces")
    {
        Bishop bishop(randomPieceAffiliation());
        CHECK(bishop.pieceCanJumpOtherPieces() == false);
    }
}
