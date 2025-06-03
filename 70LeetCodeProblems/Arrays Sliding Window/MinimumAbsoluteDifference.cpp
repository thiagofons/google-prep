#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
  public:
  vector<vector<int>> minimumAbsDifference (vector<int>& arr) {
    int size = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    // Find the minimum difference
    int minimum = INT_MAX;
    for (int i = 1; i < size; i++) {
      int difference = abs(arr[i] - arr[i - 1]);
      if (difference < minimum)
        minimum = difference;
    }

    // Check what pairs correspond to the minimum difference
    vector<vector<int>> res;
    for (int i = 1; i < size; i++) {
      int difference = abs(arr[i] - arr[i - 1]);
      if (difference == minimum)
        res.push_back({arr[i - 1], arr[i]});
    }

    return res;
  }
};

int main () {
  Solution solution;

  vector<int> arr = {1, 3, 6, 10, 15};

  vector<vector<int>> res = solution.minimumAbsDifference(arr);

  for (auto v : res) {
    for (int elem : v) {
      cout << elem << " ";
    }
    cout << endl;
  }

  return 0;
}