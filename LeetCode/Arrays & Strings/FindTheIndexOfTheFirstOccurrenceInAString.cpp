#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {

		if (haystack.size() < needle.size()) 
			return -1;

		int i = 0, j = 0;

		for (; i < haystack.size(); i++) {
			if (j == needle.size()) {
				return i - j;
			} 

			if (haystack[i] == needle[j]) {
				j++;
				continue;
			} 

			j = 0;
		}

		if (j == needle.size()) {
			return i - j;
		} 

		return -1;
    }
};

int main () {
	Solution s;
	string haystack = "mississippi", needle = "issip";

	int result = s.strStr(haystack, needle);

	cout << result << endl;

	return 0;
}