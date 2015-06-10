#ifndef MEDIAN_OF_TWO_SORTED_ARRAYS_HPP
#define MEDIAN_OF_TWO_SORTED_ARRAYS_HPP

#include <vector>
#include <iostream>

class Solution {
	public:
		double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
			auto size1 = nums1.size();
			auto size2 = nums2.size();
			auto& first = (size1 <= size2 ? nums1 : nums2);
			auto& second = (size1 <= size2 ? nums2 : nums1);
			size1 = first.size();
			size2 = second.size();
			auto total_size = size1 + size2;
			auto half = total_size / 2 - 1;

			decltype(size1) l = 0, r = size1, pilot1, pilot2;
			while (true) {
				if (1 == r - l && l != 0) {
					pilot1 = l;
					pilot2 = half - pilot1;
					break;
				} else if (0 == r) {
					pilot1 = -1;
					pilot2 = half - pilot1;
					break;
				}

				pilot1 = (l + r) / 2; // pilot1 + 1 < size1 holds
				pilot2 = half - pilot1; // pilot2 + 1 < size2 holds
				if (first[pilot1] > second[pilot2 + 1])
					r = pilot1;
				else if (second[pilot2] > first[pilot1 + 1])
					l = pilot1 + 1;
				else
					break;
			}

			double median;
			if (total_size % 2)
				median = (first[pilot1] >= second[pilot2] ? first[pilot1] : second[pilot2]);
			else
				median = (first[pilot1] + second[pilot2]) / 2.0;

			return median;
		}
};

#endif // MEDIAN_OF_TWO_SORTED_ARRAYS_HPP