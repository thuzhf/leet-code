#ifndef PALINDROME_HPP_
#define PALINDROME_HPP_

#include <vector>
#include <climits>

class Solution {
	public:
		bool isPalindrome(int x) {
			if (x / 10 == 0)  return true;
			if (x % 10 == 0)  return false;
			if (x == INT_MIN) return false;
			if (x < 0)  x = -x;
			std::vector<int> digits;
			while (x) {
				digits.push_back(x % 10);
				x /= 10;
			}
			auto digits_size = digits.size();
			auto half_size = digits_size / 2;
			for (int i = 0; i < half_size; ++i)
				if (digits[i] != digits[digits_size - 1 - i])
					return false;
			return true;
		}
};

#endif // PALINDROME_HPP_
