#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		auto first = nums.begin();
		while (first != nums.end())
		{
			if (*first == val)
			{
				auto second = first + 1;
				while (second != nums.end() && *second == val) second++;
				// 找到了一个不是val的值 前移
				if (second != nums.end())
				{
					int temp = *first;
					*first = *second;
					*second = temp;
					continue;
				}
				else // 后面的都是val
				{
					return first - nums.begin();
				}
			}
			else
			{
				first++;
			}
		}
		return first - nums.begin();
	}

	void test()
	{
		vector<int> d = { 3, 2, 2, 3 };
		cout << this->removeElement(d, 4);
	}
};