//
//  TestKnight.cpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-04.
//
//

#include "catch.hpp"
#include "Knight.hpp"
#include "ChessSquare.hpp"

using namespace std;

TEST_CASE("Testing the Knight object")
{
   SECTION("will allow knight L-moves that move towards higher files")
   {
      Knight knight;
      set<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('b', 4));
      CHECK(allowedMoves.find(ChessSquare('d', 5)) != allowedMoves.end());

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('b', 4));
      CHECK(allowedMoves.find(ChessSquare('d', 3)) != allowedMoves.end());
   }

   SECTION("will allow knight L-moves that move towards lower files")
   {
      Knight knight;
      set<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('g', 4));
      CHECK(allowedMoves.find(ChessSquare('e', 5)) != allowedMoves.end());

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('g', 4));
      CHECK(allowedMoves.find(ChessSquare('e', 3)) != allowedMoves.end());
   }

   SECTION("will allow knight L-moves that move towards higher ranks")
   {
      Knight knight;
      set<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('b', 4));
      CHECK(allowedMoves.find(ChessSquare('a', 6)) != allowedMoves.end());

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('b', 4));
      CHECK(allowedMoves.find(ChessSquare('c', 6)) != allowedMoves.end());
   }

   SECTION("will allow knight L-moves that move towards lower ranks")
   {
      Knight knight;
      set<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('c', 5));
      CHECK(allowedMoves.find(ChessSquare('b', 3)) != allowedMoves.end());

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('c', 5));
      CHECK(allowedMoves.find(ChessSquare('d', 3)) != allowedMoves.end());
   }

   SECTION("wont allow moves that take the knight off the board")
   {
      Knight knight;
      set<ChessSquare> allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('a', 5));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('h', 5));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('d', 1));
      CHECK(allowedMoves.size() == 4);

      allowedMoves = knight.potentialEmptyBoardMovesFrom(ChessSquare('d', 8));
      CHECK(allowedMoves.size() == 4);
   }
}
