#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
		// Convert the string to lowercase and remove non-alphanumeric characters
		string lowered;
		for (char c : s) {
			if (isalnum(c)) {
				lowered += tolower(c);
			}
		}
		s = lowered;

		cout << lowered << endl;

		// Check if it's a palindrome
		int i = 0, j = s.size() - 1;

		while (i < j) {
			if (s[i++] != s[j--]) {
				return false;
			}
		}

		return true;
    }
};


int main() {
	Solution solution;

	string phrase = "A man, a plan, a canal: Panama";
	
	int isPalindrome = solution.isPalindrome(phrase);
	cout << isPalindrome << endl;

	return 0;
}