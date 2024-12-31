//
//  TestPieceMovementPersistsFeature.cpp
//  Chess
//
//  Created by Trevor Phillips on 2024-12-29.
//

#include "Catch.hpp"
#include "ChessEngine.hpp"
#include "ChessEngineTestHarness.hpp"
#include "CommandDefines.hpp"
#include "OutputErrorDefines.hpp"

using namespace std;
using namespace OutputErrorDefines;

TEST_CASE("Testing that a moved piece is now only seen at its new location")
{
    SECTION("White pawn locations will update")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a3", "c7c6", "a3a4"});

        testHarness.chessEngine().runChessEngine();

        CHECK(testHarness.isLastOutputBeforeQuittingEqualTo("Moving Pawn a3a4"));
    }
    
    SECTION("Cannot make the same move twice in a row")
    {
        ChessEngineTestHarness testHarness;
        testHarness.setInputSequenceWithinANewGame({"a2a3", "c7c6", "a2a3"});

        testHarness.chessEngine().runChessEngine();
        
        CHECK(testHarness.isLastOutputBeforeQuittingEqualTo(NO_PIECE_AT_COORDINATES_ERROR));
    }
}
