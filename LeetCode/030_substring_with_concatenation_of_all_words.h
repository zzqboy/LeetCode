#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		int idx = 0;
		vector<int> words_temp;

		while (idx <= s.size() - words[0].size() * words.size() + 1)
		{
			int idx2 = 0;
			while(idx2 < words.size())
			{
				if ()
				{
				}
				int second = 0;
				int first = idx;
				string m_s = words[idx2];
				while (first < s.size() && second < m_s.size() && s[first] == m_s[second])
				{
					second++, first++;
				}
				if (second == m_s.size())
				{
					// 表示这个匹配了 把这个标记找过
					words_temp.push_back(idx2);
				}

			}
		}
	}
};