#include <vector>
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;


class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
		this->draw_first(board);
		this->dfsSolve(board, 0, 0);
	}

	bool dfsSolve(vector<vector<char>>& board, int i, int j)
	{
		if (i >= 9)
		{ 
			return true; 
		}
		if (j >= 9)
		{
			return this->dfsSolve(board, i + 1, 0);
		}
		if (board[i][j] != '.')
		{
			return this->dfsSolve(board, i, j + 1);
		}
		for (int k = 1; k <= 9; k++)
		{
			board[i][j] = '0' + k;
			this->draw(i, j, '0' + k);
			Sleep(100);
			if (this->IsValid(board, i, j))
			{
				if (this->dfsSolve(board, i, j + 1))
				{
					return true;
				}
			}
			board[i][j] = '.';
		}
		return false;
	}

	bool IsValid(vector<vector<char>>& board, int i, int j)
	{
		for (int col = 0; col < 9; ++col) {
			if (col != j && board[i][j] == board[i][col]) return false;
		}
		for (int row = 0; row < 9; ++row) {
			if (row != i && board[i][j] == board[row][j]) return false;
		}
		for (int row = i / 3 * 3; row < i / 3 * 3 + 3; ++row) {
			for (int col = j / 3 * 3; col < j / 3 * 3 + 3; ++col) {
				if ((row != i || col != j) && board[i][j] == board[row][col]) return false;
			}
		}
		return true;
	}

	void draw(int x, int y, char text)
	{
		COORD position;
		position.X = y, position.Y = x;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
		std::cout << text  << std::endl;
	}

	void draw_first(vector<vector<char>>& board)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				this->draw(i, j, board[i][j]);
			}
		}
	}

	void test()
	{
		vector<vector<char>> board =
		{ 
			{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
			{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
			{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
			{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
			{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
			{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
			{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
			{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
			{ '.', '.', '.', '.', '8', '.', '.', '7', '9' }
		};
		this->solveSudoku(board);
	}
};