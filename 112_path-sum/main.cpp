#include "path-sum.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Solution sol;
	TreeNode* root = new TreeNode(22);
	root->left = new TreeNode(4);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(11);
	root->left->left->right = new TreeNode(2);

	bool ret = sol.hasPathSum(root, 22);
	cout << ret << endl;

	return 0;
}
