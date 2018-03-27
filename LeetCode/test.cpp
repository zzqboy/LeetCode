#include "004_Median_of_Two_Sorted_Arrays.h"
#include <iostream>

int main()
{
	Solution test;
	vector<int> a{1, 2}, b{ 6, 7 };
	cout << test.findMedianSortedArrays(a, b) << endl;
	return 0;
}