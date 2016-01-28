/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-26 21:48:37
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-28 20:24:13
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
private:
    int* next_table_ = nullptr;
public:
    ~Solution() {
        if (next_table_)
            delete [] next_table_;
    }
    // KMP algorithm
    // time complexity: O(n1 + n2)
    // space complexity: O(n1)
    int strStr(std::string haystack, std::string needle) {
        build_next_table(needle);
        auto size1 = haystack.size();
        auto size2 = needle.size();
        int i = 0, j = 0;
        while (i + size2 <= size1) {
            j = 0;
            while (j < size2 && needle[j] == haystack[i + j]) ++j;
            if (j == size2) return i;
            i = i + j - next_table_[j];
        }
        return -1;
    }

    void build_next_table(std::string needle) {
        auto size = needle.size();
        next_table_ = new int[size + 1];
        next_table_[0] = -1;
        next_table_[1] = 0;
        for (int i = 2, next = next_table_[1]; i <= size; ++i) {
            while (true) {
                if (next >= 0) {
                    if (needle[next] == needle[i - 1]) {
                        next_table_[i] = next + 1;
                        next = next_table_[i];
                        break;
                    } else {
                        next = next_table_[next];
                    }
                } else {
                    next_table_[i] = 0;
                    next = next_table_[i];
                    break;
                }
            }
        }
    }

    // time complexity: O(n1*n2)
    // space complexity: O(1)
    int strStr2(std::string haystack, std::string needle) {
        auto size1 = haystack.size();
        auto size2 = needle.size();
        int ans = -1;
        bool has;
        if (size2 == 0) return 0;
        for (auto i = 0; i < size1; ++i) {
            if (size1 - i < size2) return -1;
            has = true;
            auto previous = i;
            for (auto j = 0; j < size2; ++j) {
                if (i < size1 && needle[j] == haystack[i])
                    ++i;
                else {
                    has = false;
                    break;
                }
            }
            if (has) {
                ans = previous;
                return ans;
            }
            i = previous;
        }
        return ans;
    }
};

