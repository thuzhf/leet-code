#ifndef LONGEST_PALINDROMIC_SUBSTRING_HPP_
#define LONGEST_PALINDROMIC_SUBSTRING_HPP_

#include <iostream>
#include <string>
#include <vector>

class Solution {
	public:
		std::string longestPalindrome(std::string s) {
			// Manacher's algorithm (time complexity: O(n))
			// 1. 对于s中的每个已经探索过的字符，记录以该字符为中心的最长的回文串的长度到向量v中。
			// 2. 记录到目前为止所有最长回文串中最右端字符的位置c以及该回文串中心字符的位置b（或者最左端字符的位置a）。
			// 3. 遍历s中的每个字符t，如果该字符位于c之后，那么就以该字符为中心检测并记录最长回文串，同时更新全局的最长回文串的长度以及位置；
			// 4. 如果该字符位于c或者c之前，那么找到该字符以b为对称中心的对应点，然后在v中查看该对应点处的最长回文串长度，如果该长度小于该点与a的距离，那么字符t处的最长的回文串的长度就是对应点处的最长回文串的长度；
			// 5. 如果该长度不小于该点与a的距离，那么字符t处的最长回文串的长度将至少是这个距离，然后我们只要从c之后的字符开始进行回文检测就好。
			// 6. 因此对于每个字符，我们都是进行常数时间的操作，这样总的时间复杂度将为O(n)。\
			// 7. 优化：判断当前字符的位置与终点字符的距离，然后与全局的最长回文串的距离进行比对，这样可以提前结束查找过程；同时在原始字符串中的任意两个字符中间以及开头和结尾处分别插入同一个特殊字符，这样可以使得新字符串中的所有最长回文串都是奇数长度，方便统一处理。
			if (s.empty())  return "";
			using sst = std::string::size_type;
			sst string_size = s.size();
			sst mystr_size = string_size * 2 + 1;
			char C = '\a';
			std::string mystr (mystr_size, C);
			for (sst i = 0; i < string_size; ++i)
				mystr[i * 2 + 1] = s[i];
			
			std::vector<sst> all_max (mystr_size, 1);
			sst gmax = 0;
			sst gleft = 0;
			sst gright = 0;
			sst rightmost = 0;
			sst left_of_rightmost = 0;
			for (sst i = 0; i < mystr_size; ++i) {
				if (mystr_size - i <= gmax)
					break;
				if (i >= rightmost) {
					sst l = i - 1, r = i + 2;
					while (l != -1 && r <= mystr_size && mystr[l] == mystr[r - 1]) {
						--l; ++r;
					}
					++l; --r;
					rightmost = r;
					left_of_rightmost = l;
					sst tmp_max = (r - l) / 2 + 1;
					all_max[i] = tmp_max;
					if (tmp_max > gmax) {
						gmax = tmp_max;
						gleft = l;
						gright = r;
					}
				} else {
					sst mirror_pos = rightmost - 1 + left_of_rightmost - i;
					sst mirror_max = all_max[mirror_pos];
					sst tmp_distance = mirror_pos - left_of_rightmost;
					if (mirror_max - 1 < tmp_distance)
						all_max[i] = mirror_max;
					else {
						sst r = rightmost + 1;
						sst l = i * 2 - (r - 1);
						while (l != -1 && r <= mystr_size && mystr[l] == mystr[r - 1]) {
							--l; ++r;
						}
						++l; --r;
						rightmost = r;
						left_of_rightmost = l;
						sst tmp_max = (r - l) / 2 + 1;
						all_max[i] = tmp_max;
						if (tmp_max > gmax) {
							gmax = tmp_max;
							gleft = l;
							gright = r;
						}
					}
				}
			}
			return s.substr(gleft / 2, gmax - 1);
		}
};

#endif // LONGEST_PALINDROMIC_SUBSTRING_HPP_
