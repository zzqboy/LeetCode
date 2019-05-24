#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
		{
			return 0;
		}
		if (haystack.empty() || haystack.size() < needle.size())
		{
			return -1;
		}
		int first = 0, second = 0;
		for (int idx = 0; idx < haystack.size() - needle.size() + 1; idx++)
		{
			first = idx, second = 0;
			while (first < haystack.size() && second < needle.size() && haystack[first] == needle[second])
			{
				first++;
				second++;
			}
			if (second == needle.size())
			{
				return idx;
			}
		}
		return -1;
	}

	void test()
	{
		cout << this->strStr("12312", "31");
	}
};