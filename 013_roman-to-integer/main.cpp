// FIXME
#include "roman-to-integer.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    string s;
    while (true) {
        cin >> s;
        cout << sol.romanToInt(s) << endl;
    }

	return 0;
}
