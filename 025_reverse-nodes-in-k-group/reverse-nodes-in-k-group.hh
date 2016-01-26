#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1 || !head) return head;
        ListNode* ans = head;
        ListNode* current = head;
        ListNode** arr = new ListNode* [k];
        ListNode* last = nullptr;
        ListNode* next;
        bool over = false;
        while (true) {
            for (auto i = k - 1; i >= 0; --i) {
                if (current) {
                    arr[i] = current;
                    current = current->next;
                } else {
                    over = true;
                    break;
                }
            }
            if (over) break;
            if (!last) {
                ans = arr[0];
            } else {
                last->next = arr[0];
            }
            for (auto i = 0; i < k; ++i) {
                if (i == 0)
                    next = arr[i]->next;
                if (i < k - 1)
                    arr[i]->next = arr[i + 1];
                else
                    arr[i]->next = next;
            }
            last = arr[k - 1];
            current = last->next;
        }
        return ans;
    }
};

