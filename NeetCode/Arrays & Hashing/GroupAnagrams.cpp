#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> res;

    for (string s : strs) {
      string sorted = s;

      sort(sorted.begin(), sorted.end());

      res[sorted].push_back(s);
    }

    vector<vector<string>> result;

    for (auto item : res) {
      result.push_back(item.second);
    }

    return result;
  }
};


int main () {
  Solution solution;
  vector<string> strs = {"act","pots","tops","cat","stop","hat"};

  vector<vector<string>> groups = solution.groupAnagrams(strs);

  for (const auto& group : groups) {
    for (const auto& word : group) {
      cout << word << " ";
    }
    cout << endl;
  }

  return 0;
}