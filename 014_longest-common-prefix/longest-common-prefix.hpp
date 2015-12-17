#pragma once

#include <string>
#include <vector>

class Solution {
	public:
        std::string longestCommonPrefix(std::vector<std::string>& strs) {
            using vst = std::vector<std::string>::size_type;
            using sst = std::string::size_type;
            std::string result;
            char tmp;
            sst index = 0;
            bool flag = true;
            if (strs.size() == 0)
                flag = false;
            while (flag) {
                for (vst i = 0; i < strs.size(); ++i) {
                    if (index >= strs[i].size()) {
                        flag = false;
                        break;
                    }
                    if (i == 0)
                        tmp = strs[i][index];
                    else if (strs[i][index] != tmp) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    result.push_back(tmp);
                    ++index;
                } else
                    break;
            }
            return result;
        }
};

