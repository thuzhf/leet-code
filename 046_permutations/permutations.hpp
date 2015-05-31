#ifndef PERMUTATIONS_HPP
#define PERMUTATIONS_HPP

#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution {
	public:
		vector<vector<int> > permute(vector<int> &nums){
			std::sort(nums.begin(), nums.end());
			vector<vector<int> > ret;
			unsigned n = nums.size();
			bool all_found = false;
			while (true) {
				ret.push_back(nums);
				unsigned index;
				for (unsigned i = n - 1; i >= 0; --i) {
					if (0 == i) {
						all_found = true;
						break;
					} else if (nums[i - 1] < nums[i]) {
						index = i - 1;
						int tmp;
						for (unsigned j = index + 1; j < n; ++j) {
							if (n == j + 1 || nums[j + 1] <= nums[index]) {
								tmp = nums[j];
								nums[j] = nums[index];
								nums[index] = tmp;
								for (unsigned k = (n + index) / 2 + 1; k < n; ++k) {
									tmp = nums[k];
									nums[k] = nums[n + index - k];
									nums[n + index - k] = tmp;
								}
								break;
							}
						}
						break;
					}
				}
				if (all_found)  break;
			}

			return ret;
		}
};

#endif // PERMUTATIONS_HPP
