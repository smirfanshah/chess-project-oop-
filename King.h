#pragma once
#include"Piece.h"
#include"Bishop.h"
#include"Rook.h"
#include"bscs22117.h"
class Piece;
class King :public Piece
{
private:
	Rook R;
	Bishop B;
public:
	King(int r, int c, Color C, Board* b);
	virtual void draw(int r, int c, Color _C);
	virtual bool legality(const Board& b, Position Sc, Position Dc, int Turn) override;
	//virtual bool AmiKing();
	virtual char sym(int Turn)override;
};
