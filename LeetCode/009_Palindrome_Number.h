#pragma once
#include <vector>
using namespace std;
// 回文数字，不要转为string

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
		{
			return false;
		}
		else if (x == 0)
		{
			return true;
		}
		else
		{
			vector<int> number_v;

			int n1 = x % 10;
			int n2 = x / 10;

			while (n2 != 0)
			{
				number_v.push_back(n1);
				n1 = n2 % 10;
				n2 = n2 / 10;
			}
			number_v.push_back(n1);

			int size = (number_v.end() - number_v.begin()) / 2;
			for (int i = 0; i < size; i++)
			{
				if (*(number_v.begin() + i) != *(number_v.end() - i - 1))
				{
					return false;
				}
			}
			return true;
		}

	}
};