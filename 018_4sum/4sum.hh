/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-22 21:43:19
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-22 22:17:14
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // O(n^3) time complexity
    std::vector<std::vector<int> > fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int> > ans;
        size_t size = nums.size();
        if (size < 4) return ans;
        for (size_t i = 0; i < size - 3; ++i) {
            if (i >0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[size - 1] + nums[size - 2] + nums[size - 3] < target)
                continue;
            int target_for_three_sum = target - nums[i];
            std::vector<int> nums_for_three_sum(nums.begin() + i + 1, nums.end());
            std::vector<std::vector<int> > ans_of_three_sum = threeSum(nums_for_three_sum, target_for_three_sum);
            size_t size_of_three_sum = ans_of_three_sum.size();
            for (size_t j = 0; j < size_of_three_sum; ++j) {
                ans.push_back(std::vector<int> {nums[i], ans_of_three_sum[j][0], \
                    ans_of_three_sum[j][1], ans_of_three_sum[j][2]});
            }
        }
        return ans;
    }

    std::vector<std::vector<int> > threeSum(std::vector<int>& nums, int target) {
        // std::sort(nums.begin(), nums.end());
        using vst = std::vector<int>::size_type;
        vst nums_size = nums.size();
        std::vector<std::vector<int> > ans;
        if (nums_size < 3) return ans;

        for (vst i = 0; i < nums_size - 2; ++i) {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > target)
                break;
            if (nums[i] + nums[nums_size - 1] + nums[nums_size - 2] < target)
                continue;
            vst j = i + 1, k = nums_size - 1;
            while (j < k) {
                int s = nums[i] + nums[j] + nums[k];
                if (s < target) ++j;
                else if (s > target) --k;
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
