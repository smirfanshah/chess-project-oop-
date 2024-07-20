#pragma once/
//#include"Chess.h"
#include"Position.h"
#include"bscs22117.h"
class Piece;
class Chess;
class Board//:public Piece
{
protected:
	Piece*** Ps; 
	int turn;
public:
	Board();
	Board(ifstream &rdr);
	void displayBoard();
	void naklidisplayBoard();
	void DrawBox(int r,int c,int clr);
	Piece* getPieceAt(int r,int c)const;
	Piece* SetPieceAt(Position F, Piece* p) const;
	int move(Position Sc, Position Dc);
	void updateundoboard();
	void updateredoboard();
	void queenpromote(Position Sc);
	void bishoppromote(Position Sc);
	void knightpromote(Position Sc);
	void rookpromote(Position Sc);
	void castling(Position Sc, Position Dc);
	void saveBoard(const string& filename);
	Position findking(const Board& b, Position Sc, Position Dc, int turn);
};

