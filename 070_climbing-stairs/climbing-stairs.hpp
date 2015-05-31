#ifndef CLIMBING_STAIRS_HPP_
#define CLIMBING_STAIRS_HPP_

#include "../../algorithms/fibonacci/fibonacci.hpp"

#include <iostream>
#include <vector>

class Solution {
	public:
		int climbStairs(int n) {
			return zf::fibonacci(n, 1, 2);
		};
};

#endif // CLIMBING_STAIRS_HPP_
