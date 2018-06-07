#pragma once
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
		{
			return "";
		}

		auto iter = strs.begin();
		int c_i = 0;

		while (c_i < strs[0].size())
		{
			char c = strs[0][c_i];
			for (size_t i = 1; i < strs.size(); i++)
			{
				if (c_i < strs[i].size() && strs[i][c_i] == c)
				{
					continue;
				}
				else
				{
					return strs[0].substr(0, c_i - 0);
				}
			}
			c_i++;
		}
		return strs[0].substr(0, c_i - 0);
	}
};