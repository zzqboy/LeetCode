#pragma once
#include <string>
#include <iostream>
using namespace std;

// string to int
class Solution {
public:
	int myAtoi(string str) {


		int neg = 1;
		int result = 0;

		int length = str.size();
		int i = 0;
		while(str[i] == ' ' && i < length)
		{
			i++;
			continue;
		}
		if (str[i] == '-')
		{
			i++;
			neg = -1;
		}
		else if (str[i] == '+')
		{
			i++;
		}
		for(; i < length; i++)
		{
			if (str[i] <= '9' && str[i] >= '0')
			{
				int i_n = str[i] - '0';
				if (((result > (INT_MAX / 10)) || (result == (INT_MAX / 10) && i_n >= 7)) && (neg == 1))	// 这里的判断很容易出错
				{
					return INT_MAX;
				}
				if (((result > (INT_MAX / 10)) || (result == (INT_MAX / 10) && i_n >= 8)) && (neg == -1))	// 这里的判断很容易出错
				{
					return INT_MIN;
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