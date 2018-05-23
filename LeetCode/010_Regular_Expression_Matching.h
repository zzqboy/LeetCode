#pragma once
#include <string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		int s_i = 0, p_i = 0, max_s_i = s.size(), max_p_i = p.size();
		bool equal = false;

		char *pre_char = NULL;
		while (s_i < max_s_i && p_i < max_p_i)
		{
			if (p[p_i] == s[s_i])
			{
				pre_char = &s[s_i];
				p_i++, s_i++;
				continue;
			}
			else if (p[p_i] == '.')
			{
				pre_char = &s[s_i];
				p_i++, s_i++;
				continue;
			}
			else if (p[p_i] == '*' && pre_char && *pre_char == s[s_i])
			{
				s_i++;
				continue;
			}
			else if (p[p_i] == '*' && (p_i - 1) >= 0 && p[p_i-1] == '.')
			{
				s_i++;
				continue;
			}
			else
			{
				p_i++;
			}
		}
		if (s_i == max_s_i)
		{
			equal = true;
			for (size_t i = p_i; i < max_p_i; i++)
			{
				if (p[i] != '*')
				{
					if (p[i-1] == '*' && pre_char && p[i] == *pre_char)
					{
						continue;
					}
					equal = false;
				}
			}
		}
		return equal;
	}
};