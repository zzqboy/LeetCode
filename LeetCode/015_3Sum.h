#pragma once
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> triple;

		if (nums.size() < 3)
		{
			return triple;
		}
		sort(nums.begin(), nums.end());
		for (size_t fix_i = 0; fix_i < nums.size(); fix_i++)
		{
			if (nums[fix_i] > 0 || fix_i > nums.size() - 3) break;
			if (fix_i > 0 && nums[fix_i - 1] == nums[fix_i]) continue;

			size_t i = fix_i + 1, j = nums.size() - 1;
			while (i < j)
			{
				int temp = (nums[i] + nums[j] + nums[fix_i]);
				if (temp > 0)
				{
					j -= 1;
				}
				else if (temp < 0)
				{
					i += 1;
				}
				else if (temp == 0)
				{
					vector<int> t = { nums[fix_i], nums[i], nums[j] };
					triple.push_back(t);
					while (i < j && nums[i] == nums[i + 1]) ++i;
					while (i < j && nums[j] == nums[j - 1]) --j;
					i++, j--;
				}
			}
		}
		return triple;
	}
};