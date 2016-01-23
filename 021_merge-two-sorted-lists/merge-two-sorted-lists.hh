/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-23 19:36:37
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-23 21:54:42
*/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        ListNode* tail = nullptr;
        if (!l1) return l2;
        if (!l2) return l1;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                if (!tail) {
                    tail = l1;
                    ans = l1;
                    l1 = l1->next;
                } else {
                    tail->next = l1;
                    tail = l1;
                    l1 = l1->next;
                }
            } else {
                if (!tail) {
                    tail = l2;
                    ans = l2;
                    l2 = l2->next;
                } else {
                    tail->next = l2;
                    tail = l2;
                    l2 = l2->next;
                }
            }
        }
        if (!l1) {
            tail->next = l2;
        } else {
            tail->next = l1;
        }
        return ans;
    }
};

