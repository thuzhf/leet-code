// FIXME
#include "4sum.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    vector<int> nums {1, 0, -1, 0, -2, 2};
    int target = 0;
    std::vector<std::vector<int> > ans = sol.fourSum(nums, target);
    for (auto i = 0; i < ans.size(); ++i) {
        for (auto j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
