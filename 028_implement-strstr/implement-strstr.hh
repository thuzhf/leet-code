/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-26 21:48:37
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-26 22:09:00
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // time complexity: O(n1*n2)
    // space complexity: O(1)
    int strStr(std::string haystack, std::string needle) {
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

