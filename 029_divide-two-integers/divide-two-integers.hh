#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

class Solution {
public:
    // time complexity: O(log(dividend / divisor) ^ 2)
    // space complexity: O(1)
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1 || divisor == 0) return INT_MAX;
        if (dividend == 0) return 0;
        int sign = 1;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
            sign = -1;
        int ans = 0;
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        while (dividend <= divisor) {
            int new_divisor = divisor;
            bool overflow = false;
            int exp = 0;
            while (dividend <= new_divisor) {
                if (new_divisor >= INT_MIN / 2) {
                    new_divisor *= 2;
                    ++exp;
                } else {
                    overflow = true;
                    break;
                }
            }
            if (overflow) {
                dividend -= new_divisor;
                ans += (int) pow(2, exp);
            } else {
                dividend -= new_divisor / 2;
                ans += (int) pow(2, exp - 1);
            }
        }

        return ans * sign;
    }

    // time complexity: O(dividend / divisor)
    // space complexity: O(1)
    int divide2(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1 || divisor == 0) return INT_MAX;
        if (dividend == 0) return 0;
        int ans = 0;
        int sign = 1;
        if (dividend < 0 && divisor > 0 || dividend > 0 && divisor < 0)
            sign = -1;
        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;
        while (dividend <= divisor) {
            dividend -= divisor;
            ++ans;
        }
        return ans * sign;
    }
};

