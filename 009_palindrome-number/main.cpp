#include "palindrome-number.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
	int x;
	cin >> x;
	cout << "x: " << x << endl;
	cout << sol.isPalindrome(x) << endl;

	return 0;
}
