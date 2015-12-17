#include "container-with-most-water.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    vector<int> height({1,4,3,4});
    cout << sol.maxArea(height) << endl;

	return 0;
}
