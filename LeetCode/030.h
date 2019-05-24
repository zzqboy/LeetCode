#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		if (words.size() == 0 || s.size() == 0)
		{
			return {};
		}
		// 统计每个string出现次数
		int num = 0;
		unordered_map<string, int> words_num;
		for (int i = 0; i < words.size(); i++)
		{
			num++;
			words_num[words[i]]++;
		}
		// 记录匹配的次数
		unordered_map<string, int> words_cnt;
		int match_num = 0;
		vector<int> result;
		
		int idx = 0, w_l = words[0].size(), n = words.size();
		while (idx < s.size() - w_l * n + 1)
		{
			int move_p = idx;
			match_num = 0;
			words_cnt.clear();

			while (move_p < s.size() - w_l + 1 && move_p - idx + 1 < words.size() * w_l)
			{
				string s_b = s.substr(move_p, w_l);
				if (words_num.find(s_b) != words_num.end())
				{
					words_cnt[s_b]++;
					if (words_cnt[s_b] > words_num[s_b]) // 有一个多出现了 那么idx开始的一定不匹配
					{
						break;
					}
				}
				else
				{
					break;
				}

				match_num += 1; // 总的匹配次数
				move_p += w_l;
				if (match_num == num)
				{
					result.push_back(idx);
				}
			}

			idx++;
		}
		return result;
	}

	void test()
	{
		string s = "a";
		vector<string> words = {"a"};
		vector<int> r = this->findSubstring(s, words);
		for (int i = 0; i < r.size(); i++)
		{
			cout << r[i] << endl;
		}
	}
};