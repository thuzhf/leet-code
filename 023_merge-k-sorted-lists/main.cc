// FIXME
#include "merge-k-sorted-lists.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(9);
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(6);
    std::vector<ListNode*> lists;
    lists.push_back(l1);
    lists.push_back(l2);
    ListNode* ans = sol.mergeKLists(lists);
    while (ans) {
        cout << ans->val << endl;
        ans = ans->next;
    }

	return 0;
}
