#pragma once
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		vector<int> triple;
		int result = nums[0] + nums[1] + nums[2];
		int sub = abs(nums[0] + nums[1] + nums[2] - target);

		if (nums.size() < 3)
		{
			return result;
		}
		sort(nums.begin(), nums.end());
		for (size_t fix_i = 0; fix_i < nums.size() - 2; fix_i++)
		{
			if (fix_i > 0 && nums[fix_i - 1] == nums[fix_i]) continue;

			size_t i = fix_i + 1, j = nums.size() - 1;
			while (i < j)
			{
				int temp = (nums[i] + nums[j] + nums[fix_i]);

				if (abs(temp - target) <= sub)
				{
					result = temp;
					sub = abs(temp - target);
				}

				if (temp > target)
				{
					--j;
				}
				else
				{
					++i;
				}
			}
		}
		return result;
	}
};