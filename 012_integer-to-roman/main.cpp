#include "integer-to-roman.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
    int num;
    while (true) {
        cin >> num;
        cout << sol.intToRoman(num) << endl;
    }

	return 0;
}
