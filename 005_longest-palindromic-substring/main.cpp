#include "longest-palindromic-substring.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
	string s;
	cin >> s;
	cout << sol.longestPalindrome(s) << endl;

	return 0;
}
