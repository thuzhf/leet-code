/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-26 21:32:41
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-26 21:37:24
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
    int removeDuplicates(std::vector<int>& nums) {
        auto size = nums.size();
        int ans = 0;
        if (!size) return 0;
        for (auto i = 0; i < size; ++i) {
            if (i >= 1 && nums[i] == nums[i - 1])
                continue;
            nums[ans++] = nums[i];
        }
        return ans;
    }
};

