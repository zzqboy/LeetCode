#include <limits.h>
#include <iostream>
using namespace std;


class Solution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0)
		{
			return dividend > 0 ? INT_MAX : INT_MIN;
		}

		bool is_negative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
		long long move_c = 0;
		
		long temp1 = long(dividend);
		temp1 = temp1 < 0 ? -temp1 : temp1;
		long long temp2 = divisor;
		temp2 = temp2 < 0 ? -temp2 : temp2;

		while (temp2 <= temp1)
		{
			long long temp = temp2, move = 1;
			while ((temp << 1) <= temp1)
			{
				temp <<= 1;
				move <<= 1;
			}
			move_c += move;
			temp1 -= temp;
		}
		if ((move_c > INT_MAX && !is_negative)|| move_c < INT_MIN)
		{
			return INT_MAX;
		}
		move_c = is_negative ? -move_c : move_c;
		return move_c;

	}

	void test()
	{
		cout << this->divide(-2147483648, 1);
	}
};