#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int idx = -1;
		this->binary_search(nums, target, 0, nums.size() - 1, idx);
		return idx;
	}

	void binary_search(vector<int>& nums, int target, int begin, int end, int& idx)
	{
		int mid = (begin + end) / 2;
		if (begin == end)
		{
			if (nums[begin] == target)
			{
				idx = begin;
				return;
			}
			if (nums[begin] > target)
			{
				idx = begin;
			}
			else
			{
				idx = end + 1;
			}
			return;
		}
		if (nums[mid] >= target)
		{
			this->binary_search(nums, target, begin, mid, idx);
		}
		if (nums[mid] < target)
		{
			this->binary_search(nums, target, mid + 1, end, idx);
		}
	}

	void test()
	{
		vector<int> nums = { 1, 3, 5, 6 };
		int i = this->searchInsert(nums, 5);
		cout << i << endl;
	}
};
