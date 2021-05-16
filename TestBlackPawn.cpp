//
//  TestBlackPawn.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-05-15.
//
//

#include "catch.hpp"
#include "Pawn.hpp"
#include "ChessSquare.hpp"

using namespace std;

TEST_CASE("Testing the Pawn object when playing as black")
{
   SECTION("will allow one-step moves from starting position")
   {
   Pawn pawn(BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('a', 7));
   CHECK(allowedMoves.contains(ChessSquare('a', 6)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('b', 7));
   CHECK(allowedMoves.contains(ChessSquare('b', 6)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('h', 7));
   CHECK(allowedMoves.contains(ChessSquare('h', 6)));
   }

   SECTION("will allow two step moves from starting position")
   {
   Pawn pawn(BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('a', 7));
   CHECK(allowedMoves.contains(ChessSquare('a', 5)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('b', 7));
   CHECK(allowedMoves.contains(ChessSquare('b', 5)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('h', 7));
   CHECK(allowedMoves.contains(ChessSquare('h', 5)));
   }

   SECTION("will not allow two step moves from non-starting position")
   {
   Pawn pawn(BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('a', 6));
   CHECK(!allowedMoves.contains(ChessSquare('a', 4)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('d', 6));
   CHECK(!allowedMoves.contains(ChessSquare('d', 4)));
   }

   SECTION("will give no potential moves for invalid starting position")
   {
   Pawn pawn(BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('z', 3));
   CHECK(allowedMoves.empty());
   }

   SECTION("will give no potential moves for starting position at rank 1")
   {
   Pawn pawn(BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('c', 1));
   CHECK(allowedMoves.empty());
   }

   SECTION("will give no potential moves for starting position at rank 8")
   {
   Pawn pawn(BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('d', 8));
   CHECK(allowedMoves.empty());
   }

}
