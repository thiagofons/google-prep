#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
   
  int findJudge(int n, vector<vector<int>>& trust) {
    // indegree[i] = number of arrows that comes into node i
    // n + 1, because it's indexed from 1
    vector<int> indegree(n + 1, 0);

    for (auto t : trust) {
      int p1 = t[0], p2 = t[1];

      indegree[p2]++;
      indegree[p1]--;
    }

    // Check who is the judge
    for (int i = 1; i <= n; i++) {
      if (indegree[i] == n - 1)
        return i;
    }

    // There's no judge
    return -1;
  }
};

int main () {
  Solution s;

  int n = 2;
  vector<vector<int>> trust = {{1, 3}, {2, 3}};

  int result = s.findJudge(n, trust);

  cout << result << endl;

  return 0;
}