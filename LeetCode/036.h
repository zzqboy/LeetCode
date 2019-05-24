#include <map>
#include <vector>
#include <utility>
using namespace std;


class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		map<int, vector<char>> row;
		map<int, vector<char>> column;
		vector<char> sub[9];

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				char flag = board[i][j];
				if (flag == '.')
				{
					continue;
				}
				// 扫描一行
				if (row.find(i) == row.end())
				{
					row[i] = {flag};
				}
				else
				{
					vector<char>& row_s = row[i];
					if (find(row_s.begin(), row_s.end(), flag) != row_s.end())
					{
						return false;
					}
					else
					{
						row_s.push_back(flag);
					}
				}
				// 扫描一列
				if ( column.find(j) == column.end())
				{
					column[j] = { flag };
				}
				else
				{
					vector<char>& column_s = column[j];
					if (find(column_s.begin(), column_s.end(), flag) != column_s.end())
					{
						return false;
					}
					else
					{
						column_s.push_back(flag);
					}
				}
				// 判断下每个3*3是否满足
				int sub1 = i / 3, sub2 = j / 3;
				vector<char>& sub_s = sub[sub1*3 + sub2];
				if (find(sub_s.begin(), sub_s.end(), flag) != sub_s.end())
				{
					return false;
				}
				else
				{
					sub_s.push_back(flag);
				}

			}
		}
		return true;
	}
};