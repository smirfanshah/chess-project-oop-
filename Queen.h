#pragma once
#include"Piece.h"
#include"Bishop.h"
#include"Rook.h"
#include"bscs22117.h"
class Piece;
class Queen :public Piece
{
private:
	Bishop B;
	Rook R;
public:
	Queen(int r, int c, Color C, Board* b);
	virtual void draw(int r, int c, Color _C);
	virtual bool legality(const Board& b, Position Sc, Position Dc,int Turn) override;
	virtual char sym(int Turn) override;
};
