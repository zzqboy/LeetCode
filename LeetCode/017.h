﻿#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
	vector<string> result;

	map<int, string> number2letter = { {
		{ 2, "abc" },
		{ 3, "def" },
		{ 4, "ghi" },
		{ 5, "jkl" },
		{ 6, "mno" },
		{ 7, "pqrs" },
		{ 8, "tuv" },
		{ 9, "wxyz" },
	} };

	vector<string> letterCombinations(string digits) {
		this->dfs_add_letter(digits, "");
		return this->result;
	}

	void dfs_add_letter(string digits, string pre_combine)
	{
		char number = digits[0];
		string letters = number2letter[number - '0'];
		for (int index = 0; index < letters.size(); ++index)
		{
			char letter = letters[index];
			string now_combine = pre_combine + letter;
			if (digits.size() == 1)
			{
				this->result.push_back(now_combine);
			}
			else
			{
				dfs_add_letter(digits.substr(1), now_combine);
			}
		}
	}
};