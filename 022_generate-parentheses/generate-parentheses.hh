/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-23 22:03:28
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-23 23:38:29
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // iterative backtracking
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<int> num_right_parenthesis(n, 0);
        int num_used = 0;
        int current_position = 0;
        std::vector<std::string> ans;
        if (n == 1) {
            ans.push_back("()");
            return ans;
        }
        while (true) {
            if (current_position == 0 && num_right_parenthesis[current_position] > current_position + 1 - num_used)
                break;
            if (num_right_parenthesis[current_position] > current_position + 1 - num_used) {
                num_right_parenthesis[current_position] = 0;
                --current_position;
                num_used -= num_right_parenthesis[current_position];
                ++num_right_parenthesis[current_position];
                continue;
            }
            num_used += num_right_parenthesis[current_position];
            ++current_position;
            if (current_position == n - 1) {
                num_right_parenthesis[current_position] = current_position + 1 - num_used;
                std::string tmp;
                for (auto i = 0; i < n; ++i) {
                    tmp.push_back('(');
                    for (auto j = 0; j < num_right_parenthesis[i]; ++j) {
                        tmp.push_back(')');
                    }
                }
                ans.push_back(tmp);
                --current_position;
                num_used -= num_right_parenthesis[current_position];
                ++num_right_parenthesis[current_position];
            }
        }
        return ans;
    }
};

