#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
  vector<int> smallerNumberThanCurrent(vector<int>& nums) {
    // Create a hashmap
    unordered_map<int, int> map;

    // Iterate through the sorted array
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
      if (map.find(nums[i]) == map.end()) {
        map[nums[i]] = i;
      }
    }

    // Create the return list
    vector<int> res;
    
    for (int value : nums) {
      res.push_back(map[value]);
    }

    return res;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {8, 1, 2, 2, 3};

  vector<int> res = solution.smallerNumberThanCurrent(nums);

  for (int num : res) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}