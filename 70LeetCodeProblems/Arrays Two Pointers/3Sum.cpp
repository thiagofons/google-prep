#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
  public:
  vector<vector<int>> threeSum (vector<int>& nums) {
    int size = nums.size();

    // Triplets list
    vector<vector<int>> triplets;

    // Sort the nums array
    sort(nums.begin(), nums.end());

    // Iterate through the array checking the sum
    for (int i = 0; i < size; i++) {
      
      // Has already been evaluated
      if (i > 0 && nums[i] == nums[i - 1]) 
        continue;

      int left = i + 1;
      int right = size - 1;

      while (left < right) {
        int currentSum = nums[i] + nums[left] + nums[right];

        if (currentSum > 0) {
          right--;
        } else if (currentSum < 0) {
          left++;
        } else {
          triplets.push_back({nums[i], nums[left], nums[right]});

          left++;

          while (left < right && nums[left] == nums[left - 1])
            left++;
        }
      }
    }

    return triplets;
  }
};

int main () {
  Solution solution;

  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> res = solution.threeSum(nums);

  for (auto v : res) {
    for (int elem : v) {
      cout << elem << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}