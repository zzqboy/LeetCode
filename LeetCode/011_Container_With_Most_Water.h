#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	/*
	int maxArea(vector<int>& height) {
		int result = 0;
		for (auto i = begin(height); i < end(height); i++)
		{
			for (auto j = i; j < end(height); j++)
			{
				if ((j - i) * min(*i, *j) > result)
				{
					result = (j - i) * min(*i, *j);
				}
			}
		}
		return result;
	}
	*/
	int maxArea(vector<int>& height) {
		auto i = height.begin();
		auto j = height.end() - 1;
		int result = min(*j, *i) * (j - i);
		int temp = 0;

		while (i < j)
		{
			if (*i < *j)
			{
				temp = min(*j, *(++i))*(j - i);
			}
			else
			{
				temp = min(*(--j), *i)*(j - i);
			}
			result = temp > result ? temp : result;
		}
		return result;
	}
};