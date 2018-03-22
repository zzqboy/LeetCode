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
		map<char, string::iterator> s_char;
		int max_lenght = 0, temp = 0;

		for (auto p2 = p1; p2 != end(s); p2++)
		{
			auto index = s_char.find(*p2);
			if (index == s_char.end())
			{
				s_char[*p2] = p2;
				temp += 1;
				if (temp > max_lenght)
				{
					max_lenght = temp;
				}
			}
			else
			{
				auto next_p = s_char[*p2] + 1;
				s_char.clear();
				for (p1 = next_p; p1 != p2 + 1; p1++)
				{
					s_char[*p1] = p1;
				}
				p1 = next_p;
				temp = (int)(p2 - p1 + 1);
			}

		}
		return max_lenght;
	}
};