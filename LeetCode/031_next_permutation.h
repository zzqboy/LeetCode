#include <vector>
#include <iostream>
using namespace std;
// 参考solution 2

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		if (nums.size() == 0 || nums.size() == 1)
		{
			return;
		}
		int idx = nums.size() - 1;
		int idx2 = idx - 1;

		bool is_rever = true;
		while (idx >= 1)
		{
			if (nums[idx2] < nums[idx])
			{
				// 找到刚好大于idx2的值
				int idx3 = idx, temp = nums[idx], temp2 = idx;
				while (idx3 < nums.size())
				{
					if (nums[idx3] > nums[idx2] && nums[idx3] <= temp)
					{
						temp2 = idx3;
					}
					idx3++;
				}

				this->swap(nums, temp2, idx2);
				this->rever(nums, idx2 + 1, nums.size() - 1);
				is_rever = false;
				break;
			}
			else
			{
				idx--, idx2--;
			}
		}
		if (is_rever)
		{
			this->rever(nums, 0, nums.size() - 1);
		}
	}

	bool swap(vector<int>& nums, int i1, int i2)
	{
		bool is_bigger = nums[i2] > nums[i1] ? true : false;
		int temp = nums[i2];
		nums[i2] = nums[i1];
		nums[i1] = temp;
		return is_bigger;
	}

	void rever(vector<int>& nums, int first, int second)
	{
		while (first < second)
		{
			this->swap(nums, first, second);
			first++, second--;
		}
	}

	void test()
	{
		vector<int> d = { 1, 2, 3 };
		this->nextPermutation(d);
		for (int i = 0; i < d.size(); i++)
		{
			cout << d[i] << endl;
		}
	}
};