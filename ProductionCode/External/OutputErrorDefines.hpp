//
//  OutputErrorDefines.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-01-06.
//
//

#pragma once

namespace OutputErrorDefines
{
   static const char* MOVE_NOT_ON_BOARD_ERROR = "Move is not validly on the board.";
   static const char* NO_PIECE_AT_COORDINATES_ERROR = "No piece exists at these coordinates.";
   static const char* OPPOSING_PLAYERS_PIECE_ERROR = "Nice try, that's the other players piece!";
   static const char* PIECE_CANNOT_CURRENTLY_MOVE_ERROR =
      "This piece can't be moved to that square right now.";
   static const char* MOVE_IS_BLOCKED_ERROR = "There is a piece in the way, this move is not possible.";
static const char* PROMOTION_NOT_LEGAL = "Promotion not possible at this time.";
}
