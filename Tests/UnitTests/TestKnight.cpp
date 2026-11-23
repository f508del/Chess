//
//  TestKnight.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "Catch.hpp"
#include "Knight.hpp"
#include "ChessSquare.hpp"

using namespace std;
using namespace Chess;

TEST_CASE("Testing the Knight object")
{
   SECTION("will allow knight L-moves that move towards higher files")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::B, Rank::R4));
      CHECK(allowedMoves.contains(ChessSquare(File::D, Rank::R5)));

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::B, Rank::R4));
       CHECK(allowedMoves.contains(ChessSquare(File::D, Rank::R3)));
   }

   SECTION("will allow knight L-moves that move towards lower files")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::G, Rank::R4));
      CHECK(allowedMoves.contains(ChessSquare(File::E, Rank::R5)));

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::G, Rank::R4));
      CHECK(allowedMoves.contains(ChessSquare(File::E, Rank::R3)));
   }

   SECTION("will allow knight L-moves that move towards higher ranks")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::B, Rank::R4));
      CHECK(allowedMoves.contains(ChessSquare(File::A, Rank::R6)));

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::B, Rank::R4));
      CHECK(allowedMoves.contains(ChessSquare(File::C, Rank::R6)));
   }

   SECTION("will allow knight L-moves that move towards lower ranks")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::C, Rank::R5));
      CHECK(allowedMoves.contains(ChessSquare(File::B, Rank::R3)));

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::C, Rank::R5));
      CHECK(allowedMoves.contains(ChessSquare(File::D, Rank::R3)));
   }

   SECTION("wont allow moves that take the knight off the board")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::A, Rank::R5));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::H, Rank::R5));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R1));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare(File::D, Rank::R8));
      CHECK(allowedMoves.size() == 4);
   }
    
    SECTION("will allow knights to jump other pieces")
    {
        Knight knight(randomPieceAffiliation());
        CHECK(knight.pieceCanJumpOtherPieces() == true);
    }
}
