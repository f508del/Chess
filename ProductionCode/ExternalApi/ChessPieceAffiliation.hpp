//
//  ChessPieceAffiliation.hpp
//  Chess
//
//  Created by Trevor Phillips on 2021-04-20.
//
//

#pragma once

namespace Chess
{
enum class PieceAffiliation
{
    WHITE_PIECE = 0,
    BLACK_PIECE
};

PieceAffiliation randomPieceAffiliation();
}
