#include "longest-substring-without-repeating-characters.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Solution sol;
	string s = "abcaadef";
	size_t ret = sol.lengthOfLongestSubstring(s);
	cout << ret << endl;

	return 0;
}
