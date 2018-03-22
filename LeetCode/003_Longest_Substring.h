/*!
 * \file 003_Longest_Substring.cpp
 * \brief
 * \author zzqboy
 * \date 三月 2018
 */
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		auto p1 = begin(s);
		map<char, int> s_char;
		int max_lenght = 0, temp = 0;

		for (auto p2 = p1; p2 != end(s); p2++)
		{
			cout << *p1 << " " << *p2 << " " << temp << endl;
			auto index = s_char.find(*p2);
			if (index == s_char.end())
			{
				s_char[*p2] = (int)(p2 - p1);
				temp += 1;
				continue;
			}
			else
			{
				if (temp > max_lenght)
				{
					max_lenght = temp;
				}
				p1 = p1 + s_char[*p2] + 1;
				temp = (int)(p2 - p1 + 1);
			}
		}

		if (temp > max_lenght)
		{
			max_lenght = temp;
		}
		return max_lenght;
	}
};