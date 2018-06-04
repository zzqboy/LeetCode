#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
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
};