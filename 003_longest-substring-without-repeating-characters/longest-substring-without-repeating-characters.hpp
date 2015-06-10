#ifndef LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP_
#define LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP_

#include <string>
#include <unordered_map>

class Solution {
	private:
		std::unordered_map<char, size_t> um_;

	public:
		size_t lengthOfLongestSubstring(std::string s) {
			size_t max_length = 0;
			size_t start_pos = 0;
			size_t current_length = 0;
			size_t s_length = s.size();
			for (size_t i = 0; i != s_length; i++) {
				char c = s[i];
				if (!um_.count(c)) {
					if (++current_length > max_length)
						max_length = current_length;
					um_[c] = i;
				} else {
					size_t tmp_pos = um_[c];
					if (tmp_pos < start_pos) {
						um_[c] = i;
						if (++current_length > max_length)
							max_length = current_length;
					} else {
						um_[c] = i;
						start_pos = tmp_pos + 1;
						current_length = i - start_pos + 1;
					}
				}
			}
			return max_length;
		}
};

#endif // LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_HPP_
