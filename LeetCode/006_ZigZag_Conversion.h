#pragma once
/*!
 * \file 006_ZigZag_Conversion.h
 * \brief 
 * \author zzqboy
 * \date 2018/04/07
 */
#include <string>
#include <iostream>
using namespace std;

// 找规律的一道题不知道有什么算法可言
class Solution {
public:
	string convert(string s, int numRows) {
		auto s_b = begin(s);
		string result;
		if (numRows == 1)
		{
			return s;
		}
		for (int i = 0; i < numRows; i++)
		{
			int col = i;
			while (col < (int) s.size())
			{
				//cout << s[col] << endl;
				result += s[col];
				if (i != 0 && i != numRows - 1)
				{
					int interval_i = col + (numRows -1 - i) * 2;
					if (interval_i < (int)s.size())
					{
						//cout << s[interval_i] << endl;
						result += s[interval_i];
					}
				}
				col = col + 2 * numRows - 2;
			}
		}
		return result;
	}
};