#include "Queen.h"
#include"Piece.h"
#include<iostream>
using namespace std;
Queen::Queen(int r, int c, Color C, Board* b)
	:Piece(r, c, C, b),B(r, c, C, b),R(r, c, C, b)
{

}
void Print_Queen(float x, float y, float Scale, char Sym)
{

	Global::gotoRowCol(x, y - Scale + 1);
	cout << Sym << endl;
	Global::gotoRowCol(x, y + Scale - 1);
	cout << Sym << endl;
	for (int i = 0; i < 2 * Scale - 1; i++)
	{
		Global::gotoRowCol(x + 1, y + i - Scale + 1);
		cout << Sym << endl;
	}
	for (int i = 0; i < Scale; i++)
	{
		Global::gotoRowCol(x + 2, y + i - 1);
		cout << Sym << endl;
	}
	for (int i = 0; i < Scale; i++)
	{
		Global::gotoRowCol(x + 3, y + i - 1);
		cout << Sym << endl;
	}
	for (int i = 0; i < 2 * Scale - 1; i++)
	{
		Global::gotoRowCol(x + 4, y + i - Scale + 1);
		cout << Sym << endl;
	}
	for (int i = 0; i < 2 * Scale + 1; i++)
	{
		Global::gotoRowCol(x + 5, y + i - Scale);
		cout << Sym << endl;
	}
}

char Queen::sym(int Turn)
{
	if (Turn == 0)
	{
		return 'b';
	}
	else if (Turn == 1)
	{
		return 'B';
	}
}
void Queen::draw(int r, int c, Color _C)
{
	if (_C == WHITE)
	{
		p = 'q';
		Global::SetClr(4);
		{
			Print_Queen(r+1, c + 4, 3, -37);
		}
	}
	else
	{
		p = 'Q';
		Global::SetClr(0);
		{
			Print_Queen(r+1, c + 4, 3, -37);
		}
	}
}
bool Queen::legality(const Board& b,Position Sc, Position Dc, int Turn)
{
	if (R.legality(b, Sc, Dc, C) || B.legality(b, Sc, Dc, C))
	{
		return true;
	}
	else
		return false;
}