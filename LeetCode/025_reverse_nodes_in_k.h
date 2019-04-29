#include <stdio.h>
#include <iostream>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* result = get_reverse_group(head, k);
		return result;
	}

	ListNode* get_reverse_group(ListNode* head, int k)
	{
		if (head == NULL)
		{
			return head;
		}

		if (! this->is_enough_size(head, k))
		{
			return head;
		}
		ListNode* begin = head, *next = head->next, *temp = head->next, *tail = NULL;
		int k2 = k;
		while (k2 > 1)
		{
			temp = temp->next;
			// 交换位置
			next->next = begin;
			

			k2 -= 1;
			begin = next;
			next = temp;
		}

		head->next = this->get_reverse_group(temp, k);
		return begin;
	}

	bool is_enough_size(ListNode* n, int k)
	{
		while (n != NULL)
		{
			k -= 1;
			n = n->next;
		}
		if (k > 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	void print(ListNode* n)
	{
		while (n)
		{
			cout << n->val << " ";
			n = n->next;
		}
		cout << endl;
	}

	void test()
	{
		ListNode* n = new ListNode(1);
		n->next = new ListNode(2);
		n->next->next = new ListNode(3);
		n->next->next->next = new ListNode(4);
		n->next->next->next->next = new ListNode(5);
		this->reverseKGroup(n, 3);
	}
};