#include <iostream>
#include <vector> 
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    map<int, int> frequency;

    // Count the frequency of each number
    for (int element : nums) {
      frequency[element]++;
    }

    // Add the frequencies to an array
    vector<pair<int, int>> arr;
    for (auto freq : frequency) {
      arr.push_back({freq.second, freq.first});
    }

    // Sort the array
    sort(arr.rbegin(), arr.rend());

    // Return the k most frequent numbers
    for (int i = 0; i < k; i++) {
      res.push_back(arr[i].second);
    }

    return res;
  } 
};

int main () {
  Solution s;

  vector<int> nums = {1, 2, 2, 3, 3, 3};
  int k = 2;

  vector<int> solution = s.topKFrequent(nums, k);

  for (int elem : solution) {
    cout << elem << " ";
  }
  
  cout << endl;

  return 0;
}
