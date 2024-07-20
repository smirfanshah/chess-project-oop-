#include "Board.h"
#include <chrono>
#include<fstream>
#include"Piece.h"
#include<string>
#include"Pawn.h"
#include"Rook.h"
#include"King.h"
#include"Queen.h"
#include"Knight.h"
#include"Bishop.h"
#include"bscs22117.h"
#include"Chess.h"
#include"Position.h"
#include<vector>
#include<iostream>
using namespace std;

Board::Board()
{
	Ps = new Piece * *[8];
	for (int i = 0; i < 8; i++)
	{
		Ps[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			if (i == 1)
			{
				Ps[i][j] = new Pawn(i, j, WHITE, this);
			}
			else if (i == 6)
			{
				Ps[i][j] = new Pawn(i, j, BLACK, this);
			}
			else if (i == 0 &&(j==0 || j==7))
			{
				Ps[i][j] = new Rook(i, j, WHITE, this);
			}
			else if (i == 0 && (j == 1 || j == 6))
			{
				Ps[i][j] = new Knight(i, j, WHITE, this);
			}
			else if (i == 0 && (j == 2 || j == 5))
			{
				Ps[i][j] = new Bishop(i, j, WHITE, this);
			}
			else if (i == 0 && (j == 3 ))
			{
				Ps[i][j] = new Queen(i, j, WHITE, this);
			}
			else if (i == 0 && (j == 4))
			{
				Ps[i][j] = new King(i, j, WHITE, this);
			}
			else if (i == 7 && (j == 0 || j == 7))
			{
				Ps[i][j] = new Rook(i, j, BLACK, this);
			}
			else if (i == 7 && (j == 1 || j == 6))
			{
				Ps[i][j] = new Knight(i, j, BLACK, this);
			}
			else if (i == 7 && (j == 2 || j == 5))
			{
				Ps[i][j] = new Bishop(i, j, BLACK, this);
			}
			else if (i == 7 && (j == 3))
			{
				Ps[i][j] = new Queen(i, j, BLACK, this);
			}
			else if (i == 7 && (j == 4))
			{
				Ps[i][j] = new King(i, j, BLACK, this);
			}
			else
				Ps[i][j] = nullptr;
		}
	}	
}
Board::Board(ifstream &rdr)
{
	char sp;
	Ps = new Piece * *[8];
	for (int i = 0; i < 8; i++)
	{
		Ps[i] = new Piece * [8];
		for (int j = 0; j < 8; j++)
		{
			Position P{};
			P.ri = i, P.ci = j;
			rdr >> sp;
			switch (sp)
			{
			case'P':
				Ps[P.ri][P.ci] = new Pawn(i, j, WHITE, this);
				break;
			case'p':
				Ps[P.ri][P.ci] = new Pawn(i, j, BLACK, this);
				break;
			case'R':
				Ps[P.ri][P.ci] = new Rook(i, j, WHITE, this);
				break;
			case'N':
				Ps[P.ri][P.ci] = new Knight(i, j, WHITE, this);
				break;
			case'B':
				Ps[P.ri][P.ci] = new Bishop(i, j, WHITE, this);
				break;
			case'Q':
				Ps[i][j] = new Queen(i, j, WHITE, this);
				break;
			case 'K':
				Ps[i][j] = new King(i, j, WHITE, this);
				break;
			case'r':
				Ps[i][j] = new Rook(i, j, BLACK, this);
				break;
			case'n':
				Ps[i][j] = new Knight(i, j, BLACK, this);
				break;
			case'b':
				Ps[i][j] = new Bishop(i, j, BLACK, this);
				break;
			case'q':
				Ps[i][j] = new Queen(i, j, BLACK, this);
				break;
			case'k':
				Ps[i][j] = new King(i, j, BLACK, this);
				break;

			default:
				Ps[i][j] = nullptr;
				break;

			}
		}
	}
}

