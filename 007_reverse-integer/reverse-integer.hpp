#ifndef REVERSE_INTEGER_HPP_
#define REVERSE_INTEGER_HPP_

class Solution {
	public:
		int reverse(int x) {
			if (0x80000000 == x)  return 0;
			int ret = 0;
			int sign = 1;
			if (x < 0) {
				sign = -1;
				x = -x;
			}
			int special = 0x7fffffff / 10;
			int tail;
			while (x) {
				tail = x % 10;
				x /= 10;
				if (ret > special || ret == special && tail > 7)
					return 0;
				ret *= 10;
				ret += tail;
			}

			return ret * sign;
		}
};

#endif // REVERSE_INTEGER_HPP_
