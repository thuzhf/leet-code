#pragma once

#include <vector>

class Solution {
	public:
		int maxArea(std::vector<int>& height) {
            using vst = std::vector<int>::size_type;
            vst size = height.size();
            if (size <= 1)  return 0;
            vst l = 0, r = size - 1;
            int max = 0;
            int tmp = 0;
            int pivot = 0;
            while (l < r) {
                if (height[l] <= height[r]) {
                    pivot = height[l];
                    tmp = (r - l) * pivot;
                    if (tmp > max)  max = tmp;
                    while (height[l] <= pivot)  ++l;
                } else {
                    pivot = height[r];
                    tmp = (r - l) * pivot;
                    if (tmp > max)  max = tmp;
                    while (height[r] <= pivot)  --r;
                }
            }
            return max;
        }
};

