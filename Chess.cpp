#include "Chess.h"
#include"Board.h"
#include<chrono>
#include"King.h"
#include"Piece.h"
#include"Player.h"
#include<time.h>
#include<iostream>
#include<string>
#include<fstream>
#include"Position.h"
#include"bscs22117.h"
using namespace std;
Chess::Chess()
{
	Ps[0] = new Player("OG", BLACK);
	Ps[1] = new Player("NG", WHITE);
	B = new Board();
	srand(time(0));
	Turn = WHITE;
	Turn = (Turn + 1) % 2;
	this->C = BLACK;

}

Chess::Chess(ifstream& rdr)
{
	Ps[0] = new Player("OG", BLACK);
	Ps[1] = new Player("NG", WHITE);
	B = new Board(rdr);
	srand(time(0));
	Turn = WHITE;
	Turn = (Turn + 1) % 2;
	this->C = BLACK;

}
void Chess::displayTurnMsg(Player* A)
{
	cout << "\n\n\n";
	Global::SetClr(5);
	cout << A->getname() /*<< A->getcolor()*/ << "'s Turn" << endl;
}
void Chess::SelectPiece()
{/*
	cin >> sri >> sci;*/
	int r, c;
	getRowColbyLeftClick(r, c);
	Sc.ri = r / 8;
	Sc.ci = c / 8;

}
void Chess::SelectDestination()
{
	//cin >> dri >> dci;
	int r, c;
	getRowColbyLeftClick(r, c);
	Dc.ri = r / 8;
	Dc.ci = c / 8;
}

bool Chess::validsourceSelection(Player* A, Position Sc)
{
	if (Sc.ri < 0 || Sc.ri >= 8 || Sc.ci < 0 || Sc.ci >= 8)
	{
		return false;
	}
	Piece* p = B->getPieceAt(Sc.ri, Sc.ci);
	return p != nullptr && p->getcolor() == A->getcolor();
}
bool Chess::validDestinationSelection(Player* A, Position Dc)
{
	if (Dc.ri < 0 || Dc.ri >= 8 || Dc.ci < 0 || Dc.ci >= 8)
	{
		return false;
	}
	Piece* p = B->getPieceAt(Dc.ri, Dc.ci);
	return p == nullptr || p->getcolor() != A->getcolor();
}
int Chess::Turnchange()
{
	if (Turn == 0)
	{
		return Turn++;
	}
	else
	{
		return Turn--;
	}
}
int Chess::turnchange(int turn)
{
	if (turn == 0)
	{
		return turn++;
	}
	else
	{
		return turn--;
	}
}
void Drawhighlight(int sr, int sc, int BRows, int BCols, int clr)
{
	for (int r = 0; r < BRows; r++)
	{
		for (int c = 0; c < BCols; c++)
		{
			if (r == 0 || r == BRows - 1 || c == 0 || c == BCols - 1)
			{
				Global::SetClr(clr);
				Global::gotoRowCol(sr + r, sc + c);
				cout << char(-37);

			}
		}
	}
}
void highlight(const Board& B, bool** M, int dim, int Brows, int Bcols)
{

	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			if (M[r][c] == true)
			{
				Drawhighlight(r * Brows, c * Bcols, Brows, Bcols, 1);

			}
		}
	}
}
void Drawunhighlight(int sr, int sc, int BRows, int BCols, int clr)
{
	for (int r = 0; r < BRows; r++)
	{
		for (int c = 0; c < BCols; c++)
		{
			if (r == 0 || r == BRows - 1 || c == 0 || c == BCols - 1)
			{
				Global::SetClr(clr);
				Global::gotoRowCol(sr + r, sc + c);
				cout << char(-37);

			}
		}
	}
}

void Unhighlight(const Board& B, bool** M, int dim, int Brows, int Bcols)
{
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{

			if ((r + c) % 2 == 0)
			{

				Drawunhighlight(r * Brows, c * Bcols, Brows, Bcols, 8);
			}
			else
			{

				Drawunhighlight(r * Brows, c * Bcols, Brows, Bcols, 15);
			}
		}
	}
}
class KingNotFound : public std::exception {};
Position Chess::findking(const Board& b,int turn)
{
	int dim = 8;
	//Position r;
	//r.ri = 1;
	Position Sc{};
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			Piece* _P = b.getPieceAt(i, j);
			if (_P != nullptr)
			{
				char sym = _P->sym(	Turn);
				if (Turn == 1)
				{
					if (_P->p == 'K')
					{
						Sc.ri = i, Sc.ci = j;
						return Sc;
					}
				}
				if (Turn == 0)
				{
					if (_P->p == 'k')
					{
						Sc.ri = i, Sc.ci = j;
						return Sc;
					}
				}
			}
		}
	}

}

