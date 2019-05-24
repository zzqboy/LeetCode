#include <vector>
using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<int, vector<char>> row;
		vector<int, vector<char>> column;

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char flag = board[i][j];
				if (flag == '.')
				{
					continue;
				}
				auto it = find(row.begin(), row.end(), i);
				if (it == row.end())
				{
					row[i] = {flag};
				}
				else
				{
				}
			}
		}
	}
};