#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
  /*
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> map;

    int i = 0, j = 0;
    while (j < s.size()) {
      char character = s[j];

      if (map.count(character) > 0) {
        i = map[character] + 1;

      } else {
        map[character] = j;
      }
      j++;
    }

    for (auto it : map) {
      cout << it.first << " ";
    }
    cout << endl;

    return map.size();
  }
  */
  int lengthOfLongestSubstring(string s) {
    int res = 0;

    for (int i = 0; i < s.size(); i++) {
      unordered_set<char> charSet;

      for (int j = i; j < s.size(); j++) {
        if (charSet.find(s[j]) != charSet.end()) {
          break;
        }
        charSet.insert(s[j]);
      }
      res = max(res, (int) charSet.size());
    }
    return res;
  }
};

int main () {
  Solution solution;

  string s = "pwwkew";

  cout << solution.lengthOfLongestSubstring(s) << endl;

  return 0;
}