void Board::DrawBox(int sri,int sci,int clr)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			Global::SetClr(clr);
			Global::gotoRowCol(sri + r, sci + c);
			cout << char(-37);

		}
	}
	//Ps[sri][sci]->draw();
}
void Board::displayBoard() 
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				DrawBox(i * 8, j * 8, 8);
			}
			if ((i + j) % 2 != 0)
			{
				DrawBox(i * 8, j * 8, 15);

			}
			if (Ps[i][j] == nullptr)
			{
				Global::gotoRowCol(i *8 +5, j *8+4);
				cout << "";
			}
			if (Ps[i][j] != nullptr)
			{
				if (Ps[i][j]->getcolor() == WHITE)
				{
					Ps[i][j]->draw(i * 8, j * 8, WHITE);
				}
				else if(Ps[i][j]->getcolor() == BLACK)
					Ps[i][j]->draw(i * 8, j * 8, BLACK);
			}
		}
		cout << endl;
	}

}
void Board::naklidisplayBoard()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				DrawBox(i * 8, j * 8, 8);
			}
			if ((i + j) % 2 != 0)
			{
				DrawBox(i * 8, j * 8, 15);

			}
			if (Ps[i][j] == nullptr)
			{
				Global::gotoRowCol(i * 8 + 5, j * 8 + 4);
				cout << "";
			}
			if (Ps[i][j] != nullptr)
			{
				if (Ps[i][j]->getcolor() == WHITE)
				{
					Ps[i][j]->draw(i * 8, j * 8, WHITE);
				}
				else if (Ps[i][j]->getcolor() == BLACK)
					Ps[i][j]->draw(i * 8, j * 8, BLACK);
			}
		}
		cout << endl;
	}

}
void Board::castling(Position Sc, Position Dc)
{
	if (Ps[Dc.ri][Dc.ci]->p == 'R' || Ps[Dc.ri][Dc.ci]->p == 'r')
	{
		if (Dc.ci < 4)
		{
			Piece* piece = Ps[Sc.ri][Sc.ci];
			Ps[Sc.ri][Sc.ci - 1] = Ps[Dc.ri][Dc.ci];
			Ps[Dc.ri][Dc.ci + 2] = piece;
			Ps[Sc.ri][Sc.ci] = nullptr;
			Ps[Dc.ri][Dc.ci] = nullptr;
		}
		else
		{
			Piece* piece = Ps[Sc.ri][Sc.ci];
			Ps[Sc.ri][Sc.ci + 1] = Ps[Dc.ri][Dc.ci];
			Ps[Dc.ri][Dc.ci - 1] = piece;
			Ps[Sc.ri][Sc.ci] = nullptr;
			Ps[Dc.ri][Dc.ci] = nullptr;
		}
	}
}
void Board:: queenpromote(Position Sc)
{
	if (turn == 0)
	{
	/*	delete[] this->Ps[Sc.ri][Sc.ci];*/
		Ps[Sc.ri][Sc.ci] = nullptr;
		Ps[Sc.ri][Sc.ci] = new Queen(Sc.ri, Sc.ci, BLACK, this);
	}
	else
	{
		Ps[Sc.ri][Sc.ci] = nullptr;
		Ps[Sc.ri][Sc.ci] = new Queen(Sc.ri, Sc.ci, WHITE, this);

	}
}
void Board::bishoppromote(Position Sc)
{
	if (turn == 0)
	{
		Ps[Sc.ri][Sc.ci] = nullptr;
		Ps[Sc.ri][Sc.ci] = new Bishop(Sc.ri, Sc.ci, BLACK, this);
	}
	else
	{
		Ps[Sc.ri][Sc.ci] = nullptr;
		Ps[Sc.ri][Sc.ci] = new Bishop(Sc.ri, Sc.ci, WHITE, this);

	}
}
void Board::rookpromote(Position Sc)
{
	if (turn == 0)
	{
		Ps[Sc.ri][Sc.ci] = nullptr;
		Ps[Sc.ri][Sc.ci] = new Rook(Sc.ri, Sc.ci, BLACK, this);
	}
	else
	{
		Ps[Sc.ri][Sc.ci] = nullptr;
		Ps[Sc.ri][Sc.ci] = new Rook(Sc.ri, Sc.ci, WHITE, this);

	}
}
void Board::knightpromote(Position Sc)
{
	if (turn == 0)
	{
		Ps[Sc.ri][Sc.ci] = nullptr;
		Ps[Sc.ri][Sc.ci] = new Knight(Sc.ri, Sc.ci, BLACK, this);
	}
	else
	{
		Ps[Sc.ri][Sc.ci] = nullptr;
		Ps[Sc.ri][Sc.ci] = new Knight(Sc.ri, Sc.ci, WHITE, this);

	}
}

