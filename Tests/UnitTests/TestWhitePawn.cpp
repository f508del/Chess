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
using namespace Chess;

TEST_CASE("Testing the Pawn object when playing as white")
{
   SECTION("will allow one-step moves from starting position")
   {
      Pawn pawn(PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R2));
      CHECK(allowedMoves.contains(ChessSquare(File::A, Rank::R3)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::B, Rank::R2));
      CHECK(allowedMoves.contains(ChessSquare(File::B, Rank::R3)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::H, Rank::R2));
      CHECK(allowedMoves.contains(ChessSquare(File::H, Rank::R3)));
   }

   SECTION("will allow two step moves from starting position")
   {
      Pawn pawn(PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R2));
      CHECK(allowedMoves.contains(ChessSquare(File::A, Rank::R4)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::B, Rank::R2));
      CHECK(allowedMoves.contains(ChessSquare(File::B, Rank::R4)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::H, Rank::R2));
      CHECK(allowedMoves.contains(ChessSquare(File::H, Rank::R4)));
   }

   SECTION("will not allow two step moves from non-starting position")
   {
      Pawn pawn(PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R3));
      CHECK(!allowedMoves.contains(ChessSquare(File::A, Rank::R5)));

      allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R5));
      CHECK(!allowedMoves.contains(ChessSquare(File::D, Rank::R7)));
   }

   SECTION("will give no potential moves for invalid starting position")
   {
      Pawn pawn(PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('z', 3));
      CHECK(allowedMoves.empty());
   }

   SECTION("will give no potential moves for starting position at rank 1")
   {
      Pawn pawn(PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::C, Rank::R1));
      CHECK(allowedMoves.empty());
   }

   SECTION("will give no potential moves for starting position at rank 8")
   {
      Pawn pawn(PieceAffiliation::WHITE_PIECE);
      ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R8));
      CHECK(allowedMoves.empty());
   }
    
    SECTION("will not allow pawns to jump other pieces")
    {
        Pawn pawn(PieceAffiliation::WHITE_PIECE);
        CHECK(pawn.pieceCanJumpOtherPieces() == false);
    }
}
