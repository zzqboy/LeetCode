#include <string>
using namespace std;


class Solution {
public:
	string countAndSay(int n) {
		if (n == 1) {
			return "1";
		};
		string re = countAndSay(n - 1);
		int count = 0;
		char cur = re[0];
		string sb;
		for (int i = 0; i < re.size(); i++) {
			if (cur != re[i]) {
				sb += std::to_string(count);
				sb += cur;
				cur = re[i];
				count = 1;
			}
			else {
				count++;
			}
		}
		sb += count > 0 ? std::to_string(count) + cur : "";
		return sb;
	}
};