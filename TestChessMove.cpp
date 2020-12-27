//
//  TestChessMove.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "catch.hpp"
#include "ChessMove.hpp"

TEST_CASE("Testing the ChessMove object")
{
   SECTION("basic string parsing and population")
   {
   ChessMove move;
   move.populateFromString("a1b2");
   CHECK(move.toString() == "a1b2");
   CHECK(move.isOnTheBoard());

   ChessMove move2;
   move2.populateFromString("hello");
   CHECK(!move2.isOnTheBoard());
   }

   SECTION("will overwrite existing state when parsing from invalid string")
   {
   ChessMove move;
   move.populateFromString("a1a2");
   move.populateFromString("invalidString");
   CHECK(!move.isOnTheBoard());
   }
}
