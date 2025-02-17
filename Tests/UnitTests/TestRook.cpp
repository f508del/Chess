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
        Rook piece(PieceAffiliation::WHITE_PIECE);
        CHECK(piece.pieceType() == PieceType::ROOK);
    }
    
    SECTION("Will not allow rook to jump other pieces")
    {
        Rook piece(PieceAffiliation::WHITE_PIECE);
        CHECK(piece.pieceCanJumpOtherPieces() == false);
    }
    
    SECTION("Rooks know their affiliation")
    {
        Rook blackRook(PieceAffiliation::BLACK_PIECE);
        CHECK(blackRook.affiliation() == PieceAffiliation::BLACK_PIECE);
    }
    
    SECTION("Rooks can move in increasing ranks")
    {
        Rook piece(PieceAffiliation::WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 1));
        
        CHECK(allowedMoves.contains(ChessSquare('d', 8)));
    }
    
    SECTION("Rooks can move in decreasing ranks")
    {
        Rook piece(PieceAffiliation::BLACK_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('f', 8));
        
        CHECK(allowedMoves.contains(ChessSquare('f', 1)));
    }
    
    SECTION("Rooks can move in increasing files")
    {
        Rook piece(PieceAffiliation::WHITE_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('a', 1));
        
        CHECK(allowedMoves.contains(ChessSquare('h', 1)));
    }
    
    SECTION("Rooks can move in decreasing files")
    {
        Rook piece(PieceAffiliation::BLACK_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('h', 3));
        
        CHECK(allowedMoves.contains(ChessSquare('a', 3)));
    }
    
    SECTION("Rooks Cannot move diagonally")
    {
        Rook piece(PieceAffiliation::BLACK_PIECE);
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 3));
        
        CHECK(!allowedMoves.contains(ChessSquare('c', 2)));
        CHECK(!allowedMoves.contains(ChessSquare('c', 4)));
        CHECK(!allowedMoves.contains(ChessSquare('e', 2)));
        CHECK(!allowedMoves.contains(ChessSquare('e', 4)));
    }
}
