#pragma once

#include <string>

class Solution {
	public:
	    std::string intToRoman(int num) {
            std::string result;
            const char* hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
            const char* tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
            const char* ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

            int tmp = num / 1000;
            num %= 1000;
            result.append(tmp, 'M');
            tmp = num / 100;
            num %= 100;
            result.append(hundreds[tmp]);
            tmp = num / 10;
            num %= 10;
            result.append(tens[tmp]);
            tmp = num / 1;
            num %= 1;
            result.append(ones[tmp]);
            return result;
        }
};

