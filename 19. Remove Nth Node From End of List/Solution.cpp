/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* curr = head;
		ListNode* prev = head;

		for (int i = 0; i < n; i++) {
			curr = curr->next;
		}

		//if 1 node;
		if (curr == nullptr) {
			return head->next; // nullptr
		}
	

		while (curr->next != nullptr) {
			prev = prev->next;
			curr = curr->next;
		}

		prev->next = prev->next->next;
		return head;
	}
};