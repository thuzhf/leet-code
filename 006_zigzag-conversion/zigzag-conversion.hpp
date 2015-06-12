#ifndef ZIGZAG_CONVERSION_HPP_
#define ZIGZAG_CONVERSION_HPP_

#include <string>
#include <vector>
#include <iostream>

class Solution {
	public:
		std::string convert(std::string s, int numRows) {
			if (1 == numRows)  return s;
			if (2 == numRows) {
				auto str_size = s.size();
				std::string ret (str_size, 0);
				auto numCols = str_size / numRows;
				auto remainder = str_size % numRows;
				for (int i = 0; i < numCols + remainder; ++i)
					ret[i] = s[i * 2];
				for (int i = 0; i < numCols; ++i)
					ret[numCols + remainder + i] = s[i * 2 + 1];

				return ret;
			}

			auto str_size = s.size();
			std::string ret (str_size, 0);
			auto q = str_size / (numRows - 1);
			auto r = str_size % (numRows - 1);
			std::vector<int> row_length (numRows, 0);
			if (q % 2) {
				if (0 == r || 1 == r) {
					row_length.front() = (q + 1) / 2;
					row_length.back() = (q + 1) / 2 - 1 + r;
					for (int i = 1; i < numRows - 1; ++i)
						row_length[i] = q;
				} else {
					row_length.front() = (q + 1) / 2;
					row_length.back() = (q + 1) / 2;
					for (int i = 1; i < numRows - r; ++i)
						row_length[i] = q;
					for (int i = numRows - r; i < numRows - 1; ++i)
						row_length[i] = q + 1;
				}
			} else {
				if (0 == r) {
					row_length.front() = q / 2;
					row_length.back() = q / 2;
					for (int i = 1; i < numRows - 1; ++i)
						row_length[i] = q;
				} else {
					row_length.front() = q / 2 + 1;
					row_length.back() = q / 2;
					for (int i = 1; i < r; ++i)
						row_length[i] = q + 1;
					for (int i = r; i < numRows - 1; ++i)
						row_length[i] = q;
				}
			}

			int index;
			int ret_index = 0;
			for (int i = 0; i < numRows; ++i)
				for (int j = 0; j < row_length[i]; ++j) {
					if (0 == i)
						index = j * 2 * (numRows - 1);
					else if (numRows - 1 == i)
						index = (j * 2 + 1) * (numRows - 1);
					else if (j % 2)
						index = (j + 1) * (numRows - 1) - i;
					else
						index = j * (numRows - 1) + i;
					ret[ret_index++] = s[index];
				}

			return ret;
		}
};

#endif // ZIGZAG_CONVERSION_HPP_
