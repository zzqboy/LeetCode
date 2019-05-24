/*!
* \file add two numbers
* \brief two_sum
* \author zzqboy
* \date 三月 2018
*/
#include <iostream>
#include <stdio.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		int carry = 0;
		ListNode head(0);
		ListNode* p = &head;

		while (l1 != NULL || l2 != NULL)
		{
			int x = (l1 != NULL) ? l1->val : 0;
			int y = (l2 != NULL) ? l2->val : 0;


			int sum = x + y + carry;
			carry = sum / 10;

			p->next = new ListNode(sum % 10);
			p = p->next;

			l1 = (l1 != NULL) ? l1->next : l1;
			l2 = (l2 != NULL) ? l2->next : l2;
		}
		if (carry > 0)
		{
			p->next = new ListNode(carry);
		}
		return head.next;
	}
};