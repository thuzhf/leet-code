// FIXME
#include "reverse-nodes-in-k-group.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    int k = 2;
    ListNode* ans = sol.reverseKGroup(head, k);
    while (ans) {
        cout << ans->val << endl;
        ans = ans->next;
    }

	return 0;
}
