#include <iostream>

#include "add-two-numbers.hpp"

using namespace std;

int main()
{
	Solution sol;
	// l1: 765; l2: 87; sum = 852.
	ListNode *l1 = new ListNode(5);
	//l1->next = new ListNode(6);
	//l1->next->next = new ListNode(7);
	ListNode *l2 = new ListNode(5);
	//l2->next = new ListNode(8);
	
	ListNode *l3 = sol.addTwoNumbers(l1, l2);
	while (l3) {
		cout << l3->val;
		l3 = l3->next;
	}
	cout << endl;

	return 0;
}
