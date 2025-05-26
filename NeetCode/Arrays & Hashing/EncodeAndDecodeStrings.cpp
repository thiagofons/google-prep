#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
  string encode(vector<string>& strs) {
    if (strs.empty()) return "";

    vector<int> sizes;
    string res = "";

    // Get the size of each string in strs
    for (string s : strs) {
      sizes.push_back(s.size());
    }

    // Compound the res string adding the sizes and the separators
    for (int size : sizes) {
      res += to_string(size) + ',';
    }
    res += '#';

    // Adds the content of the string in the end of the new string
    for (string s : strs) {
      res += s;
    }

    return res;
  }

  vector<string> decode(string s) {
    if (s.empty()) return {};

    vector<int> sizes;
    vector<string> res;

    int i = 0;

    // Get all the string sizes
    while (s[i] != '#') {
      string cur = "";

      while (s[i] != ',') {
        cur += s[i];
        i++;
      }

      sizes.push_back(stoi(cur));
      i++;
    }

    // To the next character, after the '#'
    i++;

    // Iterate over the string getting the substrings
    for (int size: sizes) {
      res.push_back(s.substr(i, size));
      i += size;
    }

    return res;
  }
};

int main () {
  Solution s;

  vector<string> input = {"neet", "code", "love", "you"};

  string encoded = s.encode(input);
  
  vector<string> decoded = s.decode(encoded);

  for (string s : decoded)
    cout << s << " ";
  cout << endl;
  

  return 0;
}