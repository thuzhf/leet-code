/* 
* @Author: zhangfang
* @Date:   2016-01-22 12:31:27
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-22 15:02:05
*/
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        using vst = std::vector<int>::size_type;
        vst nums_size = nums.size();
        std::vector<std::vector<int> > ans;
        if (nums_size < 3) return ans;

        for (vst i = 0; i < nums_size; ++i) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            vst j = i + 1, k = nums_size - 1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if (s < 0) ++j;
                else if (s > 0) --k;
                else {
                    ans.push_back(std::vector<int> {nums[i], nums[j], nums[k]});
                    while (j + 1 < k && nums[j] == nums[j + 1]) ++j;
                    while (k - 1 > j && nums[k] == nums[k - 1]) --k;
                    ++j; --k;
                }
            }
        }
        return ans;
    }
};

