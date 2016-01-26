#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int a): val(a), next(NULL) {}
};

class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(1)
    ListNode* swapPairs(ListNode* head) {
        ListNode* current = head;
        ListNode* last = nullptr;
        ListNode* next;
        ListNode* ans = head;
        while (current && current->next) {
            if (last) {
                last->next = current->next;
            } else {
                ans = current->next;
            }
            last = current;
            next = current->next->next;
            current->next->next = current;
            current->next = next;
            current = next;
        }
        return ans;
    }
};

