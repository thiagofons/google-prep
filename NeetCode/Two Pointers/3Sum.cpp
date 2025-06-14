#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    // Get the size of nums
    int size = nums.size();

    // Create the triplets vector
    vector<vector<int>> triplets;

    // Sort the array
    sort(nums.begin(), nums.end());

    // Iterate over the array
    for (int cur = 0; cur < size; cur++) {
      if (cur > 0 && nums[cur] == nums[cur - 1]) 
        continue;

      int left = cur + 1, right = size - 1;      

      while (left < right) {
        int sum = nums[cur] + nums[left] + nums[right];

        if (sum > 0) {
          right--;
        } else if (sum < 0) {
          left++;
        } else {
          triplets.push_back({nums[cur], nums[left], nums[right]});

          left++;

          while (left < right && nums[left] == nums[left - 1]) {
            left++;
          }
        }
      }
    } 

    return triplets;
  }
};

int main () {
  Solution s;

  vector<int> nums = {-1, 0, 1, 2, -1, -4};

  vector<vector<int>> res = s.threeSum(nums);

  for (auto v : res) {
    for (int value: v) {
      cout << value << " ";
    }
    cout << endl;
  }

  return 0;
}