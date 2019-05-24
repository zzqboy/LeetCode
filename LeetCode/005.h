#pragma once
/*!
 * \file 005_Longest_Palindromic_Substring.h
 * \brief
 * \author zzqboy
 * \date 2018/04/07
 */
#include <string>
#include <iostream>
using namespace std;

// linear scan, judge left side and right side 
// 另外可以参考 Manacher算法 O(n)
class Solution {
public:
	string longestPalindrome(string s) {
		int offset, max_length;
		string left_s, right_s;
		string result;

		for (auto i = begin(s); i != end(s); i++)
		{
			// 先判断bab情况
			offset = 1, max_length = 1, left_s = "", right_s = "";
			while (i >= (begin(s) + offset) && i < (end(s) - offset) && *(i - offset) == *(i + offset))
			{
				max_length += 2;
				right_s += *(i + offset), left_s = *(i - offset) + left_s;
				if (max_length >= result.size())
				{
					result = left_s + *(i)+right_s;
				}
				offset += 1;
			}

			// 再判断bb这个情况
			offset = 1, max_length = 0, left_s = "", right_s = "";
			while (i < (end(s) - offset) && *(i + offset) == *(i + 1 - offset))
			{
				max_length += 2;
				right_s += *(i + offset), left_s = *(i - offset + 1) + left_s;
				if (max_length >= result.size())
				{
					result = left_s + right_s;
				}
				offset += 1;
			}
		}

		if (result.size() == 0)
		{
			result = s[0];
		}
		return result;
	}
};