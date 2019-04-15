#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> result;
		vector<int>	result1;

		if (nums.size() <= 3)
		{
			result = {};
			return result;
		}

		int fixed_index1 = 0;
		int fixed_index2 = fixed_index1 + 1, index1 = fixed_index1 + 2, index2 = nums.size() - 1;
		while (fixed_index1 < nums.size() - 3)
		{
			while (index1 < index2)
			{
				int temp = nums[fixed_index1] + nums[fixed_index2] + nums[index1] + nums[index2];
				if (temp == target)
				{
					result1.push_back(nums[fixed_index1]);
					result1.push_back(nums[fixed_index2]);
					result1.push_back(nums[index1]);
					result1.push_back(nums[index2]);
					result.push_back(result1);
					result1.clear();

					while (index1 + 1 <= nums.size() - 1 && nums[index1] == nums[index1 + 1]){ index1++; }
					while (index2 - 1 >= 0 && nums[index2] == nums[index2 - 1]){ index2--; }
					index1++, index2--;
					continue;
				}
				if (temp > target)
				{
					index2--;
				}
				if (temp < target)
				{
					index1++;
				}
			}

			while (fixed_index2 < nums.size() - 3 && nums[fixed_index2] == nums[fixed_index2 + 1]){ fixed_index2++; }
			fixed_index2++;
			index1 = fixed_index2 + 1, index2 = nums.size() - 1;
			if (fixed_index2 > nums.size() - 3)
			{
				while (fixed_index1 < nums.size() - 4 && nums[fixed_index1] == nums[fixed_index1 + 1]){ fixed_index1++; }
				fixed_index1++;
				fixed_index2 = fixed_index1 + 1, index1 = fixed_index1 + 2, index2 = nums.size() - 1;
			}
		}


		for (vector<int> line: result)
		{
			for (int n : line)
			{
				cout << n << " ";
			}
			cout << endl;
		}
		return result;
	}
};