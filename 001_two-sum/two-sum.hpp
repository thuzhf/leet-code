#include <vector>
#include <unordered_map>
#include <utility>

class Solution {
	private:
		std::unordered_map<int, int> um_;
		std::vector<int> v_;

	public:
		std::vector<int> twoSum(std::vector<int> &nums, int target) {
			using vi_st = std::vector<int>::size_type;
			vi_st l = nums.size();
			for (vi_st i = 0; i < l; ++i) {
				std::pair<int, int> tmp(nums[i], i);
				um_.insert(tmp);
				v_.push_back(target - nums[i]);
			}
			for (vi_st i = 0; i < l; ++i) {
				if (1 == um_.count(v_[i]) && i != um_[v_[i]]) {
					std::vector<int> tmp;
					int a = i, b = um_[v_[i]];
					if (a > b) {
						int t = a;
						a = b;
						b = t;
					}
					tmp.push_back(a + 1);
					tmp.push_back(b + 1);
					return tmp;
				}
			}
		}
};
