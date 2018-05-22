#pragma once
#include <string>
using namespace std;

// string to int
class Solution {
public:
	int myAtoi(string str) {


		int neg = 1;
		int result = 0;

		const char* str_c = str.c_str();
		int length = strlen
		int i = 0;
		while(str_c[i++] == ' ')
		{
			continue;
		}
		if (str_c[i] == '-')
		{
			neg = -1;
		}

		for(; i < length; i++)
		{
			if (i <= '9' && i >= '0')
			{
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
				break;
			}
		}
		return result * neg;
	}
};