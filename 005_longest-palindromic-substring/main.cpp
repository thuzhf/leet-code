#include "longest-palindromic-substring.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
	string s ("1234321456787654");
	cout << sol.longestPalindrome(s) << endl;

	return 0;
}
