/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-22 17:12:05
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-22 19:44:15
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        size_t size = digits.size();
        std::string digits2;
        for (int i = 0; i < size; ++i)
            if (digits[i] != '0' && digits[i] != '1')
                digits2.push_back(digits[i]);
        size = digits2.size();
        std::vector<std::string> ans;
        if (size == 0) return ans;
        std::string mapping_table[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        std::string letters;
        std::vector<int> y(size, 0);
        int x = 0;
        while (true) {
            int d = digits2[x] - '0';
            if (x == 0 && y[x] == mapping_table[d].size())
                break;
            if (y[x] == mapping_table[d].size()) {
                --x;
                ++y[x];
                letters.pop_back();
                continue;
            }
            letters.push_back(mapping_table[d][y[x]]);
            if (x == size - 1) {
                ans.push_back(letters);
                ++y[x];
                letters.pop_back();
            } else {
                ++x;
                y[x] = 0;
            }
        }
        return ans;
    }
};

