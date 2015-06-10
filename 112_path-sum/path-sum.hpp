#ifndef PATH_SUM_HPP_
#define PATH_SUM_HPP_

#include <vector>
#include <tuple>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
	private:
		std::vector<std::tuple<TreeNode*, int> > TN_;


	public:
		bool hasPathSum(TreeNode* root, int sum) {
			if (!root || root->val > sum)
				return false;
			else if (root->val == sum)
				return true;

			TN_.push_back(std::forward_as_tuple(root, root->val));
			int left_part_sum = 0;
			int right_part_sum = 0;
			while (!TN_.empty()) {
				auto current = TN_.back();
				TN_.pop_back();
				auto&& node = std::get<0>(current);
				auto&& part_sum = std::get<1>(current);
				if (node->left) {
					left_part_sum = node->left->val + part_sum;
					if (left_part_sum == sum)
						return true;
					else if (left_part_sum < sum)
						TN_.push_back(std::forward_as_tuple(node->left, left_part_sum));
				}
				if (node->right) {
					right_part_sum = node->right->val + part_sum;
					if (right_part_sum == sum)
						return true;
					else if (left_part_sum < sum)
						TN_.push_back(std::forward_as_tuple(node->right, right_part_sum));
				}
			}
			return false;
		}
};

#endif // PATH_SUM_HPP_
