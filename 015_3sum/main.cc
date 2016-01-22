// FIXME
#include "3sum.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    vector<int> nums ({0, 0, 0});
    std::vector<std::vector<int> > ans = sol.threeSum(nums);
    for (int i = 0; i < ans.size(); ++ i) {
        for (int j = 0; j < ans[i].size(); ++ j) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

	return 0;
}
