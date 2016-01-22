/* 
* @Author: zhangfang
* @Date:   2016-01-22 12:31:27
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-22 14:04:38
*/
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int> > threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int nums_size = nums.size();
        std::vector<std::vector<int> > ans;
        
        for (int i = 0; i < nums_size; ++ i) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            for (int j = i + 1; j < nums_size; ++ j) {
                if (j > i + 1 && nums[j - 1] == nums[j])
                    continue;
                for (int k = j + 1; k < nums_size; ++ k) {
                    if (k > j + 1 && nums[k - 1] == nums[k])
                        continue;
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        ans.push_back(std::vector<int>({nums[i], nums[j], nums[k]}));
                    }
                }
            }
        }
        return ans;
    }
};

