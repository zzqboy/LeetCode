#include <stdio.h>


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l = new ListNode(0);
		ListNode* temp = l;
		while (l1 != NULL || l2 != NULL)
		{
			if (l1 != NULL && l2 != NULL)
			{
				if (l1->val <= l2->val)
				{
					l->next = l1;
					l1 = l1->next;
				}
				else
				{
					l->next = l2;
					l2 = l2->next;
				}
			}
			else if (l1 == NULL)
			{
				l->next = l2;
				l2 = l2->next;
			}
			else if (l2 == NULL)
			{
				l->next = l1;
				l1 = l1->next;
			}

			l = l->next;
		}
		return temp->next;
	}
};