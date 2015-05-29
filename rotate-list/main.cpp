#include <iostream>

#include "rotate-list.hpp"

using std::cout;
using std::endl;

int main()
{
	Solution sol;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	int k = 0;

	ListNode *result = sol.rotateRight(head, k);
	while (result) {
		cout << result->val << endl;
		result = result->next;
	}

	return 0;
}
