#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    // O(n) time complexity
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        std::vector<ListNode*> list;
        while (current) {
            list.push_back(current);
            current = current->next;
        }
        size_t size = list.size();
        if (size >= n + 1)
            list[size - n - 1]->next = list[size - n]->next;
        else
            head = list[size - n]->next;
        delete list[size - n];

        return head;
    }
};

