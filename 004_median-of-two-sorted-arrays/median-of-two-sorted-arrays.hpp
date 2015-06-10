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
			auto half = (total_size - 1) / 2 - 1;
			double median;
			if (!size1) {
				if (!size2) {
					median = 0;
					return median;
				}
				if (size2 % 2)
					median = second[size2 / 2];
				else
					median = (second[size2 / 2 - 1] + second[size2 / 2]) / 2.0;
				return median;
			}

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

				pilot1 = (l + r) / 2;
				pilot2 = half - pilot1;
				if (pilot2 + 1 < size2 && first[pilot1] > second[pilot2 + 1])
					r = pilot1;
				else if (pilot1 + 1 < size1 && second[pilot2] > first[pilot1 + 1])
					l = pilot1 + 1;
				else
					break;
			}

			if (total_size % 2)
				median = (first[pilot1] >= second[pilot2] ? first[pilot1] : second[pilot2]);
			else {
				int l_max = 0, r_min = 0;
				if (pilot1 >= 0 && pilot2 >= 0)
					l_max = (first[pilot1] >= second[pilot2] ? first[pilot1] : second[pilot2]);
				else if (pilot1 >= 0)
					l_max = first[pilot1];
				else if (pilot2 >= 0)
					l_max = second[pilot2];

				if (pilot1 + 1 < size1 && pilot2 + 1 < size2)
					r_min = (first[pilot1 + 1] < second[pilot2 + 1] ? first[pilot1 + 1] : second[pilot2 + 1]);
				else if (pilot1 + 1 < size1)
					r_min = first[pilot1 + 1];
				else if (pilot2 + 1 < size2)
					r_min = second[pilot2 + 1];
				median = (l_max + r_min) / 2.0;
			}

			return median;
		}
};

#endif // MEDIAN_OF_TWO_SORTED_ARRAYS_HPP
