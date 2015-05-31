#include "climbing-stairs.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Solution sol;
	int n;
	cin >> n;
	int r = sol.climbStairs(n);
	cout << r << endl;

	return 0;
}
