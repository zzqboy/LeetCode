/*!
 * \file 004_Median_of_Two_Sorted_Arrays.cpp
 * \brief
 * \author zzqboy
 * \date 三月 2018
 */
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

// 归并排序
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int lenght = static_cast<int>(nums1.size() + nums2.size());
		double median = (double)lenght / 2;
		bool is_even = lenght % 2 == 0 ? true : false;

		auto n1_p = begin(nums1), n2_p = begin(nums2);
		double number[2];
		int iter_count = 0, temp = 0;
		while (n1_p != end(nums1) || n2_p != end(nums2))
		{
			iter_count++;

			if (n1_p == end(nums1))
			{
				temp = *n2_p;
				n2_p++;
			}
			else if (n2_p == end(nums2))
			{
				temp = *n1_p;
				n1_p++;
			}
			else
			{
				if (*n1_p <= *n2_p)
				{
					temp = *n1_p;
					n1_p++;
				}
				else
				{
					temp = *n2_p;
					n2_p++;
				}
			}
			// cout << iter_count << "-- " << temp << endl;

			if (is_even)
			{
				if (iter_count == median)
				{
					number[0] = temp;
				}
				if (iter_count == median + 1)
				{
					number[1] = temp;
					return (number[0] + number[1]) / 2;
				}
			}
			else
			{
				if (iter_count == ceil(median))
				{
					return temp;
				}
			}
		}
		return  0;
	}
};