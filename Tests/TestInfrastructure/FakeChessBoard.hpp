//
//  FakeChessBoard.hpp
//  Chess
//
//  Created by Trevor Phillips on 2025-12-19.
//

#include "I_ReadOnlyChessBoard.hpp"
#include <memory>
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
    std::unique_ptr<Bishop> whiteBishopCapabilities_;
    std::unique_ptr<King> whiteKingCapabilities_;
    std::unique_ptr<Knight> whiteKnightCapabilities_;
    std::unique_ptr<Pawn> whitePawnCapabilities_;
    std::unique_ptr<Queen> whiteQueenCapabilities_;
    std::unique_ptr<Rook> whiteRookCapabilities_;
    std::map<ChessSquare, const I_ChessPiece*> boardState_;
};
