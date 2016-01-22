// FIXME
#include "letter-combinations-of-a-phone-number.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    std::string digits = "13";
    std::vector<std::string> ans = sol.letterCombinations(digits);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

	return 0;
}
