#pragma once
#include"Piece.h"
#include"bscs22117.h"
#include"Bishop.h"
#include"Queen.h"
#include"Knight.h"
class Piece;
class Pawn :public Piece
{
private:
	Bishop B;
	Rook R;
	Queen Q;
	Knight K;
public:
	Pawn(int r, int c, Color C, Board* b);
	virtual void draw(int r, int c, Color _C);
	virtual bool legality(const Board &B,Position Sc, Position Dc, int Turn) override;
	virtual char sym(int Turn)override;
};

  