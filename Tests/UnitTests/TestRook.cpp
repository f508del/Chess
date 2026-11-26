//
//  TestRook.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-16.
//

#include "Catch.hpp"
#include "Rook.hpp"

using namespace Chess;

TEST_CASE("Testing the Rook object")
{
    SECTION("Piece knows it is a rook")
    {
        Rook piece(randomPieceAffiliation());
        CHECK(piece.pieceType() == PieceType::ROOK);
    }
    
    SECTION("Will not allow rook to jump other pieces")
    {
        Rook piece(randomPieceAffiliation());
        CHECK(piece.pieceCanJumpOtherPieces() == false);
    }
    
    SECTION("Rooks know their affiliation")
    {
        PieceAffiliation affiliation = randomPieceAffiliation();
        Rook testRook(affiliation);
        CHECK(testRook.affiliation() == affiliation);
    }
    
    SECTION("Rooks can move in increasing ranks")
    {
        Rook piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R1));
        
        CHECK(allowedMoves.contains(ChessSquare(File::D, Rank::R8)));
    }
    
    SECTION("Rooks can move in decreasing ranks")
    {
        Rook piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::F, Rank::R8));
        
        CHECK(allowedMoves.contains(ChessSquare(File::F, Rank::R1)));
    }
    
    SECTION("Rooks can move in increasing files")
    {
        Rook piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R1));
        
        CHECK(allowedMoves.contains(ChessSquare(File::H, Rank::R1)));
    }
    
    SECTION("Rooks can move in decreasing files")
    {
        Rook piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::H, Rank::R3));
        
        CHECK(allowedMoves.contains(ChessSquare(File::A, Rank::R3)));
    }
    
    SECTION("Rooks Cannot move diagonally")
    {
        Rook piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R3));
        
        CHECK(!allowedMoves.contains(ChessSquare(File::C, Rank::R2)));
        CHECK(!allowedMoves.contains(ChessSquare(File::C, Rank::R4)));
        CHECK(!allowedMoves.contains(ChessSquare(File::E, Rank::R2)));
        CHECK(!allowedMoves.contains(ChessSquare(File::E, Rank::R4)));
    }
}
