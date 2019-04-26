#include <string>
#include <vector>
using namespace std;
// 看样子是用先进先出的结构

class Solution {
public:
	bool isValid(string s) {
		vector<char> left_parenthe;
		vector<char> parenthe1 = { '(', '[', '{' };
		vector<char> parenthe2 = { ')', ']', '}' };

		for (char c : s)
		{
			auto it = find(parenthe1.begin(), parenthe1.end(), c);
			if (it != parenthe1.end())
			{
				left_parenthe.push_back(c);
			}
			else
			{
				if (left_parenthe.size() == 0)
				{
					return false;
				}

				char last_c = left_parenthe.back();
				it = find(parenthe1.begin(), parenthe1.end(), last_c);
				int index = it - parenthe1.begin();
				
				if (c != parenthe2[index])
				{
					return false;
				}
				else
				{
					left_parenthe.pop_back();
				}
			}
		}
		if (left_parenthe.size() == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};