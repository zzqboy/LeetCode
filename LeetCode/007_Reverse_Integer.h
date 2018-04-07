#pragma once
/*!
 * \file 7_Reverse_Integer.h
 * \brief
 * \author zzqboy
 * \date 2018/04/07
 */
#include <vector>
#include <iostream>
using namespace std;

//just note not overlap
class Solution {
public:
	int reverse(int x) {
		long long result = 0;
		int flag = (x < 0) ? -1 : 1;
		vector<unsigned int> rem_number;

		while (x / 10 != 0)
		{
			int rem_n = x % 10;
			rem_number.push_back(static_cast<unsigned>(abs(rem_n)));
			cout << static_cast<unsigned>(abs(rem_n)) << endl;
			x = x / 10;
		}
		rem_number.push_back(static_cast<unsigned>(abs(x % 10)));

		long long radix = 1;
		for (auto i = rbegin(rem_number); i != rend(rem_number); i++)
		{
			cout << *i << endl;
			result += *i * radix;
			radix *= 10;
			cout << result << endl;
		}
		if ((result >= pow(2, 31) && flag == 1) || (result > pow(2, 31) && flag == -1)) // 是否溢出
		{
			return 0;
		}
		else
		{
			return result * flag;
		}
	}
};

// elegant write!
/*
class Solution {
public:
	int reverse(int x) {
		long target = 0;
		while (x != 0) {
			target = target * 10 + x % 10;
			x /= 10;
		}
		target = (target<INT_MIN || target>INT_MAX) ? 0 : target;
		return target;
	}
};
*/