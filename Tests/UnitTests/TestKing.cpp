//
//  TestKing.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-02-23.
//

#include "Catch.hpp"
#include "King.hpp"

using namespace Chess;

TEST_CASE("Testing the King object")
{
    SECTION("Piece knows it is a King")
    {
        King piece(randomPieceAffiliation());
        CHECK(piece.pieceType() == PieceType::KING);
    }
    
    SECTION("Will not allow king to jump other pieces")
    {
        King piece(randomPieceAffiliation());
        CHECK(piece.pieceCanJumpOtherPieces() == false);
    }
    
    SECTION("Kings know their affiliation")
    {
        PieceAffiliation affiliation = randomPieceAffiliation();
        King testPiece(affiliation);
        CHECK(testPiece.affiliation() == affiliation);
    }
    
    SECTION("Kings can move along ranks, one step")
    {
        King piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(allowedMoves.contains(ChessSquare('d', 5)));
        CHECK(allowedMoves.contains(ChessSquare('d', 3)));
    }
    
    SECTION("Kings can move along files, one step")
    {
        King piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(allowedMoves.contains(ChessSquare('c', 4)));
        CHECK(allowedMoves.contains(ChessSquare('e', 4)));
    }
    
    SECTION("Kings can move diagonally, one step")
    {
        King piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(allowedMoves.contains(ChessSquare('e', 5)));
        CHECK(allowedMoves.contains(ChessSquare('e', 3)));
        CHECK(allowedMoves.contains(ChessSquare('c', 5)));
        CHECK(allowedMoves.contains(ChessSquare('c', 3)));
    }
    
    SECTION("Kings cant move along ranks, more than one step at a time")
    {
        King piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(!allowedMoves.contains(ChessSquare('d', 6)));
        CHECK(!allowedMoves.contains(ChessSquare('d', 2)));
    }
    
    SECTION("Kings cant move along files, more than one step at a time")
    {
        King piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(!allowedMoves.contains(ChessSquare('f', 4)));
        CHECK(!allowedMoves.contains(ChessSquare('b', 4)));
    }
    
    SECTION("Kings cant move along diagonals, more than one step at a time")
    {
        King piece(randomPieceAffiliation());
        ExtendedSet<ChessSquare> allowedMoves =
        piece.potentialEmptyBoardMovesFrom(ChessSquare('d', 4));
        
        CHECK(!allowedMoves.contains(ChessSquare('f', 6)));
        CHECK(!allowedMoves.contains(ChessSquare('b', 2)));
        CHECK(!allowedMoves.contains(ChessSquare('f', 2)));
        CHECK(!allowedMoves.contains(ChessSquare('b', 6)));
    }
    
    SECTION("Kings inherit I_ChessPiece")
    {
        King piece(randomPieceAffiliation());
        I_ChessPiece* castedPiece = &piece;
        
        CHECK(castedPiece != nullptr);
    }
}

