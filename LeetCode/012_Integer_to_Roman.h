#pragma once
#include <string>
#include <vector>
using namespace std;

// 罗马数字
class Solution {
public:
	string intToRoman(int num) {
		switch (num)
		{
		case 1:
			return "I";
		case 4:
			return "IV";
		case 5:
			return "V";
		case 9:
			return "IX";
		case 10:
			return "X";
		case 40:
			return "XL";
		case 50:
			return "L";
		case 90:
			return "XC";
		case 100:
			return "C";
		case 400:
			return "CD";
		case 500:
			return "D";
		case 900:
			return "CM";
		case 1000:
			return "M";
		default:
			break;
		}
		int num_list[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
		int length = sizeof(num_list) / sizeof(num_list[0]);
		string result = "";

		while (num != 0)
		{
			for (int i = length - 1; i >= 0; i--)
			{
				if (num_list[i] <= num)
				{
					num -= num_list[i];
					result = result += intToRoman(num_list[i]);
					break;
				}
			}
		}
		return result;
	}
};