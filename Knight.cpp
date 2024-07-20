#include "Knight.h"
#include"Piece.h"
#include<iostream>
using namespace std;
Knight::Knight(int r, int c, Color C, Board* b)
	:Piece(r, c, C, b)
{

}
void Print_knight(float x, float y, float Scale, char Sym)
{
	Global::gotoRowCol(x, y);
	cout << Sym << endl;
	for (int i = 0; i < Scale + 1; i++)
	{
		Global::gotoRowCol(x + 1, y + i - Scale + 2);
		cout << Sym << endl;
	}
	for (int i = 0; i < Scale - 1; i++)
	{
		Global::gotoRowCol(x + 2, y + i + 2);
		cout << Sym << endl;
	}
	for (int i = 0; i < Scale; i++)
	{
		Global::gotoRowCol(x + 2, y + i - Scale + 1);
		cout << Sym << endl;
	}
	for (int i = 0; i < Scale - 1; i++)
	{
		Global::gotoRowCol(x + 3, y + i - Scale + 2);
		cout << Sym << endl;
	}
	Global::gotoRowCol(x + 4, y);
	cout << Sym << endl;
	for (int i = 0; i < 2 * Scale - 1; i++)
	{
		Global::gotoRowCol(x + 5, y + i - Scale + 1);
		cout << Sym << endl;
	}
}

char Knight::sym(int Turn)
{
	if (Turn == 0)
	{
		return 'n';
	}
	else if (Turn == 1)
	{
		return 'N';
	}
}
void Knight::draw(int r, int c, Color _C)
{
	if (_C == WHITE)
	{
		p = 'n';
		Global::SetClr(4);
		{
			Print_knight(r+1, c + 3, 3, -37);
		}
	}
	else
	{
		p = 'N';
		Global::SetClr(0);
		{
			Print_knight(r+1, c + 3, 3, -37);
		}
	}
}
bool Knight::legality(const Board& b, Position Sc, Position Dc, int Turn)
{
	int dr = abs(Dc.ri - Sc.ri);
	int dc = abs(Dc.ci - Sc.ci);
	if ((dr == 2 && dc == 1)||(dr==1 && dc==2))
	{
		return true;
	}
	return false;
}