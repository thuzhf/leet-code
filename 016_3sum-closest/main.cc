// FIXME
#include "3sum-closest.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    vector<int> nums {-1, 2, 1, -4};
    int ans = sol.threeSumClosest(nums, 1);
    cout << ans << endl;

	return 0;
}