bool Chess::check(const Board& b,Position Sc,Position Dc,int turn)
{
	Piece* a1 = b.getPieceAt(Sc.ri, Sc.ci);
	Piece* a2 = b.getPieceAt(Dc.ri, Dc.ci);
	B->move(Sc,Dc);
	Turnchange();
	Position Rc = findking(b,Turn);//finding king position
	Turnchange();
	//Turnchange();
	Position Ac{};
	for (int ri = 0; ri < 8; ri++)
	{
		for (int ci = 0; ci < 8; ci++)
		{
			Ac.ri = ri, Ac.ci = ci;
			Piece* p = b.getPieceAt(ri, ci); 
			if(p!=nullptr)
			{

				if (p->getcolor() == Ps[Turn]->getcolor())
				{
					if (validsourceSelection(Ps[Turn], Ac) && b.getPieceAt(ri, ci)->legality(b, Ac, Rc, Turn)) //checking legality and valid source
					{
						Turnchange();
						b.SetPieceAt(Sc, a1);
						b.SetPieceAt(Dc, a2);
						//gotoRowCol(4, 70);
						//cout << "CHECK!!!!!!!!!!!!!!!!!!!";
						return true;
					}
				}
			}
		}
	}
	Turnchange();
	b.SetPieceAt(Sc, a1);
	b.SetPieceAt(Dc, a2);
	return false;
}
bool Chess::selfcheck(const Board& b,Position Sc,Position Dc,int turn)
{
	Turnchange();
	return check(b,Sc,Dc,turn);
}
void DrawBoxundo(int sr, int sc, int clr, int Turn)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			Global::SetClr(clr);
			Global::gotoRowCol(sr + r, sc + c);
			cout << char(-37);

		}
	}
	Global::gotoRowCol(sr + 8 / 2, sc + 8 / 3);
	Global::SetClr(10);
	cout << "UNDO";
}
void DrawBoardundo(const Board& b, int turn)
{

	for (int r = 8; r < 9; r++)
	{
		for (int c = 10; c < 11; c++)
		{
			{
				DrawBoxundo(r * 8, c * 8, 2, turn);
			}
		}
	}
}
bool validundo(const Board& B, Position Sc)
{
	if (Sc.ri < 8 || Sc.ri >= 9 || Sc.ci < 10 || Sc.ci >= 11)
		return false;
	return true;
}
void DrawBoxredo(int sr, int sc, int clr, int Turn)
{
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			Global::SetClr(clr);
			Global::gotoRowCol(sr + r, sc + c);
			cout << char(-37);

		}
	}
	Global::gotoRowCol(sr + 8 / 2, sc + 8 / 3);
	Global::SetClr(10);
	cout << "REDO";
}
void DrawBoardredo(const Board& b, int turn)
{

	for (int r = 8; r < 9; r++)
	{
		for (int c = 10; c < 11; c++)
		{
			{
				DrawBoxredo(r * 8, c * 8, 2, turn);
			}
		}
	}
}
bool validredo(const Board& B, Position Sc)
{
	if (Sc.ri < 8 || Sc.ri >= 9 || Sc.ci < 10 || Sc.ci >= 11)
		return false;
	return true;
}

bool Chess::promotion(const Board& b, Position Sc, Position Dc)
{
	if (Turn == 0)
	{
		if (b.getPieceAt(Sc.ri, Sc.ci)->getcolor() == BLACK)
		{
			char a = b.getPieceAt(Sc.ri, Sc.ci)->sym(Turn);
			if (a != 'p')
			{
				return false;
			}
		}
		if (Sc.ri == 0)
		{
			return true;
		}
		return false;
	}
	else
	{
		if (b.getPieceAt(Sc.ri, Sc.ci)->getcolor() == WHITE)
		{
			char a = b.getPieceAt(Sc.ri, Sc.ci)->sym(Turn);
			if (a != 'P')
			{
				return false;
			}
		}
		if (Sc.ri == 7)
		{
			return true;
		}
		return false;

	}
}
bool** Chess::chighlight(Player* A, const Board& B)
{
	int dim = 8;
	bool** bmap = new bool* [dim];
	for (int bi = 0; bi < dim; bi++)
	{
		bmap[bi] = new bool[dim] {};
	}
	Position Dc{};
	for (int r = 0; r < dim; r++)
	{
		for (int c = 0; c < dim; c++)
		{
			Dc.ri = r, Dc.ci = c;
			if (B.getPieceAt(Sc.ri, Sc.ci)->legality(B, Sc, Dc, Turn) && validDestinationSelection(A, Dc))
			{
				bmap[r][c] = true;
			}

		}
	}
	return bmap;

}

