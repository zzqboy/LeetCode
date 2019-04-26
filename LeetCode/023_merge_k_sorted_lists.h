#include <vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		// 一次遍历里最小的node
		ListNode* temp = new ListNode(0);
		ListNode* result = temp;

		while (true)
		{
			int idx = 0;
			int idx2 = -1;
			ListNode* min_l = NULL;

			for (ListNode* l : lists)
			{
				if (l != NULL)
				{
					if (min_l == NULL || l->val <= min_l->val)
					{
						min_l = l;
						idx2 = idx;
					}
				}
				idx += 1;
			}
			
			if (idx2 == -1)
			{
				// 已经遍历完了
				break;
			}
			
			temp->next = min_l;
			temp = temp->next;
			lists[idx2] = min_l->next;
		}

		return result->next;
		
	}
};