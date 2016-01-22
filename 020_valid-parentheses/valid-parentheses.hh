/* 
* @Author: zhangfang
* @Email:  thuzhf@gmail.com
* @Date:   2016-01-22 22:41:00
* @Last Modified by:   zhangfang
* @Last Modified time: 2016-01-22 22:51:34
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    // O(n)
    bool isValid(std::string s) {
        std::vector<int> stack;
        auto size = s.size();
        for (auto i = 0; i < size; ++i) {
            if (s[i] == '(') {
                stack.push_back(1);
            } else if (s[i] == ')') {
                if (!stack.empty() && stack.back() == 1)
                    stack.pop_back();
                else
                    return false;
            } else if (s[i] == '[') {
                stack.push_back(2);
            } else if (s[i] == ']') {
                if (!stack.empty() && stack.back() == 2)
                    stack.pop_back();
                else
                    return false;
            } else if (s[i] == '{') {
                stack.push_back(3);
            } else if (s[i] == '}') {
                if (!stack.empty() && stack.back() == 3)
                    stack.pop_back();
                else
                    return false;
            }
        }
        if (stack.empty())
            return true;
        else
            return false;
    }
};

