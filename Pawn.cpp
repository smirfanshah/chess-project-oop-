#include "Pawn.h"
#include"Piece.h"
#include"Rook.h"
#include<iostream>
using namespace std;
Pawn::Pawn(int r, int c, Color C, Board* b)
	:Piece(r,c,C,b),R(r, c, C, b),B(r, c, C, b),Q(r, c, C, b),K(r, c, C, b)
{

}
void pawn(float x, float y,float Scale,char Sym)
{
	Global::gotoRowCol(x + 1, y);
	cout << Sym << endl;
	for (int i = 0; i < 3; i++)
	{
		Global::gotoRowCol(x + 3, y + i - 1);
		cout << Sym << endl;
	}
	for (float i = 0; i < 2 * Scale + 1; i++)
	{
		Global::gotoRowCol(x + Scale, y + i - Scale);
		cout << Sym;
	}
	for (int i = 0; i < 3 * Scale + 1; i++)
	{
		Global::gotoRowCol(x + 4, y + i - Scale - 1);
		cout << Sym << endl;
	}
}

char Pawn::sym(int Turn)
{
	if (Turn == 0)
	{
		return 'p';
	}
	else if (Turn == 1)
	{
		return 'P';
	}
}
void Pawn::draw(int r, int c, Color _C)
{
	p = 'p';
	if (_C == WHITE)
	{
		Global::SetClr(4);
		{
			pawn(r, c + 3, 2, -37);
		}
	}
	else
	{
		Global::SetClr(0);
		{
			pawn(r, c + 3, 2, -37);
		}
	}
	/*Global::gotoRowCol(r + 4, c + 4);
	cout << (_C == WHITE ? 'P' : 'p');*/
	//	}
}bool Pawn::legality(const Board& b, Position Sc, Position Dc, int Turn)
{
	if (Turn == 1)
	{
		int diff = abs(Dc.ri - Sc.ri);
		if (Sc.ri == 1)
		{
			if ((verticmove(Sc, Dc) && isverticpc(b, Sc, Dc) && diff <= 2 && Sc.ri < Dc.ri) ||
				(diagmove(Sc, Dc)&&(isdiagL2Rpckill(b,Sc,Dc)|| isdiagR2Lpckill(b, Sc, Dc))&& diff == 1 && Sc.ri < Dc.ri && abs(Sc.ci - Dc.ci) == 1))
			{
				return true;
			}
		}
		else if ((verticmove(Sc, Dc) && isverticpc(b, Sc, Dc) && diff == 1 && Sc.ri < Dc.ri) ||
			(diagmove(Sc, Dc) && (isdiagL2Rpckill(b, Sc, Dc) || isdiagR2Lpckill(b, Sc, Dc)) && diff == 1 && Sc.ri < Dc.ri && abs(Sc.ci - Dc.ci) == 1))
		{
			return true;
		}
	}
	else
	{
		int diff1 = abs(Dc.ri - Sc.ri);
		if (Sc.ri == 6)
		{
			if ((verticmove(Sc, Dc) && isverticpc(b, Sc, Dc) && diff1 <= 2 && Sc.ri > Dc.ri) ||
				(diagmove(Sc, Dc) && (isdiagL2Rpckill(b, Sc, Dc) || isdiagR2Lpckill(b, Sc, Dc)) && diff1 == 1 && Sc.ri > Dc.ri && abs(Sc.ci - Dc.ci) == 1))
			{
				return true;
			}
		}
		else if ((verticmove(Sc, Dc) && isverticpc(b, Sc, Dc) && diff1 == 1 && Sc.ri > Dc.ri) ||
			(diagmove(Sc, Dc) && (isdiagL2Rpckill(b, Sc, Dc) || isdiagR2Lpckill(b, Sc, Dc)) && diff1 == 1 && Sc.ri > Dc.ri && abs(Sc.ci - Dc.ci) == 1))
		{
			return true;
		}
	}
	return false;
}
