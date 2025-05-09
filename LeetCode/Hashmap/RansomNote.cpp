#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map;

		// Create the map from magazine
		for (char i : magazine) {
			map[i] += 1;
		}

		// Remove from the map the characters of ransomNote
		for (char i : ransomNote) {
			if (map[i] == 0) {
				return false;
			}

			map[i] -= 1;
		}

		return true;
    }
};

int main() {
	Solution solution;

  	string ransomNote = "aa";
  	string magazine = "ab";
	
  	bool canConstruct = solution.canConstruct(ransomNote, magazine);
	cout << canConstruct << endl;

	return 0;
}
