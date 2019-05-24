#include <vector>
using namespace std;


class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		if (board.empty() || board.size() != 9 || board[0].size() != 9) return;
		this->dfsSolve(board, 0, 0);
	}

	bool dfsSolve(vector<vector<char>>& board, int i, int j)
	{
		if (i >= 9){ return true; }
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
};