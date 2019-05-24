#pragma once
#include <string>
using namespace std;

// 参考：https://www.jianshu.com/p/85f3e5a9fcda


class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0 && s.size() == 0) return true;
		if (p.size() == 0 && s.size() != 0) return false;

		if (p.size() == 1 && s.size() == 0) return false;
		if (p.size() == 1)
		{
			if (p[0] == s[0] || p[0] == '.')
			{
				return isMatch(s.substr(1), p.substr(1));
			}
			else
			{
				return false;
			}
		}
		if (p.size() > 1)
		{
			if (p[1] != '*')
			{
				if( s.size() != 0 && (s[0] == p[0] || p[0] == '.'))	return isMatch(s.substr(1), p.substr(1));
				return false;
			}
			if (p[1] == '*')
			{
				if (s.size() != 0 && (s[0] == p[0] || p[0] == '.'))
				{
					if (isMatch(s, p.substr(2))) return true;
					return isMatch(s.substr(1), p);
				}
				else
				{
					return isMatch(s, p.substr(2));
				}
			}
		}

	}
};