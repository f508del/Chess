//
//  TestBlackPawn.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-05-15.
//
//

#include "Catch.hpp"
#include "Pawn.hpp"
#include "ChessSquare.hpp"

using namespace std;
using namespace Chess;

TEST_CASE("Testing the Pawn object when playing as black")
{
   SECTION("will allow one-step moves from starting position")
   {
   Pawn pawn(PieceAffiliation::BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R7));
   CHECK(allowedMoves.contains(ChessSquare(File::A, Rank::R6)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::B, Rank::R7));
   CHECK(allowedMoves.contains(ChessSquare(File::B, Rank::R6)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::H, Rank::R7));
   CHECK(allowedMoves.contains(ChessSquare(File::H, Rank::R6)));
   }

   SECTION("will allow two step moves from starting position")
   {
   Pawn pawn(PieceAffiliation::BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R7));
   CHECK(allowedMoves.contains(ChessSquare(File::A, Rank::R5)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::B, Rank::R7));
   CHECK(allowedMoves.contains(ChessSquare(File::B, Rank::R5)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::H, Rank::R7));
   CHECK(allowedMoves.contains(ChessSquare(File::H, Rank::R5)));
   }

   SECTION("will not allow two step moves from non-starting position")
   {
   Pawn pawn(PieceAffiliation::BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R6));
   CHECK(!allowedMoves.contains(ChessSquare(File::A, Rank::R4)));

   allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R6));
   CHECK(!allowedMoves.contains(ChessSquare(File::D, Rank::R4)));
   }

   SECTION("will give no potential moves for invalid starting position")
   {
   Pawn pawn(PieceAffiliation::BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare('z', 3));
   CHECK(allowedMoves.empty());
   }

   SECTION("will give no potential moves for starting position at rank 1")
   {
   Pawn pawn(PieceAffiliation::BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::C, Rank::R1));
   CHECK(allowedMoves.empty());
   }

   SECTION("will give no potential moves for starting position at rank 8")
   {
   Pawn pawn(PieceAffiliation::BLACK_PIECE);
   ExtendedSet<ChessSquare> allowedMoves = pawn.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R8));
   CHECK(allowedMoves.empty());
   }

    SECTION("will not allow pawns to jump other pieces")
    {
        Pawn pawn(PieceAffiliation::BLACK_PIECE);
        CHECK(pawn.pieceCanJumpOtherPieces() == false);
    }
}
