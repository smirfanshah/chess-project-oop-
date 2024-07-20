#include "Bishop.h"
#include"bscs22117.h"
#include"Piece.h"
#include<iostream>
using namespace std;
Bishop::Bishop(int r, int c, Color C, Board* b)
	:Piece(r, c, C, b)
{

}
void Print_bishop(float x, float y, float Scale, char Sym)
{
	Global::gotoRowCol(x, y);
	cout << Sym << endl;
	for (int i = 0; i < Scale; i++)
	{
		Global::gotoRowCol(x + 1, y + i - Scale + 2);
		cout << Sym << endl;
	}
	for (int i = 0; i < 2 * Scale - 1; i++)
	{
		Global::gotoRowCol(x + 2, y + i - Scale + 1);
		cout << Sym << endl;
	}
	for (int i = 0; i < Scale; i++)
	{
		Global::gotoRowCol(x + 3, y + i - Scale + 2);
		cout << Sym << endl;
	}
	Global::gotoRowCol(x + 4, y);
	cout << Sym << endl;
}

void Bishop::draw(int r, int c, Color _C)
{
	if (_C == WHITE)
	{
		p = 'b';
		Global::SetClr(4);
		{
			Print_bishop(r+1, c + 4, 3, -37);
		}
	}
	else if(_C==BLACK)
	{
		p = 'B';
		Global::SetClr(0);
		{
			Print_bishop(r+1, c + 4, 3, -37);
		}
	}

}
char Bishop::sym(int Turn)
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
bool Bishop::legality(const Board& b, Position Sc, Position Dc, int Turn)
{
	if (diagmove(Sc, Dc) && isdiagL2Rpc(b, Sc, Dc)
		|| diagmove(Sc, Dc) && isdiagR2Lpc(b, Sc, Dc))
	{
		return true;
	}

	return false;
}