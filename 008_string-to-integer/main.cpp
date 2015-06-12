#include "string-to-integer.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	Solution sol;
	string s = "-2147483648";
	cout << sol.myAtoi(s) << endl;


	return 0;
}
