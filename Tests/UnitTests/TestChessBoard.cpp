//
//  TestChessBoard.cpp
//  Chess
//
//  Created by Trevor Phillips on 2025-01-04.
//

#include "Catch.hpp"
#include "ChessBoard.hpp"
#include "ChessMove.hpp"
#include "InternalChessMove.hpp"

using namespace Chess;

TEST_CASE("Testing the ChessBoard object")
{
    SECTION("On a fresh board, can query whether a clear path exists, running vertically positive, open path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("c2c4");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == true);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running vertically positive, blocked path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("a1a3");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == false);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running vertically negative, open path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("a7a5");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == true);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running vertically negative, blocked path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("a8a6");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == false);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running horizontally positive, open path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("a3e3");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == true);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running horizontally positive, blocked path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("a1e1");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == false);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running horizontally negative, open path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("e3a3");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == true);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running horizontally negative, blocked path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("e1a1");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == false);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running diagonally, open path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("c2f5");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == true);
    }
    
    SECTION("On a fresh board, can query whether a clear path exists, running diagonally, blocked path")
    {
        ChessBoard board;
        board.resetBoard();
        ChessMove move;
        move.populateFromString("c1f4");
        CHECK(board.squaresBetweenEndPointsAreEmpty(move) == false);
    }
    
    SECTION("When the board is reset, the pieces in the 1st and 2nd ranks are all white")
    {
        ChessBoard board;
        board.resetBoard();
        
        for (int i = 0; i <= 7; i++)
        {
            CHECK(board.whitePieceExistsAt(ChessSquare(char('a' + i), 1)));
            CHECK(board.whitePieceExistsAt(ChessSquare(char('a' + i), 2)));
        }
    }
    
    SECTION("When the board is reset, the pieces in the 7th and 8th ranks are all black")
    {
        ChessBoard board;
        board.resetBoard();
        
        for (int i = 0; i <= 7; i++)
        {
            CHECK(board.blackPieceExistsAt(ChessSquare(char('a' + i), 7)));
            CHECK(board.blackPieceExistsAt(ChessSquare(char('a' + i), 8)));
        }
    }
    
    SECTION("When the board is reset, the white king is at e 1")
    {
        ChessBoard board;
        board.resetBoard();
        
        CHECK(1 == board.currentKingSquare(Chess::PieceAffiliation::WHITE_PIECE).rank());
        CHECK('e' == board.currentKingSquare(Chess::PieceAffiliation::WHITE_PIECE).file());
    }
    
    SECTION("When the board is reset, the black king is at e 8")
    {
        ChessBoard board;
        board.resetBoard();
        
        CHECK(8 == board.currentKingSquare(Chess::PieceAffiliation::BLACK_PIECE).rank());
        CHECK('e' == board.currentKingSquare(Chess::PieceAffiliation::BLACK_PIECE).file());
    }
    
    SECTION("Current king square will be updated as game progresses")
    {
        ChessBoard board;
        board.resetBoard();
        
        InternalChessMove pawnMove;
        pawnMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('e',2), PieceAffiliation::WHITE_PIECE, PieceType::PAWN));
        pawnMove.addValidMoveElement(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('e',4), PieceAffiliation::WHITE_PIECE, PieceType::PAWN));
        
        InternalChessMove kingMove;
        kingMove.addValidMoveElement(MoveElement(MoveElementAction::REMOVE_PIECE, ChessSquare('e',1), PieceAffiliation::WHITE_PIECE, PieceType::KING));
        kingMove.addValidMoveElement(MoveElement(MoveElementAction::PLACE_PIECE, ChessSquare('e',2), PieceAffiliation::WHITE_PIECE, PieceType::KING));
        
        board.applyMove(pawnMove);
        board.applyMove(kingMove);
        
        CHECK(2 == board.currentKingSquare(Chess::PieceAffiliation::WHITE_PIECE).rank());
        CHECK('e' == board.currentKingSquare(Chess::PieceAffiliation::WHITE_PIECE).file());
    }
}

