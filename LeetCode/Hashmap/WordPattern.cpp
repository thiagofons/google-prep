#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:

	vector<string> split_sentence(string sen) {
		// Create a stringstream object
		stringstream ss(sen);
		
		// Variable to hold each word
		string word;
		
		// Vector to store the words
		vector<string> words;
		
		// Extract words from the sentence
		while (ss >> word) {
			// Add the word to the vector
			words.push_back(word);
		}
		return words;
	}

    bool wordPattern(string pattern, string s) {
		vector<string> sentence = split_sentence(s);

		unordered_map<char, string> map;

		for (int i = 0; i < pattern.size(); i++) {
			char c = pattern[i];

			if (map.count(c) && map[c] != sentence[i])
				return false;

			if (map.count(c))

			map[c] = sentence[i];
		}
		return true;
    }
};

int main () {
	Solution solution;

	string pattern = "aaaa";
	string s = "dog cat cat dog";

	bool result = solution.wordPattern(pattern, s);

	cout << result << endl;

	return 0;
}