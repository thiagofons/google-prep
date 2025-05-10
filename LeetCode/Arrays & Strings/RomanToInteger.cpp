#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		unordered_map<char, int> map = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};

		unordered_map<char, char> previous = {
			{'V', 'I'},
			{'X', 'I'},
			{'L', 'X'},
			{'C', 'X'},
			{'D', 'C'},
			{'M', 'C'}
		};

		if (s.size() == 1) {
			return map[s[0]];
		}

		char previous, current, amount = 0;
		int total = 0;

		for (int i = s.size() - 1; i >= 0; i--) {
			// Get the current character
			current = s[i];
			
			// Check if it can be placed before the previous
			previous = current;
		}


    }
};

int main() {
	Solution solution;
	string s = "I";

	int romanToInt = solution.romanToInt(s);

	cout << romanToInt << endl;
	
	return 0;
}