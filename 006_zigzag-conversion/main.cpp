#include "zigzag-conversion.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
	string s ("PAYPALISHIRING");
	cout << sol.convert(s, 3) << endl;

	return 0;
}
