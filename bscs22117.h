#ifndef bscs22117_h
#define bscs22117_h
enum Color
{
	BLACK, WHITE=15
};
//struct position
//{
//	int ri, ci;
//};
#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;
class Global
{
public:
	static void getRowColbyLeftClick(int& rpos, int& cpos);
	static void gotoRowCol(int rpos, int cpos);
	static void SetClr(int clr);

};

//class ChessBoard
//{
//	int rows;
//	int cols;
//	int dim;
//	int turn;
//};
//class Position
//{
//	int Src;
//	int Dst;
//};
//
#endif