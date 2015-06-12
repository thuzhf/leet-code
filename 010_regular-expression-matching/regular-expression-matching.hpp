#ifndef REGULAR_EXPRESSION_MATCHING_HPP_
#define REGULAR_EXPRESSION_MATCHING_HPP_

#include <string>
#include <iostream>

class Solution {
	public:
		bool isMatch(std::string s, std::string p) {
			using sst = std::string::size_type;
			sst sindex = 0, pindex = 0;
			while (true) {
				if (pindex == p.size()) {
					if (sindex == s.size())
						return true;
					else
						return false;
				}

				if (pindex + 1 < p.size() && p[pindex + 1] == '*') { // if next is *
					if (sindex >= s.size()) {
						pindex += 2;
					} else {
						if (p[pindex] == '.') {
							sindex = s.size();
							pindex += 2;
						} else {
							while (sindex < s.size() && s[sindex] == p[pindex])
								++sindex;
							pindex += 2;
						}
					}
				} else { // if this is last char or the next is not *
					if (sindex >= s.size() || p[pindex] != '.' && s[sindex] != p[pindex])
						return false;
					else {
						++sindex;
						++pindex;
					}
				}
				std::cout << sindex << ' ' << pindex << std::endl;
			}
		}
};

#endif // REGULAR_EXPRESSION_MATCHING_HPP_
