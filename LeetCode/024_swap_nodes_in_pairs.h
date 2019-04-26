#include <stdio.h>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* swapPairs(ListNode* head) {

	}

	void dfs_swap(ListNode* head, ListNode* before, ListNode* after, int num)
	{
		if (num % 2 == 0)
		{
			ListNode* next = head->next;
			ListNode* back = next->next;
		}
	}
};