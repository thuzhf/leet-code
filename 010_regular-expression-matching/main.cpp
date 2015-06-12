#include "regular-expression-matching.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
	string s = "b";
	string p = "b.*";
	cout << sol.isMatch(s, p) << endl;


	return 0;
}
