//
//  FakeChessBoard.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-12-19.
//

#include "I_ReadOnlyChessBoard.hpp"
#include "ScopedPointer.hpp"
#include <map>

class Bishop;
class ChessSquare;
class I_ChessPiece;
class King;
class Knight;
class Pawn;
class Queen;
class Rook;

class FakeChessBoard : public I_ReadOnlyChessBoard
{
public:
    FakeChessBoard();
    virtual ~FakeChessBoard();
    
    // Inherited
    bool anyPieceExistsAt(const ChessSquare& square) const override;
    const I_ChessPiece* pieceAt(const ChessSquare& square) const override;
    
    // helpers
    void placeBishopAtSquare(const ChessSquare& square);
    void placeKingAtSquare(const ChessSquare& square);
    void placeKnightAtSquare(const ChessSquare& square);
    void placePawnAtSquare(const ChessSquare& square);
    void placeQueenAtSquare(const ChessSquare& square);
    void placeRookAtSquare(const ChessSquare& square);
    
private:
    ScopedPointer<Bishop> whiteBishopCapabilities_;
    ScopedPointer<King> whiteKingCapabilities_;
    ScopedPointer<Knight> whiteKnightCapabilities_;
    ScopedPointer<Pawn> whitePawnCapabilities_;
    ScopedPointer<Queen> whiteQueenCapabilities_;
    ScopedPointer<Rook> whiteRookCapabilities_;
    std::map<ChessSquare, const I_ChessPiece*> boardState_;
};
