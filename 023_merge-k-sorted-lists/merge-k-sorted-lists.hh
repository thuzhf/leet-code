/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-26 17:35:22
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-26 20:08:27
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(NULL) {}
};

bool zf_greater(const ListNode* l1, const ListNode* l2) {
    return l1->val > l2->val;
}

class Solution {
public:
    // time complexity: O(log(k) * (n_1 + n_2 + ... + n_k))
    // space complexity: O(n_1 + n_2 + ... + n_k)
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        ListNode* ans;
        ListNode* last = nullptr;
        auto size = lists.size();
        std::vector<ListNode*> heap;
        for (auto i = 0; i < size; ++i) {
            if (lists[i])
                heap.push_back(lists[i]);
        }
        if (!heap.size()) return nullptr;
        std::make_heap(heap.begin(), heap.end(), zf_greater);
        ans = heap.front();
        while (!heap.empty()) {
            std::pop_heap(heap.begin(), heap.end(), zf_greater);
            if (last) {
                last->next = heap.back();
                last = last->next;
            } else {
                last = heap.back();
            }
            if (!last->next) {
                heap.resize(heap.size() - 1);
            } else {
                heap.back() = last->next;
                std::push_heap(heap.begin(), heap.end(), zf_greater);
            }
        }

        return ans;
    }
};

