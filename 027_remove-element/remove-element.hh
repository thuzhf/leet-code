/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-26 21:39:23
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-26 21:47:24
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // time complexity: O(n)
    // space complexity: O(1)
    int removeElement(std::vector<int>& nums, int val) {
        auto size = nums.size();
        decltype(size) index = 0;
        for (auto i = 0; i < size; ++i) {
            if (nums[i] != val) {
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

