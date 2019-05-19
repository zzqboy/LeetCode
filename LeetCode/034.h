#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int p1 = -1, p2 = -1;
		if (nums.size() == 0)
		{
			return{ p1, p2 };
		}
		this->dfs_binary_find(nums, 0, nums.size() - 1, target, p1, p2, -1);
		cout << p1 << " " << p2;
		return{ p1, p2 };
	}

	void dfs_binary_find(vector<int>& nums, int begin, int end, int target, int& p1, int& p2, int flag)
	{
		if (end < begin)
		{
			return;
		}
		if (begin == end)
		{
			if (nums[begin] == target && (begin == 0 || nums[begin - 1] != target))
			{
				p1 = begin;
			}
			if (nums[end] == target && (end == nums.size() - 1 || nums[end + 1] != target))
			{
				p2 = end;
			}
			return;
		}
		int mid = (begin + end) / 2;

		if (nums[mid] > target)
		{
			this->dfs_binary_find(nums, begin, mid - 1, target, p1, p2, flag);
		}
		if (nums[mid] < target)
		{
			this->dfs_binary_find(nums, mid + 1, end, target, p1, p2, flag);
		}
		if (nums[mid] == target)
		{
			if (flag == -1 || flag == 1)
			{
				if (mid != 0 && nums[mid - 1] == target)
				{
					this->dfs_binary_find(nums, begin, mid - 1, target, p1, p2, 1);
				}
				else
				{
					p1 = mid;
				}
			}
			if (flag == 2 || flag == -1)
			{
				if (nums[mid + 1] == target)
				{
					this->dfs_binary_find(nums, mid + 1, end, target, p1, p2, 2);
				}
				else
				{
					p2 = mid;
				}
			}

		}
	}

	void test()
	{
		vector<int> nums = {2, 2};
		this->searchRange(nums, 1);
	}
};