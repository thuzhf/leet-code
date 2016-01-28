// FIXME
#include "implement-strstr.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    string s1 = "1235123671234567890";
    string s2 = "1234";
    int ans = sol.strStr(s1, s2);
    cout << ans << endl;

	return 0;
}
