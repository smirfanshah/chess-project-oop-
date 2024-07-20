#pragma once
#include"Position.h"
#include"bscs22117.h"
class Board;
class Player;
class Piece;
class Chess:public Global
{
	int Turn;
	Position Sc;
	Position Dc;
	Color C;
	Player* Ps[2];
	Board* B;
	Piece* board[8][8];
public:
	Chess();
	Chess(ifstream &rdr);
	void play();
	void play2();
	void main();
	void displayTurnMsg(Player* A);
	void SelectPiece();
	void SelectDestination();
	bool ishorizpck2r(const Board& b, Position Sc, Position Dc, int turn);
	bool** chighlight(Player *A, const Board& b);
	bool validsourceSelection(Player* A, Position Sc);
	bool validDestinationSelection(Player *A,Position Dc);
	int Turnchange();
	int turnchange(int turn);
	Position findking(const Board& b,int turn);
	bool check(const Board& b,Position Sc,Position Dc,int turn);
	bool selfcheck(const Board& b,Position Sc,Position Dc,int turn);
	bool promotion(const Board& b,Position Sc, Position Dc);
	void setPieceAt(int row, int col, Piece* piece) {
		board[row][col] = piece;
	}
	void save(const Board& b, int turn);
};
