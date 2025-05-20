#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n);

    for (int i = 0; i < n; i++) {
      int count = 1;
      int j = i + 1;

      while (j < n) {
        if (temperatures[j] > temperatures[i])
          break;

        j++;
        count++;
      }
      count = (j == n) ? 0 : count;
      res[i] = count;
    } 
    return res;
  }
};

int main() {
  Solution solution;
  vector<int> temperatures = {30,38,30,36,35,40,28};

  vector<int> result = solution.dailyTemperatures(temperatures);

  return 0;
}