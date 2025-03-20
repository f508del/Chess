//
//  ChessMoveValidator.hpp
//  Chess
//
//  Created by Trevor Phillips on 2020-12-30.
//
//

#pragma once
#include "ChessMoveValidity.hpp"

class ChessMove;
class ChessBoard;

class ChessMoveValidator
{
public:
    ChessMoveValidator(const ChessBoard& board);
    virtual ~ChessMoveValidator();

    Chess::MoveValidity validateMove(const ChessMove& currentMove);
    
    void ignorePlayerInitiative();
    void accountForPlayerInitiative();

private:
    const ChessBoard& board_;
    bool playerInitiativeIsApplicable_;
};
