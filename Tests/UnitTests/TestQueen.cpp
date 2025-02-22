//
//  TestQueen.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-22.
//

#include "Catch.hpp"
#include "Queen.hpp"

using namespace Chess;

TEST_CASE("Testing the Queen object")
{
    SECTION("Piece knows it is a queen")
    {
        Queen piece(randomPieceAffiliation());
        CHECK(piece.pieceType() == PieceType::QUEEN);
    }
    
    SECTION("Will not allow queen to jump other pieces")
    {
        Queen piece(randomPieceAffiliation());
        CHECK(piece.pieceCanJumpOtherPieces() == false);
    }
    
    SECTION("Queens know their affiliation")
    {
        PieceAffiliation affiliation = randomPieceAffiliation();
        Queen testQueen(affiliation);
        CHECK(testQueen.affiliation() == affiliation);
    }
    
    SECTION("Queens can move along ranks")
    {
        Queen piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(allowedMoves.contains(ChessSquare('d', 8)));
        CHECK(allowedMoves.contains(ChessSquare('d', 1)));
    }
    
    SECTION("Queens can move along files")
    {
        Queen piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(allowedMoves.contains(ChessSquare('a', 4)));
        CHECK(allowedMoves.contains(ChessSquare('h', 4)));
    }
    
    SECTION("Queens can move diagonally")
    {
        Queen piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(allowedMoves.contains(ChessSquare('e', 5)));
        CHECK(allowedMoves.contains(ChessSquare('e', 3)));
        CHECK(allowedMoves.contains(ChessSquare('c', 5)));
        CHECK(allowedMoves.contains(ChessSquare('c', 3)));
    }
    
    SECTION("Queens cannot move like a knight")
    {
        Queen piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(!allowedMoves.contains(ChessSquare('f', 5)));
        CHECK(!allowedMoves.contains(ChessSquare('b', 5)));
        CHECK(!allowedMoves.contains(ChessSquare('c', 2)));
        CHECK(!allowedMoves.contains(ChessSquare('c', 6)));
    }
}

