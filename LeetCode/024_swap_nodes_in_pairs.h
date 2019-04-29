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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL)
		{
			return head;
		}
		if (head->next == NULL)
		{
			return head;
		}
		ListNode* r = NULL;
		ListNode* r2 = NULL;
		dfs_swap(r, r2, head, head->next, 0);
		return r;
	}

	void dfs_swap(ListNode*& result, ListNode* pre_n1, ListNode* pre_n, ListNode* head, int num)
	{
		if (num == 0)
		{
			result = head;
		}
		if (head == NULL)
		{
			return;
		}
		if (num % 2 == 0)
		{
			if (head->next != NULL)
			{
				pre_n->next = head->next;

			}
			else
			{
				pre_n->next = NULL;
			}
			head->next = pre_n;
			if (pre_n1 != NULL)
			{
				pre_n1->next = head;
			}
			dfs_swap(result, head, pre_n, pre_n->next, num + 1);
		}
		else
		{
			dfs_swap(result, pre_n, head, head->next, num + 1);
		}
	}

	void test()
	{
		ListNode* s = new ListNode(1);
		s->next = new ListNode(2);
		s->next->next = new ListNode(3);
		s->next->next->next = new ListNode(4);
		s->next->next->next->next = new ListNode(5);

		this->swapPairs(s);
	}
};