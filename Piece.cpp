#include "Piece.h"

#include <sstream>
#include"bscs22117.h"
#include<iostream>
using namespace std;
Piece::Piece(int r, int c, Color _C, Board* b)
{
	this->ri = r;
	this->ci = c;
	this->C = _C;
	this->B = b;
}
void Piece::move(int r, int c)
{
	this->ri = r;
	this->ci = c;

}	

bool Piece::horizmove(Position Sc, Position Dc)
{
	return Sc.ri == Dc.ri;
}
bool Piece::verticmove(Position Sc, Position Dc)
{
	return Sc.ci == Dc.ci;
}
bool Piece::diagmove(Position Sc, Position Dc)
{
	int dr = abs(Dc.ri - Sc.ri);
	int dc = abs(Dc.ci - Sc.ci);
	return dr == dc;

}
bool Piece::ishorizpc(const Board &b, Position Sc, Position Dc)
{
	int cs, ce;
	if (Sc.ci < Dc.ci)
	{
		cs = Sc.ci + 1;
		ce = Dc.ci - 1;
	}
	else
	{
		cs = Dc.ci + 1;
		ce = Sc.ci - 1;
	}
	for (int c = cs; c <= ce; c++)
	{
		if (b.getPieceAt(Sc.ri, c) != nullptr)
		{
			return false;
		}
	}
	return true;
}
bool Piece::isverticpc(const Board& b, Position Sc, Position Dc)
{
	int rs, re;
	if (Sc.ri < Dc.ri)
	{
		rs = Sc.ri;
		re = Dc.ri;
	}
	else
	{
		rs = Dc.ri;
		re = Sc.ri;
	}
	for (int r = rs + 1; r < re; r++)
	{
		if (b.getPieceAt(r,Sc.ci) != nullptr)
			return false;
	}
	return true;
}
bool Piece::isdiagL2Rpc(const Board& b, Position Sc, Position Dc)
{
	int dr;
	if (Sc.ri <Dc.ri)
	{
		dr = Dc.ri - Sc.ri - 1;
		for (int i = 1; i <= dr; i++)
		{
			if (b.getPieceAt(Sc.ri + i,Sc.ci + i) != nullptr)
				return false;
		}
	}
	else
	{
		for (int i = 1; i < Sc.ri - Dc.ri; i++)
		{
			if (b.getPieceAt(Sc.ri - i,Sc.ci + i) != nullptr)
				return false;
		}
	}
	return true;


}
bool Piece::isdiagR2Lpckill(const Board& b, Position Sc, Position Dc)
{
	if (Sc.ri < Dc.ri)
	{
		int dif = abs(Dc.ri - Sc.ri);
		for (int i = 1; i <= 2; i++)
		{
			if (b.getPieceAt(Sc.ri + i, Sc.ci - i) == nullptr)
				return false;
			if (b.getPieceAt(Sc.ri + i, Sc.ci - i) != nullptr)
				return true;

		}
	}
	else
	{
		int dif = abs(Sc.ri - Dc.ri);
		for (int i = 1; i <= 2; i++)
		{
			if (b.getPieceAt(Sc.ri - i, Sc.ci - i) == nullptr)
				return false;
			if (b.getPieceAt(Sc.ri - i, Sc.ci - i) != nullptr)
				return true;
		}
	}
	return false;
}
bool Piece::isdiagL2Rpckill(const Board& b, Position Sc, Position Dc)
{
	int dr;
	if (Sc.ri < Dc.ri)
	{
		dr = Dc.ri - Sc.ri - 1;
		for (int i = 1; i <= 2; i++)
		{
			if (b.getPieceAt(Sc.ri + i, Sc.ci + i) == nullptr)
				return false;
			if (b.getPieceAt(Sc.ri + i, Sc.ci + i) != nullptr)
				return true;

		}
	}
	else
	{
		for (int i = 1; i < 2; i++)
		{
			if (b.getPieceAt(Sc.ri - i, Sc.ci + i) == nullptr)
				return false;
			if (b.getPieceAt(Sc.ri - i, Sc.ci + i) != nullptr)
				return true;
		}
	}
	return false;


}
bool Piece::isdiagR2Lpc(const Board& b, Position Sc, Position Dc)
{
	if (Sc.ri < Dc.ri)
	{
		int dif = abs(Dc.ri - Sc.ri);
		for (int i = 1; i <= dif; i++)
		{
			if (b.getPieceAt(Sc.ri + i, Sc.ci - i) != nullptr)
				return false;
		}
	}
	else
	{
		int dif = abs(Sc.ri - Dc.ri);
		for (int i = 1; i <= dif; i++)
		{
			if (b.getPieceAt(Sc.ri - i, Sc.ci - i) != nullptr)
				return false;
		}
	}
	return true;
}


//bool Piece::AmiKing()
//{
//	return false;
//}
//string Piece::toString() const {
//  stringstream ss;
//  ss << C << "-" << p;
//  return ss.str();
//}
string Piece::getname()
{
	return this->name;
}
Color Piece::getcolor()
{
	return this->C;
}