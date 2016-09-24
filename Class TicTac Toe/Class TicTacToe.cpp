// Class TicTacToe.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include "iostream"
#include "assert.h"
#include "TicTacToe.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	TicTacToe game;
	int player = 1, line, column;
	cout << "������������ ��� � ���� ��������-������!" << endl;
	cout << endl;
	game.PrintArray();
	cout << endl;
	while (game.CheckWin() == '#')
	{
		do{
			cout << "��� ������ ����� " << player << ". ������� �������:" << endl;
			cout << "������( �� 0 �� 2): ";
			cin >> line;
			assert(line == 0 || line == 1 || line == 2);
			cout << "�������( �� 0 �� 2): ";
			cin >> column;
			assert(column == 0 || column == 1 || column == 2);
		} while (!game.PositionEmpty(line, column));
		game.Set(line, column, player);
		game.PrintArray();
		if (game.CheckWin() == '#')
		{
			player = (player == 1) ? 2 : 1;
		}
		if (!game.CheckGame())
		{
			cout << "���� �������� � �����!" << endl;
			player = 0;
			break;
		}
	}
	if (player != 0)
		cout << "���� ��������. ������� ����� ����� " << player << " . �����������!" << endl;

	return 0;
}

