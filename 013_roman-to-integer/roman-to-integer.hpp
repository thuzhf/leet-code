#pragma once

#include <string>

class Solution {
    private:
        static const int length = 13;
        const char* startwith[length] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        const int number[length] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    public:
		int romanToInt(std::string& s) {
            std::string s1[] = {s.substr(0, 1), s.substr(0, 2)};
            std::string s2[] = {"", ""};
            if (s.size() >= 2)  s2[0] = s.substr(1);
            if (s.size() >= 3)  s2[1] = s.substr(2);
            int parity;
            for (int i = 0; i < length; ++i) {
                parity = i % 2;
                if (s1[parity].compare(startwith[i]) == 0)
                    return number[i] + romanToInt(s2[parity]);
            }
            return 0;
        }
};

