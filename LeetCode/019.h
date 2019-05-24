#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	vector<ListNode*> temp_node;

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		int deep = -1;
		dfs_remove(head, deep);
		int n_from_b  = deep + 1 - n;
		if (n_from_b == 0)
		{
			return head->next;
		}
		if (n_from_b == deep)
		{
			ListNode* node = temp_node[n_from_b - 1];
			node->next = NULL;
		}
		else
		{
			ListNode* node = temp_node[n_from_b - 1];
			ListNode* next_node = temp_node[n_from_b];
			node->next = next_node->next;
		}
		return head;
	}

	void dfs_remove(ListNode* head, int& deep)
	{
		if (head == NULL)
		{
			return;
		}
		deep++;
		temp_node.push_back(head);
		dfs_remove(head->next, deep);
	}
};