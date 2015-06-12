#include "regular-expression-matching.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
	string s = "asdf;ljk";
	string p = ".*9*a*f*g*v*c*o*e*";
	cout << sol.isMatch(s, p) << endl;


	return 0;
}
