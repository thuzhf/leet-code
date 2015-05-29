#ifndef ROTATE_LIST_HPP_
#define ROTATE_LIST_HPP_

#include <vector>
#include <iostream>

using std::vector;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *rotateRight(ListNode *head, int k) {
			ListNode *ret = new ListNode(0);
			ListNode *current = ret;
			vector<int> tmp;
			while (head) {
				tmp.push_back(head->val);
				head = head->next;
			}
			unsigned n = tmp.size();
			for (unsigned i = 0; i < n; ++i) {
				unsigned index = (n - k + i) % n;
				current->val = tmp[index];
				if (n - 1 == i)  break;
				current->next = new ListNode(0);
				current = current->next;
			}

			return ret;
		}
};

#endif // ROTATE_LIST_HPP_
