#include <vector>
#include <string>
#include <iostream>
using namespace std;


class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result; 
		this->add_next_parenthe("", n*2, 0, result);
		for (string s:result)
		{
			cout << s << endl;
		}
		return result;
	}

	void add_next_parenthe(string begin, int num, int flag, vector<string>& result)
	{
		if (flag < 0 || num < 0)
		{
			return;
		}
		if (num == 0 && flag == 0)
		{
			result.push_back(begin);
			return;
		}
		add_next_parenthe(begin + "(", num - 1, flag + 1, result);
		add_next_parenthe(begin + ")", num - 1, flag - 1, result);
	}
};