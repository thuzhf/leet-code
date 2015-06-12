#include "reverse-integer.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
	int x;
	cin >> x;
	int r = sol.reverse(x);
	cout << r << endl;

	return 0;
}
