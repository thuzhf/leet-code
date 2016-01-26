// FIXME
#include "generate-parentheses.hh"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    vector<int> ans;
    for (int i = 1; i <= 15; ++i) {
        std::vector<std::string> str = sol.generateParenthesis(i);
        ans.push_back(str.size());
    }
    for (auto i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }

	return 0;
}
