#include "stdafx.h"
#include "iostream"
#include "TicTacToe.h"

using namespace std;


TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			array[i][j] = '#';
}

void TicTacToe::PrintArray() const
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << array[i][j];
		cout << endl;
	}
}

char TicTacToe::CheckWin() const
{
	for (int i = 0; i < 3; i++)
		if (array[i][0] == array[i][1] && array[i][1] == array[i][2])
			return array[i][0];
	for (int i = 0; i < 3; i++)
		if (array[0][i] == array[1][i] && array[1][i] == array[2][i])
			return array[0][i];
	if (array[0][0] == array[1][1] && array[1][1] == array[2][2])
		return array[1][1];
	if (array[0][2] == array[1][1] && array[1][1] == array[2][0])
		return array[1][1];
	return 0;
}
void TicTacToe::Set(int i, int j, int player)
{
	if (player == 1)
		array[i][j] = 'x';
	else 
		array[i][j] = 'o';
}
bool TicTacToe::PositionEmpty(int i, int j) const
{
	if (array[i][j] == '#')
		return true;
	else
	{
		cout << "Вы вводите число в уже заполненную позицию. Повторите попытку!" << endl;
		return false;
	}
}
bool TicTacToe::CheckGame() const
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (array[i][j] == '#')
				return true;
	return false;
}