/*!
 * \file 001_two_sum.cpp
 * \brief two_sum
 * \author zzqboy
 * \date 三月 2018
 */
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result{ 0, 0 };

		for (auto i = begin(nums); i != end(nums); i++)
		{
			for (auto j = i + 1; j != end(nums); j++)
			{
				if ((*i + *j) == target)
				{
					cout << *i << " " << *j << endl;
					result = { int(i - begin(nums)), int(j - begin(nums)) };
					return result;
				}
			}
		}

		return result;
	}
};

// o(n)解法
class Solution2 {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result{ 0, 0 };
		map<int, int> complete_map;

		for (auto i = begin(nums); i != end(nums); i++)
		{
			auto index = complete_map.find(*i);
			if (index == end(complete_map))
			{
				cout << target - *i << " " << i - begin(nums) << endl;
				complete_map[target - *i] = int(i - begin(nums));
			}
			else
			{
				result = { complete_map[*i], int(i - begin(nums)) };
			}
		}

		return result;
	}
};
