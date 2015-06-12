#ifndef REGULAR_EXPRESSION_MATCHING_HPP_
#define REGULAR_EXPRESSION_MATCHING_HPP_

#include <string>
#include <iostream>
#include <utility>
#include <vector>

struct Match {
	using sst = std::string::size_type;
	sst sindex;
	sst pindex;
	Match(sst s = 0, sst p = 0): sindex(s), pindex(p) {}
};

class Solution {
	private:
		std::vector<std::vector<Match> > match_;
		bool backtrack(std::string::size_type& sindex, std::string::size_type& pindex) {
			if (match_.empty())
				return false;
			else {
				sindex = match_.back().back().sindex;
				pindex = match_.back().back().pindex;
				match_.back().pop_back();
				if (match_.back().empty())
					match_.pop_back();
				return true;
			}
		}

	public:
		bool isMatch(std::string s, std::string p) {
			using sst = std::string::size_type;
			sst sindex = 0, pindex = 0;
			while (true) {
				if (pindex == p.size()) { // if p reaches end
					if (sindex == s.size()) // if s reaches end, then succeed
						return true;
					else if (!backtrack(sindex, pindex))
						return false;
				} else { // if p doesn't reach end, then continue matching
					if (pindex + 1 < p.size() && p[pindex + 1] == '*') { // if next is *, may produce branch
						if (p[pindex] == '.') { // produce many branches
							std::vector<Match> tmp;
							pindex += 2;
							while (sindex < s.size())
								tmp.push_back(Match(sindex++, pindex));
							match_.push_back(std::move(tmp));
						} else {
							if (s[sindex] == p[pindex]) {
								std::vector<Match> tmp;
								char c = p[pindex];
								pindex += 2;
								while (sindex < s.size() && s[sindex] == c)
									tmp.push_back(Match(sindex++, pindex));
								match_.push_back(std::move(tmp));
							} else {
								pindex += 2;
							}
						}
					} else { // if next is not *, then simply compare s and p
						if (s[sindex] == p[pindex]) {
							++sindex;
							++pindex;
						} else if (!backtrack(sindex, pindex))
							return false;
					}
				}
			}
		}
};

#endif // REGULAR_EXPRESSION_MATCHING_HPP_
