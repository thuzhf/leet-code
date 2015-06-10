#include "median-of-two-sorted-arrays.hpp"

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	Solution sol;
	vector<int> nums1({2,3}), nums2({1,4});
	double median = sol.findMedianSortedArrays(nums1, nums2);
	cout << median << endl;

	return 0;
}
