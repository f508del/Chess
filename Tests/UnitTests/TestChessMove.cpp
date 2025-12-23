//
//  TestChessMove.cpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-26.
//
//

#include "Catch.hpp"
#include "ChessMoveRequest.hpp"

TEST_CASE("Testing the ChessMoveRequest object")
{
   SECTION("basic string parsing and validation")
   {
       ChessMoveRequest move;
       move.populateFromString("a1b2");
       CHECK(move.isOnTheBoard());

       ChessMoveRequest move2;
       move2.populateFromString("hello");
       CHECK(!move2.isOnTheBoard());
   }

   SECTION("will overwrite existing state when parsing from invalid string")
   {
       ChessMoveRequest move;
       move.populateFromString("a1a2");
       move.populateFromString("invalidString");
       CHECK(!move.isOnTheBoard());
   }
}
