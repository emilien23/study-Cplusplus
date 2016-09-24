// Class TicTacToe.cpp: определяет точку входа для консольного приложения.
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
	cout << "Приветствуем Вас в игре Крестики-Нолики!" << endl;
	cout << endl;
	game.PrintArray();
	cout << endl;
	while (game.CheckWin() == '#')
	{
		do{
			cout << "Ход игрока номер " << player << ". Вводите позицию:" << endl;
			cout << "Строка( от 0 до 2): ";
			cin >> line;
			assert(line == 0 || line == 1 || line == 2);
			cout << "Столбец( от 0 до 2): ";
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
			cout << "Игра окончена в ничью!" << endl;
			player = 0;
			break;
		}
	}
	if (player != 0)
		cout << "Игра окончена. Победил игрок номер " << player << " . Поздравляем!" << endl;

	return 0;
}

