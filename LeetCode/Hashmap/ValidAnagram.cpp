#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
		unordered_map<char, int> map;

		// Check the length of both strings
		if (s.size() != t.size()) 
			return false;

		// Iterate over s, adding 1 to hashmap
		for (char c : s) {
			map[c]++;
		}

		// Iterate over t, removing 1 and checking
		for (char c : t) {
			if (map[c] == 0) 
				return false;
			
			map[c]--;
		}

		// Check if the map is all 0
		for (auto it : map) {
			if (it.second != 0) 
				return false;
		}

		return true;
    }
};

int main() {
	string s = "rat";
	string t = "car";

	Solution solution;
	int isAnagram = solution.isAnagram(s, t);

	// Output the result
	cout << isAnagram << endl;

	return 0;
}