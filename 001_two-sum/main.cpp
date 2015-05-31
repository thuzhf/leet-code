#include "two-sum.hpp"

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

int main()
{
	Solution sol;
	vector<int> nums = {7,9,4,3,8};
	int target = 7;
	vector<int> r = sol.twoSum(nums, target);
	for (int i = 0; i < r.size(); ++i)
		cout << r[i] << ' ';
	cout << endl;

	return 0;
}
