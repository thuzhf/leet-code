#include <iostream>
#include <vector>
#include <cstdlib>

#include "permutations.hpp"

using std::cout;
using std::endl;
using std::vector;

int main()
{
	Solution sol;

	vector<int> nums;
	for (int i = 0; i < 6; ++i) {
		nums.push_back(i + 1);
	}
	vector<vector<int> > result = sol.permute(nums);
	for (auto &&i: result) {
		for (auto &&j: i) {
			cout << j << ' ';
		}
		cout << endl;
	}

	return 0;
}
