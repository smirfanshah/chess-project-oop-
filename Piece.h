#pragma once
#include"Position.h"
#include"Board.h"
#include"bscs22117.h"
class Board;	
class Piece
{
protected:
	int ri, ci;
	Color C;			
	Board* B;
	string name;
public:
	char p;
	Piece(int r, int c, Color _C,Board *B);
	virtual void draw(int r,int c,Color _C) = 0;
	virtual bool legality(const Board &b, Position Sc, Position Dc,int Turn)=0;
	virtual char sym(int Turn)=0;
	void move(int r, int c);
	bool horizmove(Position Sc,Position Dc);
	bool verticmove(Position Sc, Position Dc);
	bool diagmove(Position Sc, Position Dc);
	bool ishorizpc(const Board &b, Position Sc, Position Dc);
	bool isverticpc(const Board& b, Position Sc, Position Dc);
	bool isdiagL2Rpc(const Board& b, Position Sc, Position Dc);
	bool isdiagL2Rpckill(const Board& b, Position Sc, Position Dc);
	bool isdiagR2Lpckill(const Board& b, Position Sc, Position Dc);

	bool isdiagR2Lpc(const Board& b, Position Sc, Position Dc);
	
	string getname();
	Color getcolor();
	

};

