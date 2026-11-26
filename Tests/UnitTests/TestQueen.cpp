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
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R4));
        
        CHECK(allowedMoves.contains(ChessSquare(File::D, Rank::R8)));
        CHECK(allowedMoves.contains(ChessSquare(File::D, Rank::R1)));
    }
    
    SECTION("Queens can move along files")
    {
        Queen piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R4));
        
        CHECK(allowedMoves.contains(ChessSquare(File::A, Rank::R4)));
        CHECK(allowedMoves.contains(ChessSquare(File::H, Rank::R4)));
    }
    
    SECTION("Queens can move diagonally")
    {
        Queen piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R4));
        
        CHECK(allowedMoves.contains(ChessSquare(File::E, Rank::R5)));
        CHECK(allowedMoves.contains(ChessSquare(File::E, Rank::R3)));
        CHECK(allowedMoves.contains(ChessSquare(File::C, Rank::R5)));
        CHECK(allowedMoves.contains(ChessSquare(File::C, Rank::R3)));
    }
    
    SECTION("Queens cannot move like a knight")
    {
        Queen piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R4));
        
        CHECK(!allowedMoves.contains(ChessSquare(File::F, Rank::R5)));
        CHECK(!allowedMoves.contains(ChessSquare(File::B, Rank::R5)));
        CHECK(!allowedMoves.contains(ChessSquare(File::C, Rank::R2)));
        CHECK(!allowedMoves.contains(ChessSquare(File::C, Rank::R6)));
    }
}