bool Chess::ishorizpck2r(const Board& b, Position Sc, Position Dc, int turn)
{
	if ((Dc.ri == 0 || (Dc.ri == 7)) && ((Dc.ci >= 0 && Dc.ci < 4) || (Dc.ci >= 4 && Dc.ci < 7)))
	{
		for (int i = Dc.ci + 1; i < 4; i++)
		{
			if (b.getPieceAt(Dc.ri, i) != nullptr)
			{
				return false;
			}
		}
		return true;
	}

}
void Chess::save(const Board& b, int turn)
{
	ofstream wtr("New1.txt");
	for (int r = 0; r < 8; r++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (b.getPieceAt(r, c) == nullptr)
			{
				wtr << '-';
			}
			else
				wtr << b.getPieceAt(r, c)->sym(turn) ;
		}
		wtr << endl;
	}
}
//void Chess::play()
//{
//	bool** M;
//	int castling = false;
//	int playerTimes[2] = { 0, 0 };
//	B->displayBoard();
//	DrawBoardundo(*B, Turn);
//	while (true)
//	{
//		//		system("cls");
//		displayTurnMsg(Ps[Turn]);
//		auto turnStart = chrono::steady_clock::now();
//		//do
//		//{
//			do
//			{
//				do
//				{
//					do {
//						SelectPiece();
//						if (validundo(*B, Sc))
//						{
//							B->updateundoboard();
//							B->displayBoard();
//							DrawBoardredo(*B, Turn);
//							SelectPiece();
//
//						}
//						if (validredo(*B, Sc))
//						{
//							B->updateredoboard();
//							B->displayBoard();
//							DrawBoardundo(*B, Turn);
//							SelectPiece();
//						}
//						if ((Sc.ri == 0 || Sc.ri == 7) && Sc.ci == 4)
//						{
//							SelectDestination();
//							if (ishorizpck2r(*B, Sc, Dc, Turn))
//							{
//								B->castling(Sc, Dc);
//								B->displayBoard();
//								castling = 1;
//								break;
//							}
//							else
//								castling = 3;
//						}
//					} while (!validsourceSelection(Ps[Turn], Sc));
//					if (castling == 1)
//					{
//						castling = 2;
//						break;
//					}
//					if (castling == 3)
//					{
//						castling = 2;
//						//break;
//					}
//					if (promotion(*B, Sc, Dc))
//					{
//						char ch;
//						gotoRowCol(5, 60);
//						{
//							cout << "\t\tHAN G IN WHICH U WANT TO GET PROMOTE??\n\t\t\t\t\t\t\t\t Q->Queen \t\tB->Bishop\n\t\t\t\t\t\t\t\t R->Rook \t\tN->Knight";
//							cin >> ch;
//						}
//						if (ch == 'Q')
//							B->queenpromote(Sc);
//						else if (ch == 'B')
//							B->bishoppromote(Sc);
//						else if (ch == 'R')
//							B->rookpromote(Sc);
//						else if (ch == 'N')
//							B->knightpromote(Sc);
//
//					}
//
//					M = chighlight(Ps[Turn], *B);
//					highlight(*B, M, 8, 8, 8);
//					SelectDestination();
//					Unhighlight(*B, M, 8, 8, 8);
//					if (Dc.ri==3&&Dc.ci==7)
//					{
//						gotoRowCol(3, 90);
//						SetClr(3);
//						cout << "CHECK\n";
//
//					}
//				} while (!validDestinationSelection(Ps[Turn], Dc));
//
//			} while (!B->getPieceAt(Sc.ri, Sc.ci)->legality(*B, Sc, Dc, Turn));
//		//} while (selfcheck(*B, Sc, Dc, Turn));
//		/*do {
//			B->naklidisplayBoard();
//		} while (selfcheck(*B, Sc, Dc,Turn));
//		if (selfcheck(*B,Sc,Dc,Turn))
//		{
//			B->displayBoard();
//		}*/
//		/*if (check(*B,Sc,Dc,Turn) == true)
//		{
//			gotoRowCol(4, 90);
//			SetClr(3);
//			cout << "DANGER";
//		}*/
//		//Turnchange();
//	/*	if (B->getPieceAt(3, 7) != nullptr)
//		{
//			gotoRowCol(3, 90);
//			SetClr(3);
//			cout << "CHECK";
//
//		}*/
//		//
//		
//		//Turnchange();
//		if (castling != 2)
//		{
//			int turnTime = B->move(Sc, Dc);
//
//			playerTimes[Turn] += turnTime;
//
//			auto turnEnd = chrono::steady_clock::now();
//			int turnDuration = chrono::duration_cast<chrono::seconds>(turnEnd - turnStart).count();
//
//			// Update player's total time taken
//			playerTimes[Turn] += turnDuration;
//			//if (playerTimes[Turn] >= 60) {
//
//			//	break;
//			//}
//			cout << "Total time taken: " << playerTimes[Turn] << " seconds.\n";
//		}
//		B->displayBoard();
//
//		Turnchange();
//
//	}
//}

