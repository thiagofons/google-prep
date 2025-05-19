#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int end = s.size() - 1;

		while (s[end] == ' ') 
			end--;

		int start = end;

		while (s[start] != ' ' && start >= 0) {
			start--;
		}

		return end - start;
	}
};

int main() {
	Solution s;
	string phrase = "a";

	int length = s.lengthOfLastWord(phrase);

	cout << length << endl;

	return 0;
}
