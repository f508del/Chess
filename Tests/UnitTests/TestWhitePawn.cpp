//
//  TestPawn.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Catch.hpp"
#include "Pawn.hpp"
#include "ChessSquare.hpp"

using namespace std;

TEST_CASE("Testing the Pawn object when playing as white")
{
   SECTION("will allow one-step moves from starting position")
   {
      Pawn pawn(Chess::PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('a', 2));
      CHECK(allowedMoves.contains(ChessSquare('a', 3)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('b', 2));
      CHECK(allowedMoves.contains(ChessSquare('b', 3)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('h', 2));
      CHECK(allowedMoves.contains(ChessSquare('h', 3)));
   }

   SECTION("will allow two step moves from starting position")
   {
      Pawn pawn(Chess::PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('a', 2));
      CHECK(allowedMoves.contains(ChessSquare('a', 4)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('b', 2));
      CHECK(allowedMoves.contains(ChessSquare('b', 4)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('h', 2));
      CHECK(allowedMoves.contains(ChessSquare('h', 4)));
   }

   SECTION("will not allow two step moves from non-starting position")
   {
      Pawn pawn(Chess::PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('a', 3));
      CHECK(!allowedMoves.contains(ChessSquare('a', 5)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('d', 5));
      CHECK(!allowedMoves.contains(ChessSquare('d', 7)));
   }

   SECTION("will give no potential moves for invalid starting position")
   {
      Pawn pawn(Chess::PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('z', 3));
      CHECK(allowedMoves.empty());
   }

   SECTION("will give no potential moves for starting position at rank 1")
   {
      Pawn pawn(Chess::PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('c', 1));
      CHECK(allowedMoves.empty());
   }

   SECTION("will give no potential moves for starting position at rank 8")
   {
      Pawn pawn(Chess::PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('d', 8));
      CHECK(allowedMoves.empty());
   }
    
    SECTION("will not allow pawns to jump other pieces")
    {
        Pawn pawn(Chess::PieceAffiliation::WHITE_PIECE);
        CHECK(pawn.pieceCanJumpOtherPieces() == false);
    }
}
