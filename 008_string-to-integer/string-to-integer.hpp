#ifndef STRING_TO_INTEGER_HPP_
#define STRING_TO_INTEGER_HPP_

#include <string>
#include <iostream>

class Solution {
	private:
		bool isDigit(const char& c) {
			if ('0' <= c && c <= '9')
				return true;
			else
				return false;
		}

	public:
		int myAtoi(std::string str) {
			int ret = 0;
			int sign = 1;
			auto str_size = str.size();
			std::string whitespace = " ";
			auto start = str.find_first_not_of(whitespace);
			int special = 0x7fffffff / 10;
			if (str[start] == '+') {
				++start;
				sign = 1;
			} else if (str[start] == '-') {
				++start;
				sign = -1;
			}

			while (true)
				if (start >= str_size || !isDigit(str[start])) {
					return ret * sign;
				} else {
					int tmp = str[start] - '0';
					if (ret > special || ret == special && (tmp > 8 || tmp == 8 && sign == 1)) {// overflow
						if (sign == 1)  return 0x7fffffff;
						if (sign == -1)  return 0x80000000;
					} else if (ret == special && tmp == 8 && sign == -1) {
						if (start + 1 == str_size || !isDigit(str[start + 1])) {
							ret = ret * 10 + tmp; // 0x8fffffff
							return ret;
						} else
							return 0x80000000;
					} else {
						ret = ret * 10 + tmp;
						++start;
					}
				}
		}
};

#endif // STRING_TO_INTEGER_HPP_
