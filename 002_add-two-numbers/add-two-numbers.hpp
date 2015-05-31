#ifndef ADD_TWO_NUMBERS_HPP
#define ADD_TWO_NUMBERS_HPP

#include <cstdlib>
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
			ListNode *current = new ListNode(0);
			ListNode *ret = current;
			// state = 0 means neither l1 or l2 is NULL;
			// state = 1 means l2 = NULL but l1 not;
			// state = 2 means l1 = NULL but l2 not.
			int state = 0;
			int l1_val = 0, l2_val = 0;
			int carry = 0;
			int s = 0;
			int unit = 0;
			while(true) {
				if (0 == state) {
					l1_val = l1->val;
					l2_val = l2->val;
				} else if (1 == state) {
					l1_val = l1->val;
					l2_val = 0;
				} else if (2 == state) {
					l1_val = 0;
					l2_val = l2->val;
				}

				s = l1_val + l2_val + carry;
				carry = s / 10;
				unit = s % 10;
				current->val = unit;
				if (l1)  l1 = l1->next;
				if (l2)  l2 = l2->next;
				if (NULL == l1 && NULL == l2) {
					if (carry)  current->next = new ListNode(carry);
					break;
				} else if (NULL == l1)
					state = 2;
				else if (NULL == l2)
					state = 1;
				else
					state = 0;
				current->next = new ListNode(0);
				current = current->next;
			}

			return ret;
		}
};

#endif // ADD_TWO_NUMBERS_HPP