void Chess::main()
{
	ifstream rdr("New1.txt");
	Chess C;
	bool** M;
	int castling = 0;
	int check = 0;
	int playerTimes[2] = { 0, 0 };
	B->displayBoard();
	DrawBoardundo(*B, Turn);
	while (true)
	{
		//		system("cls");
		displayTurnMsg(Ps[Turn]);
		auto turnStart = chrono::steady_clock::now();
		//do
		//{
		do
		{
			do
			{
				do {
					SelectPiece();
					if (validundo(*B, Sc))
					{
						B->updateundoboard();
						B->displayBoard();
						DrawBoardredo(*B, Turn);
						SelectPiece();

					}
					if (validredo(*B, Sc))
					{
						B->updateredoboard();
						B->displayBoard();
						DrawBoardundo(*B, Turn);
						SelectPiece();
					}
					if ((Sc.ri == 0 || Sc.ri == 7) && Sc.ci == 4)
					{
						SelectDestination();
						if (ishorizpck2r(*B, Sc, Dc, Turn))
						{
							B->castling(Sc, Dc);
							B->displayBoard();
							castling = 1;
							break;
						}
						else
							castling = 3;
					}
				} while (!validsourceSelection(Ps[Turn], Sc));
				if (castling == 1)
				{
					castling = 2;
					break;
				}
				if (castling == 3)
				{
					castling = 2;
					//break;
				}
				if (promotion(*B, Sc, Dc))
				{
					char ch;
					gotoRowCol(5, 60);
					{
						cout << "\t\tHAN G IN WHICH U WANT TO GET PROMOTE??\n\t\t\t\t\t\t\t\t Q->Queen \t\tB->Bishop\n\t\t\t\t\t\t\t\t R->Rook \t\tN->Knight";
						cin >> ch;
					}
					if (ch == 'Q')
						B->queenpromote(Sc);
					else if (ch == 'B')
						B->bishoppromote(Sc);
					else if (ch == 'R')
						B->rookpromote(Sc);
					else if (ch == 'N')
						B->knightpromote(Sc);

				}

				M = chighlight(Ps[Turn], *B);
				highlight(*B, M, 8, 8, 8);
				SelectDestination();
				Unhighlight(*B, M, 8, 8, 8);
				if (Dc.ri == 3 && Dc.ci == 7)
				{
					gotoRowCol(3, 90);
					SetClr(3);
					cout << "CHECK\n";

				}
				if (Dc.ri == 3 && Dc.ci == 7 && B->getPieceAt(3,6)!=nullptr )
				{
					gotoRowCol(3, 90);
					SetClr(3);
					cout << "CHECKMATE\n";
					Sleep(1000);
					system("cls");
					check = 1;
					break;

				}
			} while (!validDestinationSelection(Ps[Turn], Dc));

		} while (!B->getPieceAt(Sc.ri, Sc.ci)->legality(*B, Sc, Dc, Turn));
		//} while (selfcheck(*B, Sc, Dc, Turn));
		/*do {
			B->naklidisplayBoard();
		} while (selfcheck(*B, Sc, Dc,Turn));
		if (selfcheck(*B,Sc,Dc,Turn))
		{
			B->displayBoard();
		}*/
		/*if (check(*B,Sc,Dc,Turn) == true)
		{
			gotoRowCol(4, 90);
			SetClr(3);
			cout << "DANGER";
		}*/
		//Turnchange();
	/*	if (B->getPieceAt(3, 7) != nullptr)
		{
			gotoRowCol(3, 90);
			SetClr(3);
			cout << "CHECK";

		}*/
		//

		//Turnchange();
		if (check == 1)
		{
			check = 0;
			break;
		}
		if (castling != 2)
		{
			int turnTime = B->move(Sc, Dc);

			playerTimes[Turn] += turnTime;

			auto turnEnd = chrono::steady_clock::now();
			int turnDuration = chrono::duration_cast<chrono::seconds>(turnEnd - turnStart).count();

			// Update player's total time taken
			playerTimes[Turn] += turnDuration;
			//if (playerTimes[Turn] >= 60) {

			//	break;
			//}
			cout << "Total time taken: " << playerTimes[Turn] << " seconds.\n";
		}
		B->displayBoard();

		Turnchange();

	}
	
}
void Chess::play()
{
	ifstream rdr("New1.txt");
	Chess C1;
	Chess C2(rdr);
	char c;
	Global::gotoRowCol(40, 50);
	cout << "n -> NEW OR L-> LOAD? ";
	cin >> c;
	if (c == 'l')
	{
		system("cls");
		C2.main();

	}
	else if (c=='n')
	{
		system("cls");
		C1.main();

	}

}