#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> c_s;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				c_s.push(i);
			}
			else
			{
				if (!c_s.empty())
				{
					if (s[c_s.top()] == '(')
					{
						c_s.pop();
					}
					else
					{
						c_s.push(i);
					}
				}
				else
				{
					c_s.push(i);
				}
			}
		}
		if (c_s.empty())
		{
			return s.size();
		}
		int a = s.size(), b = 0;
		int max_ = 0;
		while (!c_s.empty())
		{
			b = c_s.top();
			c_s.pop();
			max_ = max(max_, a - b - 1);
			a = b;
		}
		max_ = max(max_, a);
		return max_;
	}
	
	void test()
	{
		cout << this->longestValidParentheses("()(())");
	}
};