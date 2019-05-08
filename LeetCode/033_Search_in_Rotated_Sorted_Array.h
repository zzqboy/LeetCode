#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
		{
			return -1;
		}
		int idx = -1;
		this->dfs_search(nums, 0, nums.size() - 1, target, idx);
		cout << idx;
		return idx;
	}

	void dfs_search(vector<int>& nums, int begin, int end, int target, int& idx)
	{
		int mid = (begin + end) / 2;
		if (begin == end)
		{
			if (nums[mid] == target)
			{
				idx = mid;
			}
			return;
		}
		
		if (nums[mid] > nums[begin]) // 正常递增
		{
			if (nums[begin] > target || nums[mid] < target) 
			{
				// 找不到了
			}
			else
			{
				// 在前半段
				dfs_search(nums, begin, mid, target, idx);
				return;
			}
		}
		else // 这段不正常 继续找
		{
			dfs_search(nums, begin, mid, target, idx);
		}

		if (nums[mid + 1] < nums[end]) // 正常递增
		{
			if (nums[mid + 1] > target || nums[end] < target)
			{
				// 找不到了
			}
			else
			{
				// 在前半段
				dfs_search(nums, mid + 1, end, target, idx);
				return;
			}
		}
		else // 这段不正常 继续找
		{
			dfs_search(nums, mid + 1, end, target, idx);
		}
	}

	void test()
	{
		vector<int> n = { 1, 3 };
		this->search(n, 3);
	}
};