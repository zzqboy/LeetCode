#pragma once
#include <string>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		if (s.size() == 0)
		{
			return 0;
		}

		switch (s[0])
		{
		case 'I':
			if (2 <= s.size() && s[1] == 'V')
			{
				return 4 + romanToInt(s.substr(2));
			}
			else if (2 <= s.size() && s[1] == 'X')
			{
				return 9 + romanToInt(s.substr(2));
			}
			else
			{
				return 1 + romanToInt(s.substr(1));
			}
		case 'V':
			return 5 + romanToInt(s.substr(1));
		case 'X':
			if (2 <= s.size() && s[1] == 'L')
			{
				return 40 + romanToInt(s.substr(2));
			}
			else if (2 <= s.size() && s[1] == 'C')
			{
				return 90 + romanToInt(s.substr(2));
			}
			else
			{
				return 10 + romanToInt(s.substr(1));
			}
		case 'L':
			return 50 + romanToInt(s.substr(1));
		case 'C':
			if (2 <= s.size() && s[1] == 'D')
			{
				return 400 + romanToInt(s.substr(2));
			}
			else if (2 <= s.size() && s[1] == 'M')
			{
				return 900 + romanToInt(s.substr(2));
			}
			else
			{
				return 100 + romanToInt(s.substr(1));
			}
		case 'D':
			return 500 + romanToInt(s.substr(1));
		case 'M':
			return 1000 + romanToInt(s.substr(1));
		default:
			return 0;
		}
	}
};