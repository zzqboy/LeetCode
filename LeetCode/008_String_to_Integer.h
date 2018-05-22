#pragma once
#include <string>
using namespace std;

// string to int
class Solution {
public:
	int myAtoi(string str) {
		int neg = 1;
		int result = 0;
		int begin = false;

		for (char i : str)
		{
			if (i <= '9' && i >= '0')
			{
				begin = true;
				int i_n = i - '0';
				if ((result > (INT_MAX / 10)) || (result == (INT_MAX / 10) && i_n >= 7))	// 这里的判断很容易出错
				{
					if (neg == 1)
					{
						return INT_MAX;
					}
					else
					{
						return INT_MIN;
					}
				}
				result = result * 10;
				result += i_n;
			}
			else
			{
				if (i == '-')
				{
					begin = true;
					neg = -1;
					continue;
				}
				else if (i == '+' || i == ' ')
				{
					begin = true;
					continue;
				}
				else
				{
					if (!begin)
					{
						return 0;
					}
					else
					{
						break;
					}
				}
			}
		}
		return result * neg;
	}
};