#include "Rook.h"
#include"Piece.h"
#include"bscs22117.h"
#include<iostream>
using namespace std;

//void SetClr(int clr)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
//}
Rook::Rook(int r, int c, Color C, Board* b)
	:Piece(r, c, C, b)
{

}
void Print_rook(float x, float y, float Scale, char Sym)
{

	for (int i = 0; i < 3; i++)
	{
		Global::gotoRowCol(x, y + i - 1);
		cout << Sym << endl;
	}
	for (int i = 0; i < Scale + 1; i++)
	{
		Global::gotoRowCol(x + i - 1, y);
		cout << Sym << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		Global::gotoRowCol(x + 2, y + i - 1);
		cout << Sym << endl;
	}

	for (int i = 0; i < 3; i++)
	{
		Global::gotoRowCol(x + 3, y + i - 1);
		cout << Sym << endl;
	}

	for (int i = 0; i < 2 * Scale - 1; i++)
	{
		Global::gotoRowCol(x + 4, y + i - Scale + 1);
		cout << Sym << endl;
	}
}

char Rook::sym(int Turn)
{
	if (Turn == 0)
	{
		return 'r';
	}
	else if (Turn == 1)
	{
		return 'R';
	}
}
void Rook::draw(int r, int c, Color _C)
{
	if (_C == WHITE)
	{
		p = 'r';
		Global::SetClr(4);
		{
			Print_rook(r+2, c + 4, 3, -37);
		}
	}
	else
	{
		p = 'R';
		Global::SetClr(0);
		{
			Print_rook(r+2, c + 4, 3, -37);
		}
	}
}
//int sri, int sci, int dri, int dci
bool Rook::legality(const Board& b, Position Sc, Position Dc, int Turn)
{
	if ((Piece::ishorizpc(b, Sc, Dc) && Piece::horizmove(Sc, Dc))
		|| (Piece::isverticpc(b, Sc, Dc) && Piece::verticmove(Sc, Dc)))
	{
		return true;
	}
	else
		return false;
}