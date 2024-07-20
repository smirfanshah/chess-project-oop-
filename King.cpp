#include "King.h"
#include"Piece.h"
#include"Rook.h"
#include"Bishop.h"
#include<iostream>
using namespace std;

King::King(int r, int c, Color C, Board* b)
	:Piece(r, c, C, b),R(r,c,C,b),B(r,c,C,b)
{

}
void Print_king(float x, float y, float Scale, char Sym)
{

	Global::gotoRowCol(x - 1, y + Scale);
	cout << Sym << endl;
	Global::gotoRowCol(x - 1, y - Scale);
	cout << Sym << endl;
	Global::gotoRowCol(x - 1, y);
	cout << Sym << endl;
	for (int i = 0; i < 2 * Scale + 1; i++)
	{
		Global::gotoRowCol(x, y + i - Scale);
		cout << Sym << endl;
	}
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

char King::sym(int Turn)
{
	if (Turn == 0)
	{
		return 'k';
	}
	else if (Turn == 1)
	{
		return 'K';
	}
}
void King::draw(int r,int c,Color _C)
{

	if (_C == WHITE)
	{
		p = 'k';
		Global::SetClr(4);
		{
			Print_king(r+1, c + 4, 3, -37);
		}
	}
	else
	{	
		p = 'K';
		Global::SetClr(0);
		{
			Print_king(r+1, c + 4, 3, -37);
		}
	}
}
//bool King::AmiKing()
//{
//	return true;
//}
bool King::legality(const Board& b, Position Sc, Position Dc, int Turn)
{
	return (abs(Dc.ri -Sc.ri) <= 1) && (abs(Dc.ci - Sc.ci) <= 1) && 
		(R.legality(b, Sc ,Dc,C) || B.legality(b, Sc, Dc,C));
	return false;

}
