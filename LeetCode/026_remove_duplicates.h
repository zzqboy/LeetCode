#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = 0;
		auto begin = nums.begin();
		while(begin != nums.end())
		{
			len += 1;
			int temp = *begin;
			begin++;
			
			while (begin != nums.end() && *(begin) == temp)
			{
				begin = nums.erase(begin);
			}
		}
		return len;
	}

	void test()
	{
		vector<int> d = {};
		cout << this->removeDuplicates(d);
	}
};