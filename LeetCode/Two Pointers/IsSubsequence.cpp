#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

		// Check if they are equal
		if (!s.compare(t)) {
			return true;
		}

		// Iterate using two pointer to check if s is substring of t
        while (j < t.size()) {
			if (s[i] == t[j]) {
				i++;
			}

			j++;

			if (i == s.size()) {
				return true;
			}
        }
        return false;
    }
};

int main() {
	Solution solution;

  	string s = "";
  	string t = "";
	
	int isSubsequence = solution.isSubsequence(s, t);
	cout << isSubsequence << endl;

	return 0;
}