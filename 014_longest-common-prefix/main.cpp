// FIXME
#include "longest-common-prefix.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    vector<string> strs = {"asdf", "ascv", "as43"};
    cout << sol.longestCommonPrefix(strs) << endl;

	return 0;
}
