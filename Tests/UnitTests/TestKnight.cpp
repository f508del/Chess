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
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('b', 4));
      CHECK(allowedMoves.contains(ChessSquare('d', 5)));

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('b', 4));
      CHECK(allowedMoves.contains(ChessSquare('d', 3)));
   }

   SECTION("will allow knight L-moves that move towards lower files")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('g', 4));
      CHECK(allowedMoves.contains(ChessSquare('e', 5)));

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('g', 4));
      CHECK(allowedMoves.contains(ChessSquare('e', 3)));
   }

   SECTION("will allow knight L-moves that move towards higher ranks")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('b', 4));
      CHECK(allowedMoves.contains(ChessSquare('a', 6)));

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('b', 4));
      CHECK(allowedMoves.contains(ChessSquare('c', 6)));
   }

   SECTION("will allow knight L-moves that move towards lower ranks")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('c', 5));
      CHECK(allowedMoves.contains(ChessSquare('b', 3)));

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('c', 5));
      CHECK(allowedMoves.contains(ChessSquare('d', 3)));
   }

   SECTION("wont allow moves that take the knight off the board")
   {
      Knight knight(randomPieceAffiliation());
      ExtendedSet<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('a', 5));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('h', 5));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('d', 1));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('d', 8));
      CHECK(allowedMoves.size() == 4);
   }
    
    SECTION("will allow knights to jump other pieces")
    {
        Knight knight(randomPieceAffiliation());
        CHECK(knight.pieceCanJumpOtherPieces() == true);
    }
}
