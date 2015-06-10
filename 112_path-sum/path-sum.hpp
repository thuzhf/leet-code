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
			if (!root)
				return false;
			TN_.push_back(std::forward_as_tuple(root, 0));
			int current_sum;
			while (!TN_.empty()) {
				auto current = TN_.back();
				TN_.pop_back();
				auto&& node = std::get<0>(current);
				auto&& history_sum = std::get<1>(current);
				current_sum = history_sum + node->val;
				if (!node->left && !node->right && current_sum == sum)
					return true;
				if (node->left)
					TN_.push_back(std::forward_as_tuple(node->left, current_sum));
				if (node->right)
					TN_.push_back(std::forward_as_tuple(node->right, current_sum));
			}
			return false;
		}
};

#endif // PATH_SUM_HPP_
