#pragma once
#include"Piece.h"
#include"bscs22117.h"
class Piece;
class Rook :public Piece
{
public:
	Rook(int r, int c, Color C, Board* b);
	virtual void draw(int r, int c, Color _C);
	virtual bool legality(const Board& b, Position Sc, Position Dc,int Turn) override;
	virtual char sym(int Turn)override;
};

