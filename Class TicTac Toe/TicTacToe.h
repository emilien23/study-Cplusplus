#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
	TicTacToe();
	char CheckWin() const;
	void PrintArray() const;
	void Set(int i, int j, int player);
	bool PositionEmpty(int i, int j) const;
	bool CheckGame() const;
private:
	char array[3][3];
};
#endif