//void Board::saveBoard(const string& filename) {
//	ofstream outfile(filename);
//	if (outfile.is_open()) {
//		// Save whose turn it is to move
//		outfile << static_cast<int>(turn) << endl;
//
//		// Save the state of the board and the pieces
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) {
//				// Save the piece, or an empty cell marker if the cell is empty
//				if (Ps[i][j] == nullptr) {
//					outfile << " ";
//				}
//				else {
//					outfile << Ps[i][j]->toString();
//				}
//			}
//			outfile << endl;
//		}
//
//		outfile.close();
//		cout << "Board saved successfully.\n";
//	}
//	else {
//		cout << "Unable to open file.\n";
//	}
//}
//
//void Board::loadBoard(const string& filename) {
//	ifstream infile(filename);
//	if (infile.is_open()) {
//		// Load whose turn it is to move
//		int turn_int;
//		infile >> turn_int;
//		turn = static_cast<Color>(turn_int);
//
//		// Load the state of the board and the pieces
//		for (int i = 0; i < 8; i++) {
//			for (int j = 0; j < 8; j++) {
//				string piece_str;
//				infile >> piece_str;
//				if (piece_str == " ") {
//					Ps[i][j] = nullptr;
//				}
//				else {
//					Ps[i][j] = Piece::fromString(piece_str);
//				}
//			}
//		}
//
//		infile.close();
//		cout << "Board loaded successfully.\n";
//	}
//	else {
//		cout << "Unable to open file.\n";
//	}	
//}
vector<int> moveHistory;
vector<int> redoHistory;
int Board::move(Position Sc,Position Dc)
{
	auto moveStart = chrono::steady_clock::now();
	Piece* piece = Ps[Sc.ri][Sc.ci];
	Ps[Dc.ri][Dc.ci] = piece;
	Ps[Sc.ri][Sc.ci] = nullptr;
	moveHistory.push_back(Sc.ri);
	moveHistory.push_back(Sc.ci);
	moveHistory.push_back(Dc.ri);
	moveHistory.push_back(Dc.ci);
	redoHistory.clear();
	auto moveEnd = chrono::steady_clock::now();
	return chrono::duration_cast<chrono::milliseconds>(moveEnd - moveStart).count();
}
void Board::updateundoboard()
{
	if (moveHistory.empty()) {
		return;
	}
	int Dc_ci = moveHistory.back();
	moveHistory.pop_back();
	int Dc_ri = moveHistory.back();
	moveHistory.pop_back();
	int Sc_ci = moveHistory.back();
	moveHistory.pop_back();
	int Sc_ri = moveHistory.back();
	moveHistory.pop_back();

	Ps[Sc_ri][Sc_ci] = Ps[Dc_ri][Dc_ci];
	Ps[Dc_ri][Dc_ci] = nullptr;

	redoHistory.push_back(Sc_ri);
	redoHistory.push_back(Sc_ci);
	redoHistory.push_back(Dc_ri);
	redoHistory.push_back(Dc_ci);
}
void Board::updateredoboard()
{
	if (redoHistory.empty()) {
		return;
	}
	int Dc_ci = redoHistory.back();
	redoHistory.pop_back();
	int Dc_ri = redoHistory.back();
	redoHistory.pop_back();
	int Sc_ci = redoHistory.back();
	redoHistory.pop_back();
	int Sc_ri = redoHistory.back();
	redoHistory.pop_back();

	Piece* piece = Ps[Sc_ri][Sc_ci];
	Ps[Dc_ri][Dc_ci] = piece;
	Ps[Sc_ri][Sc_ci] = nullptr;

	moveHistory.push_back(Sc_ri);
	moveHistory.push_back(Sc_ci);
	moveHistory.push_back(Dc_ri);
	moveHistory.push_back(Dc_ci);
}
Piece* Board::getPieceAt(int r, int c) const
{
	return Ps[r][c];
}
Piece* Board::SetPieceAt(Position F, Piece* p)const
{
	return Ps[F.ri][F.ci] = p;
}
