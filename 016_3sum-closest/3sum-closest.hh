/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-22 15:16:18
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-22 17:07:22
*/

#pragma once
#include <cstdlib>
#include <climits>
#include <vector>
#include <algorithm>

class Solution {
private:
    int best_;
    unsigned diff_;

public:
    Solution(): diff_(UINT_MAX) {}
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        using vst = std::vector<int>::size_type;
        vst nums_size = nums.size();

        for (vst i = 0; i < nums_size; ++i) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            vst j = i + 1, k = nums_size - 1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                unsigned diff = abs(s - target);
                if (diff < diff_) {
                    diff_ = diff;
                    best_ = s;
                }
                if (s < target) ++j;
                else if (s > target) --k;
                else return target;
            }
        }
        return best_;
    }
};

